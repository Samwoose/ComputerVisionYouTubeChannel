#include <iostream>
#include <string>
using namespace std;

#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
using namespace cv;

int main(int argc, const char **argv) {

	//-Matrix Initialization
	//1.Initialization with zero matrix
	int rowSize1 = 3;
	int colSize1 = 3;
	Size matrixSize1(rowSize1, colSize1);
	
	int rowSize2 = 3;
	int colSize2 = 2;
	Size matrixSize2(colSize2, rowSize2); //be careful with order of parameter

	Mat term1 = Mat::eye(matrixSize1, CV_32FC1);
	Mat term2 = Mat::ones(matrixSize1, CV_32FC1)*2;
	Mat term3 = (Mat_<float>(matrixSize1) << 1, 1, 1, 0, 0, 0, 0, 0, 0);
	Mat term4 = Mat::ones(matrixSize2, CV_32FC1);
	

	Mat result = (term1 + term1 + term2 - term3) * term4 ;

	
	cout << "Calculation Result: " << endl;
	cout << result << endl;


	return 0;
}