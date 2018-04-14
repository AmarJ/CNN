#ifndef DEF_VOLUME
#define DEF_VOLUME

#include <vector>
#include <iostream>
#include "Matrix.h"

class Tensor
{
public:
	Tensor();
	Tensor(int height, int width);
	Tensor(int height, int width, int depth);
	Tensor(std::vector<Matrix> const &layers);

	//vector storing matrices (3D volume of matrices)
	std::vector<Matrix> layers;

	virtual int getDepth() const;
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual void addLayer(Matrix layer);
	void init_random_values(int low, int high);
	virtual Matrix getLayer(int index) const;
	virtual Matrix convolution(Tensor filter, int stride, int bias);
protected:
	int height;
	int width;
	int depth;
};

#endif
