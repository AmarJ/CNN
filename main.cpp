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

void printVec(vector<vector<double>> vec)
{
	//cout << "here\n" << endl; 
	for (int i = 0; i < vec.size(); i++){
    	for (int j = 0; j < vec[i].size(); j++){
        	cout << vec[i][j] << ' ';
    	}
		cout << endl;
	}
}	

Matrix convolution(Matrix conv_layer, Matrix filter, int stride, int bias)
{
	int W = conv_layer.getWidth();
	int F = filter.getWidth();
	int output_size = (((W-F)/stride)+1);
	
	printVec(conv_layer.array);

	//checking if output Matrix will have size greater than 1
	if (output_size < 1)
		throw logic_error("Invalid: Output matrix size 0.");
	
	vector<vector<double>> output_layer;

	//goes through matrix and performs dot product on small local regions 
	for (int i=0; i<conv_layer.getHeight(); i+=stride){
		
		vector<double> row_output_layer;
		for (int j=0; j<conv_layer.getWidth(); j+=stride){

			vector<vector<double>> local_region;
			cout << "-----------------------------------" << endl; 				
			//disgusting I know... creates a local region
			for (int y=i; y<i+F; y++){
				vector<double> row_local_region;
				for (int x=j; x<j+F; x++){
					row_local_region.push_back(conv_layer.getIndexValue(y, x));
				}
				local_region.push_back(row_local_region);
			}
			printVec(local_region);
			//int answ = Matrix(local_region).multiply(filter);
			//cout << answ << endl;
			row_output_layer.push_back( Matrix(local_region).multiply(filter) );
		}	
		output_layer.push_back(row_output_layer);
	}

	Matrix output = Matrix(output_layer);
	
	return output;
}

int main(int argc, char* argv[])
{
	Matrix X1 = createMatrixFromFile("layers/input_layer_7X7");
	Matrix F1 = createMatrixFromFile("layers/filter_3X3");

	Matrix RESULT = convolution(X1, F1, 2, 0);	

	return 0;
}	
