#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Utility.h"

class Matrix
{
public:
	Matrix();
	Matrix(int height, int width);
	Matrix(std::vector<std::vector<double>> const &array);	
	
	//2D vector stores matrix
	std::vector<std::vector<double>> matrix;

	//functions
	int getIndexValue(int i, int j) const;
	int getHeight() const;
	int getWidth() const;
	int dotProduct(Matrix &other) const;
	int getMax() const;
	void checkIfEqual(Matrix &other) const;
	void add(Matrix other);
	void print() const;
	Matrix filter_slide(Matrix filter, int stride, int bias);
	Matrix max_pool(int H, int F, int stride, int bias);
private:
	int height;
	int width;
};

#endif 
