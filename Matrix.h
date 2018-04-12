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
	std::vector<std::vector<double>> array;
	int getIndexValue(int i, int j) const;
	int getHeight() const;
	int getWidth() const;
	int multiply(Matrix &other) const;
private:
	int height;
	int width;
};

#endif 
