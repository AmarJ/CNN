#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include "Matrix.h"
#include "Volume.h"

using namespace std;

Matrix createMatrixFromFile(string filename)
{
	vector<vector<double> > array;
	ifstream inputFile(filename);
	string temp;
	
	while (getline(inputFile, temp)) {
		istringstream buffer(temp);
		
		vector<double> line{istream_iterator<double>(buffer), istream_iterator<double>()};
		
		array.push_back(line);
	}

	return Matrix(array);	
}	

//convolution performed on matrix with given filter
Matrix convolution(Matrix conv_layer, Matrix filter, int stride, int bias)
{
	int W = conv_layer.getWidth();
	int F = filter.getWidth();
	int output_size = (((W-F)/stride)+1);
	
	//checking if output Matrix will have size greater than 1
	if (output_size < 1)
		throw logic_error("Invalid: Output matrix size 0.");
	
	vector<vector<double>> output_layer;

	//goes through matrix and performs dot product on small local regions 
	for (int i=0; i<conv_layer.getHeight() && i+stride<W; i+=stride){
		
		vector<double> row_output_layer;
		for (int j=0; j<conv_layer.getWidth() && j+stride<W; j+=stride){

			vector<vector<double>> local_region;
			//disgusting I know... creates a local region
			for (int y=i; y<i+F; y++){
				vector<double> row_local_region;
				for (int x=j; x<j+F; x++){
					row_local_region.push_back(conv_layer.getIndexValue(y, x));
				}
				local_region.push_back(row_local_region);
			}
			row_output_layer.push_back( Matrix(local_region).dotProduct(filter) );
		}	
		output_layer.push_back(row_output_layer);
	}
	Matrix output = Matrix(output_layer);
	
	return output;
}

//convolution performed on volume of matrices with volume of filters
Matrix convolution(Volume conv_layer, Volume filter, int stride, int bias)
{
	int W = conv_layer.getWidth();
	int F = filter.getWidth();
	int output_size = (((W-F)/stride)+1);
	
	if (output_size < 1)
        throw logic_error("Invalid: Output matrix size 0.");	

	//temporarily adding blank matrix to first layer -- will fix later
	Matrix result = Matrix(output_size, output_size);
	for (int i=0; i<conv_layer.getDepth(); i++){
		result.add( *convolution(conv_layer.getLayer(i), filter.getLayer(i), stride, bias) );
	}
}

int main(int argc, char* argv[])
{
	Volume conv_layer_1 = Volume(7, 7);
	conv_layer_1.addLayer(createMatrixFromFile("layers/1_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/2_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/3_input_layer_7X7"));

	Volume filter_1 = Volume(3, 3);
	filter_1.addLayer(createMatrixFromFile("layers/1_filter_3X3"));
	filter_1.addLayer(createMatrixFromFile("layers/2_filter_3X3"));
	filter_1.addLayer(createMatrixFromFile("layers/3_filter_3X3"));

	Matrix RESULT_1 = convolution(conv_layer_1, filter_1, 2, 0); 
	printVec(RESULT_1.array);

	return 0;
}	
