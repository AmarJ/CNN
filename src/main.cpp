#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <jpeglib.h> /*** http://libjpeg.sourceforge.net/ ***/
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

Matrix createMatrixFromImage(string filename)
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

	// 227x227x3 input layer -> 3 channels RGB from an image (for now I just made up values to test)
    Tensor conv_layer_1 = Tensor(227, 227);
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
	
	// 11x11x3 x 48 filters	
    Filters kernel_1 = Filters(11, 11, 3, 48);
 
	//  227x227x3 (intput layer) <--> 11x11x3 (filter) => 55x55x48 (output volume) 
  	Tensor conv_layer_2 = conv_layer_1.convolution(kernel_1, 4, 1);
	
	// printing first layer of output volume to see if it actually convolved input layer
	conv_layer_2.getLayer(0).print();    
	cout << conv_layer_2.getHeight() << " " << conv_layer_2.getWidth() << " done." << endl;
    
	return 0;
}	
