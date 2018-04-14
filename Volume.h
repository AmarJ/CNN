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

	virtual int getDepth() const;
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual void addLayer(Matrix layer);
	void init_random_values();
	virtual Matrix getLayer(int index) const;
	virtual Matrix convolution(Volume filter, int stride, int bias);
protected:
	int height;
	int width;
	int depth;
};

#endif
