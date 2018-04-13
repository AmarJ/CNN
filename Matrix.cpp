#include "Matrix.h"
#include <sstream>
#include <stdexcept>

using namespace std;

Matrix::Matrix(){}

Matrix::Matrix(int height, int width)
{
	this->height = height;
	this->width = width;
	this->array = vector<vector<double>> (height, vector<double>(width));
}

Matrix::Matrix(vector<vector<double>> const &array)
{
	this->height = array.size();
	this->width = array[0].size();
	this->array = array;
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
	return array[i][j];
}

void Matrix::checkIfEqual(Matrix &other) const
{
	if (height != other.getHeight())
		throw logic_error("Heights of matrices are not the same.");
	if (width != other.getWidth())
		throw logic_error("Width of matrices are not the same.");
}

int Matrix::dotProduct(Matrix &other) const
{

	checkIfEqual(other);

	int product = 0;

	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			product += (array[i][j] * other.getIndexValue(i, j));
		}
	}

	return product;
}

void Matrix::add(Matrix &other)
{
	checkIfEqual(other);

	vector<vector<double>> result; 

	for (int i=0; i<height; i++){
		vector<double> row_result;
		for (int j=0; j<width; j++){
			row_result.push_back( array[i][j] + other.getIndexValue(i, j));
		}
		result.push_back(row_result);
	}

	array = result;
}

void Matrix::print() const
{
	for (int i = 0; i < height; i++){
    	for (int j = 0; j < width; j++){
        	cout << array[i][j] << ' ';
    	}
		cout << endl;
	}
}

