#include "Volume.h"
#include "Matrix.h"

class Filter: public Volume
{
public:
	Filter();
	Filter(int height, int width, int depth);
private:
	void init_random_values();
};
