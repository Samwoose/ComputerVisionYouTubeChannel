#include <iostream>
#include <string>
using namespace std;

#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
using namespace cv;

int main(int argc, const char **argv) {

	//-Matrix Initialization
	//1.Initialization with zero matrix
	int rowSize = 3;
	int colSize = 3;
	Size matrixSize1(rowSize, colSize);
	Mat zeroMatrix = Mat::zeros(matrixSize1, CV_32FC1);//3x3 zero matrix with 1 channel. 

	cout << "Zero Matrix: " << endl;
	cout << zeroMatrix << endl;

	//2.Initialization with one matrix
	Mat oneMatrix = Mat::ones(matrixSize1, CV_32FC1);//3x3 one matrix with 1 channel.

	cout << "One Matrix: " << endl;
	cout << oneMatrix << endl;

	//3.Initialization with identity matrix
	Mat identityMatrix = Mat::eye(matrixSize1, CV_32FC1);//3x3 identity matrix with 1 channel.

	cout << "Identity Matrix: " << endl;
	cout << identityMatrix << endl;

	//4.Basic Matrix Operations
	//(1) Matrix addition
	Mat resultMat1 = identityMatrix + identityMatrix; 
	cout << "Matrix addition: " << endl;
	cout << resultMat1 << endl;
	
	//(2) Matrix subtraction
	Mat resultMat2 = identityMatrix - identityMatrix;
	cout << "Matrix subtraction: " << endl;
	cout << resultMat2 << endl;

	//(3) Element-wise matrix multiplication
	Mat resultMat3 = resultMat1.mul(resultMat1);
	cout << "Element-wise matrix multiplication: " << endl;
	cout << resultMat3 << endl;

	//(4) Matrix multiplication
	Mat tempMat1 = Mat::ones(4, 2, CV_32FC1);
	Mat tempMat2 = Mat::ones(2, 4, CV_32FC1);

	Mat resultMat4 = tempMat1*tempMat2;
	cout << "matrix1: " << endl;
	cout << tempMat1 << endl;

	cout << "matrix2: " << endl;
	cout << tempMat2 << endl;

	cout << "Matrix multiplication: " << endl;
	cout << resultMat4 << endl;

	return 0;
}