#include "Filters.h"
#include "Utility.h"

using namespace std;

Filters::Filters(){}

Filters::Filters(int height, int width, int depth, int numberOfFilters)
{
	this->height = height;
	this->width = width;
	this->depth = depth;
	this->filters = vector<Tensor> (numberOfFilters);

	//inits Filters with random digits
	for (int i=0; i<filters.size(); i++){
		filters[i] = Tensor(height, width, depth);
		filters[i].init_random_values(-1,1);
	}
}

int Filters::getNumberOfFilters() const
{
	return depth;
}

Tensor Filters::getFilter(int index)
{	
	return filters[index];
}

int Filters::getHeight() const
{
    return height;
}

int Filters::getWidth() const
{
    return width;
}

int Filters::getDepth() const
{
    return depth;
}
