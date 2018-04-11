#include "Matrix.h"
#include <sstream>

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

int Matrix::multiply(Matrix &other) const
{
	if (height != other.getHeight())
		throw "Heights of matrices are not the same.";
	if (width != other.getWidth())
		throw "Width of matrices are not the same.";

	int sum = 0;

	for (int i=0; i<height; i++){
		for (int j=0; j<width; j++){
			sum += (array[i][j] * other.getIndexValue(i, j));
		}
	}

	return sum;
}
