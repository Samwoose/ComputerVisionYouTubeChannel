#include <iostream>
#include <string>
using namespace std;

#include "opencv2\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
using namespace cv;

int main(int argc, const char** argv) {
	string robotPath = argv[1];
	string robotGrayPath = argv[2];

	cv::Mat robot = imread(robotPath);

	if (!robot.data) {
		cout << "error: no image" << endl;
		return -1;
	}

	imshow("robot image (color)", robot);

	Mat robotGray;
	cvtColor(robot, robotGray, COLOR_RGB2GRAY);

	imwrite(robotGrayPath, robotGray);

	waitKey(0);


}
