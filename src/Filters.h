#ifndef DEF_FILTERS
#define DEF_FILTERS

#include <vector>
#include <iostream>
#include "Tensor.h"

class Filters
{
public: 
	Filters();
	Filters(int height, int width, int depth, int numberOfFilters);

	std::vector<Tensor> filters;

	Tensor getFilter(int index) ;
protected:
	int height;
	int width;
	int depth;
};

#endif
