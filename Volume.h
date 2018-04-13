#ifndef DEF_VOLUME
#define DEF_VOLUME

#include <vector>
#include <iostream>
#include "Matrix.h"

class Volume
{
public:
	Volume();
	Volume(int height, int width);
	Volume(std::vector<Matrix> const &layers);

	//vector storing matrices (3D volume of matrices)
	std::vector<Matrix> layers;

	int getDepth() const;
	int getHeight() const;
	int getWidth() const;
	void addLayer(Matrix layer);
	Matrix getLayer(int index) const;
	Matrix convolution(Volume filter, int stride, int bias);
private:
	int height;
	int width;
	int depth;
};

#endif
