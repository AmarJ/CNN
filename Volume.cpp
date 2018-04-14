#include <vector>
#include "Volume.h"

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

void Volume::init_random_values()
{
	for (int i=0; i<depth; i++){
		for (int y=0; y<height; y++){
			for (int x=0; x<width; x++){
				layers[i].setIndexValue(y, x, (rand() % 1 - 1));
			}
		}
	}
}

Matrix Volume::convolution(Volume filter, int stride, int bias)
{
	int F = filter.getWidth();
	int output_size = (((width-F)/stride)+1);
	
	if (output_size < 1)
        throw logic_error("Invalid: Output matrix size 0.");	

	//temporarily doing addition of blank matrix in first iteration -- will fix later
	Matrix result = Matrix(output_size, output_size);
	for (int i=0; i<depth; i++){
		result.add(layers[i].filter_slide(filter.getLayer(i), stride, bias));
	}

	if (bias > 0) {
		vector<vector<double>> bias_filter(output_size, vector<double>(output_size, bias));
		result.add(bias_filter);
	}
	return result;
}
