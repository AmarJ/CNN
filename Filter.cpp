#include "Filter.h"

using namespace std;

Filter::Filter(){}

Filter::Filter(int height, int width, int depth)
{
	this->height = height;
	this->width = width;
	this->depth = depth;
	this->layers = vector<Matrix> (depth);
	init_random_values();
}

void Filter::init_random_values()
{
