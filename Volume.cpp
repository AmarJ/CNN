#include <vector>
#include "Volume.h"
#include "Matrix.h"

using namespace std;

Volume::Volume(){}

Volume::Volume(int height, int width)
{
	this->height = height;
	this->width = width;
	this->depth = 0;
	this->layers = vector<Matrix> (depth);
}

Volume::Volume(vector<Matrix> const &layers)
{
	this->height = layers[0].getHeight();
	this->width = layers[0].getWidth();
	this->depth = layers.size();
	this->layers = layers;
}

int Volume::getHeight() const
{   
    return height;
}       
        
int Volume::getWidth() const
{           
    return width;
}

int Volume::getDepth() const
{
	return depth;
}

void Volume::addLayer(Matrix layer)
{
	layers.push_back(layer);
	depth++;
}

Matrix Volume::getLayer(int index) const
{
	return layers[index];
}

