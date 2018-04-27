#include "Matrix.h"
#include "Utility.h"
#include <cmath>

using namespace std;

Matrix::Matrix(){}

Matrix::Matrix(int height, int width)
{
	this->height = height;
	this->width = width;
	this->matrix = vector<vector<double>> (height, vector<double>(width));
}

Matrix::Matrix(vector<vector<double>> const &matrix)
{
	this->height = matrix.size();
	this->width = matrix[0].size();
	this->matrix = matrix;
}

int Matrix::getHeight() const
{
	return height;
}

int Matrix::getWidth() const
{
	return width;
}

int Matrix::getIndexValue(int i, int j) const
{
	return matrix[i][j];
}

void Matrix::checkIfEqual(Matrix &other) const
{
	if (height != other.getHeight()){
		cout << height << endl;
		cout << other.getHeight() << endl;
		throw logic_error("Heights of matrices are not the same.");
	}
	
	if (width != other.getWidth()){
		cout << width << endl;
		cout << other.getWidth() << endl;
		throw logic_error("Width of matrices are not the same.");
	}
}

int Matrix::dotProduct(Matrix &other) const
{
	checkIfEqual(other);

	int product = 0;

	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			product += (matrix[i][j] * other.getIndexValue(i, j));
		}
	}

	return product;
}

int Matrix::getMax() const
{	
	int max = 0;

	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}

	return max;
}

void Matrix::add(Matrix other)
{
	checkIfEqual(other);

	vector<vector<double>> result; 

	for (int i=0; i<height; i++){
		vector<double> row_result;
		for (int j=0; j<width; j++){
			row_result.push_back( matrix[i][j] + other.getIndexValue(i, j));
		}
		result.push_back(row_result);
	}

	matrix = result;
}

Matrix Matrix::filterSlide(Matrix filter, int stride, int bias)
{
	int F = filter.getWidth();
	float f_W = (float)width;
	float f_F = (float)F;
	float f_S = (float)stride;
	int output_size = ceil((f_W-f_F)/f_S)+1;

	//checking if output Matrix will have size greater than 1
	if (output_size < 1)
		throw logic_error("Invalid: Output matrix size 0.");
	
	vector<vector<double>> output_layer;

	//goes through matrix and performs dot product on small local regions 
	for (int i=0; i<=height-F; i+=stride){
		vector<double> row_output_layer;
		for (int j=0; j<=width-F; j+=stride){

			vector<vector<double>> local_region;
			//disgusting I know... creates a local region
			for (int y=i; y<(i+F); y++){
				vector<double> row_local_region;
				for (int x=j; x<(j+F); x++){
					//gets row of local region
					row_local_region.push_back(matrix[y][x]); 	
				}
				//adds row of local region to local_region matrix
				local_region.push_back(row_local_region);
			}
			//adds dot product of local region and filter to row of output  
			row_output_layer.push_back( Matrix(local_region).dotProduct(filter) );
		}
		//adds row of output to output matrix
		output_layer.push_back(row_output_layer);
	}
	Matrix output = Matrix(output_layer);
	return output;
}

Matrix Matrix::maxSlide(int H, int F, int stride, int bias)
{
	//for now H isn't use since the filters are always squares... keeping it here for now... if I want to do rectangular stuff
	
	float f_W = (float)width;
	float f_F = (float)F;
	float f_S = (float)stride;
	int output_size = ceil((f_W-f_F)/f_S)+1;

	//checking if output Matrix will have size greater than 1
	if (output_size < 1)
		throw logic_error("Invalid: Output matrix size 0.");
	
	vector<vector<double>> output_layer;

	//goes through matrix and performs max pool on small local regions 
	for (int i=0; i<=height-F; i+=stride){
		vector<double> row_output_layer;
		for (int j=0; j<=width-F; j+=stride){

			vector<vector<double>> local_region;
			//creates a local region
			for (int y=i; y<(i+F); y++){
				vector<double> row_local_region;
				for (int x=j; x<(j+F); x++){
					//gets row of local region
					row_local_region.push_back(matrix[y][x]); 	
				}
				//adds row of local region to local_region matrix
				local_region.push_back(row_local_region);
			}
			//max pool on local region  
			row_output_layer.push_back(Matrix(local_region).getMax());
		}
		//adds row of output to output matrix
		output_layer.push_back(row_output_layer);
	}
	Matrix output = Matrix(output_layer);
	return output;
}

void Matrix::print() const
{
	Utility::printVec(matrix);
}
