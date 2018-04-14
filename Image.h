#include <fstream>

using namespace std;
typedef unsigned char unchar;

class MImage {

public:
    MImage(const char* fileName);
    ~MImage();
    void write(const char* fileName);
    void smoothFilter();
private:
    ifstream* pInFile;
    ofstream* pOutFile;
    unchar imageHeaderData[1078]; //.bmp header data with offset 1078.
    unchar** imageData;
    unchar m_smoothFilter[3][3]; // Smoothing Filter.
    unchar**  filteredData;
};