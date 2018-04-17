#include <iostream>
#include "Utility.h"

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
}
			
