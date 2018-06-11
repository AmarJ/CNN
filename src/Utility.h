#ifndef DEF_UTILITY
#define DEF_UTILITY

#include <vector>
#include "Matrix.h"

class Matrix;

namespace Utility
{
	void printVec(std::vector<std::vector<double> > matrix);

    Matrix createMatrixFromFile(std::string filename, int padding);
}

#endif
