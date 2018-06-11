#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include "Utility.h"
#include "Matrix.h"

namespace Utility
{
	void printVec(std::vector<std::vector<double> > matrix) {
		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < matrix[i].size(); j++){
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

    //used for tests to create a matrix out of a file for first layer of CNN
    Matrix createMatrixFromFile(std::string filename, int padding)
    {
        std::vector<std::vector<double> > matrix;
        std::ifstream inputFile(filename);
        std::string temp;

        while (std::getline(inputFile, temp)) {
            std::istringstream buffer(temp);

            std::vector<double> line{std::istream_iterator<double>(buffer), std::istream_iterator<double>()};

            matrix.push_back(line);
        }

        return Matrix(matrix, padding);
    }
}
			
