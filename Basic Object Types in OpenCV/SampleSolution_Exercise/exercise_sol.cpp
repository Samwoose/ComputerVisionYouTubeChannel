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

	Mat robotImg = imread(robotPath);
	Mat robotImgWithRotatedRect = robotImg.clone();
	
	Scalar rotatedRectColor(0, 255, 0);//Green
	Scalar rectColor(0, 0, 255); //Red
	int thickness = 3;
	int rectHeight = 80;
	int rectWidth = 120;
	
	Point_<int> center = Point_<int>(125, 225);
	Size rotatedRectSize(rectHeight, rectWidth);
	float angle = 135;//135 degree
	RotatedRect wantedRotatedRect(center, rotatedRectSize, angle);

	const int numOfVertices = 4;
	Point2f vertices[numOfVertices];
	wantedRotatedRect.points(vertices); //get vertices of the rotated rectangle
	//draw the rotated rectagle with drawing line function
	for (int i = 0; i < numOfVertices; i++) {
		Point_<float> currentVertix1 = Point_<float>(vertices[i]);
		Point_<float> currentVertix2 = Point_<float>(vertices[(i + 1) % 4]);//need 2 vertix to draw a line
		line(robotImgWithRotatedRect, currentVertix1, currentVertix2, rotatedRectColor, thickness);
	}

	//get bounding box
	Rect boundingBox = wantedRotatedRect.boundingRect();
	rectangle(robotImgWithRotatedRect, boundingBox, rectColor, thickness);

	imshow("robot image with a rotated rect", robotImgWithRotatedRect);
	waitKey(0);


	return 0;
}