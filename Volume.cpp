#include <vector>
#include "Volume.h"

using namespace std;

Volume::Volume(){}

Volume::Volume(vector<Matrix> const &layers)
{
	this->height = layers[0].getHeight();
	this->width = layers[0].getWidth();
	this->depth = layers.size();
	this->layers = layers;
}
