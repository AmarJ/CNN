#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
//#include <jpeglib.h> /*** http://libjpeg.sourceforge.net/ ***/
#include "Matrix.h"
#include "Tensor.h"
#include "Filters.h"

using namespace std;

Matrix createMatrixFromFile(string filename)
{
	vector<vector<double> > matrix;
	ifstream inputFile(filename);
	string temp;
	
	while (getline(inputFile, temp)) {
		istringstream buffer(temp);
		
		vector<double> line{istream_iterator<double>(buffer), istream_iterator<double>()};
		
		matrix.push_back(line);
	}

	return Matrix(matrix);	
}

int main(int argc, char* argv[]) {

	//Testing convolution
	cout << "------------------------------------Testing convolution-------------------------------------" << endl;

	// 227x227x3 input layer -> 3 channels RGB from an image (for now I just made up values to test)
    //Tensor conv_layer_1 = Tensor(227, 227);
    //conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    //conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    //conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));

	// 7x7x3 input layer
	Tensor conv_layer_1 = Tensor(7, 7);
	conv_layer_1.addLayer(createMatrixFromFile("layers/1_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/2_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/3_input_layer_7X7"));

	// 11x11x3 x 48 filters	
    //Filters kernel_1 = Filters(11, 11, 3, 48);

	// 3x3x3 x 48 filters
	Filters kernel_1 = Filters(3, 3, 3, 48);

	// 227x227x3 (intput layer) <--> 11x11x3 (filter) => 55x55x48 (output volume)
  	//Tensor conv_layer_2 = conv_layer_1.convolution(kernel_1, 4, 1);

	//  227x227x3 (intput layer) <--> 11x11x3 (filter) => 55x55x48 (output volume)
	Tensor conv_layer_2 = conv_layer_1.convolution(kernel_1, 2, 0);

	// printing first layer of output volume to see if it actually convolved input layer
	conv_layer_2.getLayer(0).print();    
	cout << "Output volume ->  " << conv_layer_2.getHeight() << "x" << conv_layer_2.getWidth() << "x" << conv_layer_2.getDepth() << endl;

	//Testing max pool
	cout << "------------------------------------Testing max pool-------------------------------------" << endl;
    Tensor max_pool_layer_1 = conv_layer_2.maxPool(2, 2, 1, 0);

    // printing first layer of output volume to see if it actually performed proper max pool operation
    max_pool_layer_1.getLayer(0).print();
    cout << "Output volume ->  " << max_pool_layer_1.getHeight() << "x" << max_pool_layer_1.getWidth() << "x" << max_pool_layer_1.getDepth() << endl;

    return 0;
}	
