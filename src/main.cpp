#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <time.h>
#include "Matrix.h"
#include "Tensor.h"
#include "Filters.h"
#include "Utility.h"

using namespace std;

//Testing convolution on 7x7x3 Tensor with 16 filters: 3x3x3 and stride 2
void test_7x7_Conv() {

    // 7x7x3 input layer
    Tensor conv_layer_1 = Tensor(7, 7);
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/1_input_layer_7X7", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/2_input_layer_7X7", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/3_input_layer_7X7", 0));

    // 3x3x3 x 48 filters
    Filters kernel_1 = Filters(3, 3, 3, 16);

    cout << "______test_7x7_Conv Test Start_______________________\n" << endl;
    cout << "---- Test [Fwd Convolution] ----" << endl;

    Tensor conv_layer_2 = conv_layer_1.fwdConv(kernel_1, 2, 0);
    cout << "\n[Input volume]: 7x7x3 --> Convolution (filter: 3x3x3 * 16 @ stride=2) --> [Output volume]: "
         << conv_layer_2.getHeight() << "x"
         << conv_layer_2.getWidth() << "x"
         << conv_layer_2.getDepth() << endl;

    // printing first layer of output volume to see if it actually convolved input layer
    cout << "---- [Input matrix layer 0] ----" << endl;
    conv_layer_1.getLayer(0).print();
    cout << "###### FILTER 0  #####" << endl;
    kernel_1.getFilter(0).getLayer(0).print();
    cout << "######################" << endl;
    conv_layer_2.getLayer(0).print();
    cout << "Output volume ->  " << conv_layer_2.getHeight() << "x" << conv_layer_2.getWidth() << "x" << conv_layer_2.getDepth() << endl;

    cout << "\n___________________Test End_________________________\n" << endl;
}

//Testing max pool on 3x3x16 Tensor with stride 2
void test_7x7_MaxPool() {

    // 7x7x3 input layer
    Tensor conv_layer_1 = Tensor(7, 7);
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/1_input_layer_7X7", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/2_input_layer_7X7", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/3_input_layer_7X7", 0));

    // 3x3x3 x 48 filters
    Filters kernel_1 = Filters(3, 3, 3, 16);

    cout << "______test_7x7_MaxPool Test Start____________\n" << endl;

    Tensor conv_layer_2 = conv_layer_1.fwdConv(kernel_1, 2, 0);
    cout << "\n---- Test [Max Pool] ----" << endl;
    cout << "\n[Input matrix]" << endl;
    conv_layer_2.getLayer(0).print();

    Tensor max_pool_layer_1 = conv_layer_2.fwdMaxPool(2, 2, 1, 0);
    cout << "----Max pool operation (downsampling)----" << endl;
    max_pool_layer_1.getLayer(0).print();

    cout << "Output volume ->  " << max_pool_layer_1.getHeight() << "x" << max_pool_layer_1.getWidth() << "x" << max_pool_layer_1.getDepth() << endl;
    cout << "\n___________________Test End_________________________\n" << endl;
}

void test_7x7_Conv_MaxPool() {

	// 7x7x3 input layer
	Tensor conv_layer_1 = Tensor(7, 7);
	conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/1_input_layer_7X7", 0));
	conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/2_input_layer_7X7", 0));
	conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/3_input_layer_7X7", 0));

	// 3x3x3 x 48 filters
	Filters kernel_1 = Filters(3, 3, 3, 16);

    cout << "______test_7x7_Conv_MaxPool Test Start________________\n" << endl;
	cout << "---- Test [Fwd Convolution] ----" << endl;
    Tensor conv_layer_2 = conv_layer_1.fwdConv(kernel_1, 2, 0);
    cout << "\n[Input volume]: 7x7x3 --> Convolution (filter: 3x3x3 * 16 @ stride=2) --> [Output volume]: "
         << conv_layer_2.getHeight() << "x"
         << conv_layer_2.getWidth() << "x"
         << conv_layer_2.getDepth() << endl;
    cout << "\n---- [Test Max Pool] ----" << endl;
    Tensor max_pool_layer_1 = conv_layer_2.fwdMaxPool(2, 2, 1, 0);
    cout << "\n[Input volume]: 3x3x3 --> Max pool (max pool filter: 2x2x16 * 16 @ stride=1) --> [Output volume]: "
         << max_pool_layer_1.getHeight() << "x"
         << max_pool_layer_1.getWidth() << "x"
         << max_pool_layer_1.getDepth() << endl;
    cout << "\n___________________Test End_________________________\n" << endl;
}

void test_227x227_Conv_MaxPool() {

    // 227x227x3 input layer -> 3 channels RGB from an image (for now I just made up values to test)
    Tensor conv_layer_1 = Tensor(227, 227);
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/input_layer_227X227", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/input_layer_227X227", 0));
    conv_layer_1.addLayer(Utility::createMatrixFromFile("layers/input_layer_227X227", 0));

    // 11x11x3 x 48 filters
    Filters kernel_1 = Filters(11, 11, 3, 16);

    cout << "______test_227x227_Conv_MaxPool Test Start____________\n" << endl;
    cout << "---- Test [Fwd Convolution] ----" << endl;
    Tensor conv_layer_2 = conv_layer_1.fwdConv(kernel_1, 4, 0);
    cout << "\n[Input volume]: 227x227x3 --> Convolution (filter: 11x11x16 * 16 @ stride=2) --> [Output volume]: "
         << conv_layer_2.getHeight() << "x"
         << conv_layer_2.getWidth() << "x"
         << conv_layer_2.getDepth() << endl;
    cout << "\n---- [Test Max Pool] ----" << endl;
    Tensor max_pool_layer_1 = conv_layer_2.fwdMaxPool(5, 5, 5, 0);
    cout << "\n[Input volume]: 55x55x48 --> Max pool (max pool filter: 5x5x16 * 16 @ stride=2) --> [Output volume]: "
         << max_pool_layer_1.getHeight() << "x"
         << max_pool_layer_1.getWidth() << "x"
         << max_pool_layer_1.getDepth() << endl;
    cout << "\n___________________Test End_________________________\n" << endl;
}

int main(int argc, char* argv[]) {
    srand(time(0)); //used for setting random values for filters
    test_7x7_Conv();
    test_7x7_MaxPool();
	test_7x7_Conv_MaxPool();
    test_227x227_Conv_MaxPool();
    return 0;
}	
