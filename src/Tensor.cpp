#include <vector>
#include <ctime>
#include <stdexcept>
#include "Tensor.h"
#include <cmath>

using namespace std;

Tensor::Tensor(){}

Tensor::Tensor(int height, int width)
{
	this->height = height;
	this->width = width;
	this->depth = 0;
	this->layers = vector<Matrix> (depth);
}

Tensor::Tensor(int height, int width, int depth)
{
	this->height = height;
	this->width = width;
	this->depth = depth;
	this->layers = vector<Matrix> (depth);
}

Tensor::Tensor(vector<Matrix> const &layers)
{
	this->height = layers[0].getHeight();
	this->width = layers[0].getWidth();
	this->depth = layers.size();
	this->layers = layers;
}

int Tensor::getHeight() const
{   
    return height;
}       
        
int Tensor::getWidth() const
{           
    return width;
}

int Tensor::getDepth() const
{
	return depth;
}

void Tensor::addLayer(Matrix layer)
{
	layers.push_back(layer);
	depth++;
}

Matrix Tensor::getLayer(int index) const
{
	return layers[index];
}

void Tensor::init_random_values(int low, int high)
{
	cout << "AMAR_depth: " << depth << endl;
    srand(time(0));
    for (int i=0; i<depth; i++){
		vector<vector<double>> layer;
		for (int y=0; y<height; y++){
	        vector<double> rows;
			for (int x=0; x<width; x++){
			    double temp = low + (rand() % (high - low + 1));
                rows.push_back(temp);
			}
			layer.push_back(rows);
		}
		//Matrix temp = Matrix(layer);
		//temp.print();
		layers[i] = layer;
	}
}

Matrix Tensor::convolution(Tensor filter, int stride, int bias)
{
	int F = filter.getWidth();
	float f_W = (float)width;
	float f_F = (float)F;
	float f_S = (float)stride;
	int output_size = ceil((f_W-f_F)/f_S)+1;

	
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
