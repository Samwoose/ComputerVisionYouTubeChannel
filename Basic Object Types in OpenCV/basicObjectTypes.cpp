#include <string>
#include <iostream>
using namespace std;

#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\opencv.hpp"
using namespace cv;

int main(int argc, char **argv) {
	
	string robotPath = argv[1];
	//1.Mat Class

	//Method1
	//Declare Mat object called firstMatrix
	int sizeOfRow = 4;
	int sizeOfColumn = 4;

	Mat firstMatrix(sizeOfRow, sizeOfColumn, CV_8UC1);

	//Method2
	Mat secondMatrix; 
	//It can be used whenever we need a Mat object. 

	//Useful Mat class member variables
	int rowSize = firstMatrix.rows;// size of row is 4 as we define earlier
	int colSize = firstMatrix.cols;// size of column is 4 as we define earlier

	
	//2.Vec Class
	//declare Vec object
	Vec<int, 2> firstVec = { 1,2 };
	//Get individual component
	int component1 = firstVec[0];
	int component2 = firstVec[1];
	



	//3.Vec3b Class
	//it turns out Vec3b is predefined vec types
	//e.g. typedef Vec<uchar,3> Vec3b; => it means type Vec3b is defined by Vec<uchar,3>
	//declare Vec object
	Vec3b firstVec3b = { 1, 2, 3 }; //compoents 1,2,and 3 will be unsigned char type. 
	//Get individual component
	uchar firstComponent = firstVec3b[0];
	uchar secondComponent = firstVec3b[1];
	uchar thirdComponent = firstVec3b[2];
	
	//Usage of Vec3b with Mat. It can be used when you want to get value at certain pixel
	Mat robotImg = imread(robotPath);
	int tempRow = 0; //first row
	int tempCol = 0; //first column
	int tempChannel = 0; //first channel
	uchar valueAtCertainPixel = robotImg.at<cv::Vec3b>(tempRow, tempCol)[tempChannel];
	

	//4.Scalar Class
	Scalar firstScalar(5);
	Scalar secondScalar(5, 5, 5);
	//Mat thirdMatrix = Mat::ones(2, 2, CV_32F); //2x2 matrix with 3 channel.

	Mat thirdMatrix(2, 2, CV_32F,firstScalar); //2x2 matrix with 1 channel.
	Mat fourthMatrix(2, 2, CV_32FC3, secondScalar); //2x2 matrix with 3 channel.

	cout << thirdMatrix << endl;
	cout << fourthMatrix << endl;
	

	//5.Point Class
	Point_<int> firstPoint;
	firstPoint.x = 5;
	firstPoint.y = 3;

	//or
	Point_<float> secondPoint = Point_<float>(5, 3);

	//6. Size Class
	int matObjWidth = 10;
	int matObjHeight = 10;
	Size matObjSize(matObjHeight, matObjWidth); 
	Mat fifthMatrix(matObjSize, CV_32F); //Define 10x10 matrix with 1 channel using a Size object
	//Equivalent to Mat fifthMatrix(matObjHeight, matObjWidth, CV_32F);


	//7. Rect Class
	int upperLeftPoint1 = 0;
	int upperLeftPoint2 = 0;
	int rectWidth = 100;
	int rectHeight = 100;
	Rect wantedRectShape(upperLeftPoint1, upperLeftPoint2, rectHeight, rectWidth);

	Mat robotImgWithRect = robotImg.clone();//Clone the robot image
	Scalar rectColor(0, 255, 0);//Green
	int thickness = 3;
	rectangle(robotImgWithRect, wantedRectShape, rectColor, thickness); //drawing rectangle function 
	imshow("robot image", robotImg);
	
	imshow("robot image with a rectangle on it", robotImgWithRect);
	

	//8. RotatedRect Class
	Mat robotImgWithRotatedRect = robotImg.clone();
	Point_<int> center = Point_<int>(200, 200);
	Size rotatedRectSize(rectHeight, rectWidth);
	float angle = 45;//45 degree
	RotatedRect wantedRotatedRect(center, rotatedRectSize, angle);
	
	const int numOfVertices = 4;
	Point2f vertices[numOfVertices];
	wantedRotatedRect.points(vertices); //get vertices of the rotated rectangle
	//draw the rotated rectagle with drawing line function
	for (int i = 0; i < numOfVertices; i++){
		Point_<float> currentVertix1 = Point_<float>(vertices[i]);
		Point_<float> currentVertix2 = Point_<float>(vertices[(i + 1) % 4]);//need 2 vertix to draw a line
		line(robotImgWithRotatedRect, currentVertix1, currentVertix2, rectColor, thickness);
	}
	
	imshow("robot image with a rotated rect", robotImgWithRotatedRect);
	waitKey(0);


	return 0;
}