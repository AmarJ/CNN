#include "Filters.h"

using namespace std;

Filters::Filters(){}

Filters::Filters(int height, int width, int depth, int numberOfFilters)
{
	this->height = height;
	this->width = width;
	this->depth = depth;
	this->filters = vector<Tensor> (numberOfFilters);
}

Tensor Filters::getFilter(int index)
{	

	return filters[index];
}
