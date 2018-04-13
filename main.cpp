#include <iostream>
#include <vector>
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

int main(int argc, char* argv[])
{
	Volume conv_layer_1 = Volume(7, 7);
	conv_layer_1.addLayer(createMatrixFromFile("layers/1_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/2_input_layer_7X7"));
	conv_layer_1.addLayer(createMatrixFromFile("layers/3_input_layer_7X7"));

	Volume filter_1 = Volume(3, 3);
	filter_1.addLayer(createMatrixFromFile("layers/W0/1_filter_3X3"));
	filter_1.addLayer(createMatrixFromFile("layers/W0/2_filter_3X3"));
	filter_1.addLayer(createMatrixFromFile("layers/W0/3_filter_3X3"));

	Matrix OUTPUT = conv_layer_1.convolution(filter_1, 2, 1); 
	OUTPUT.print();
	cout << "done" << endl;
	return 0;
}	
