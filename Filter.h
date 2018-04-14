#include "Volume.h"
#include "Matrix.h"


class Filter: public Volume
{
public:
	Filter();
	Filter(int height, int width, int depth);
	int getHeight();
	int getWidth();
	Matrix getLayer(int index) const;
private:
	void init_random_values();
};
