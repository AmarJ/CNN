#ifndef DEF_FILTERS
#define DEF_FILTERS

#include <vector>
#include <iostream>
#include "Tensor.h"

class Tensor;

class Filters
{
public: 
	Filters();
	Filters(int height, int width, int depth, int numberOfFilters);

	std::vector<Tensor> filters;

	int getDepth() const;
    int getHeight() const;
 	int getWidth() const;
	Tensor getFilter(int index);
	int getNumberOfFilters() const; 
protected:
	int height;
	int width;
	int depth;
};

#endif
