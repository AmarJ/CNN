#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <vector>
#include <iostream>

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
	void checkIfEqual(Matrix &other) const;
	void add(Matrix other);
	void print() const;
	Matrix kernel_slide(Matrix filter, int stride, int bias);
private:
	int height;
	int width;
};

#endif 
