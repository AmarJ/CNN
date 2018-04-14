#include <stdlib.h>
#include <time.h>
#include "Filter.h"
#include "Volume.h"

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
	for (int i=0; i<depth; i++){
		for (int y=0; y<height; y++){
			for (int x=0; x<width; x++){
				layers[i].setIndexValue(y, x, (rand() % 1 - 1));  
			}
		}
	}	
}

