#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Matrix.h"
#include "Tensor.h"
#include <jpeglib.h>

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

    Tensor conv_layer_1 = Tensor(7, 7);
    conv_layer_1.addLayer(createMatrixFromFile("layers/1_input_layer_7X7"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/2_input_layer_7X7"));
    conv_layer_1.addLayer(createMatrixFromFile("layers/3_input_layer_7X7"));

    Tensor kernel_1 = Tensor(3, 3, 3);
    kernel_1.init_random_values(-1, 1);

    Matrix activation_map = conv_layer_1.convolution(kernel_1, 2, 1);

    cout << "done." << endl;

    return 0;
}	
