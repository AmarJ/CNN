#ifndef DEF_VOLUME
#define DEF_VOLUME

#include <vector>
#include <iostream>
#include "Matrix.h"

class Volume
{
public:
	Volume();
	Volume(std::vector<Matrix> const &layers);

	//vector storing matrices (3D volume of matrices)
	std::vector<Matrix> layers;
private:
	int height;
	int width;
	int depth;
};

#endif
