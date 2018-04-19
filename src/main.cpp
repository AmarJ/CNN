#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <jpeglib.h> /*** http://libjpeg.sourceforge.net/ ***/
#include "Matrix.h"
#include "Tensor.h"

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

    Tensor conv_layer_1 = Tensor(227, 227);
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/input_layer_227X227"));
	
    Tensor kernel_1 = Tensor(11, 11, 3);
    kernel_1.init_random_values(-1, 1);
 
  	Matrix activation_map = conv_layer_1.convolution(kernel_1, 4, 1);
	activation_map.print();
    cout << activation_map.getHeight() << " " << activation_map.getWidth() << " done." << endl;
    return 0;
}	
