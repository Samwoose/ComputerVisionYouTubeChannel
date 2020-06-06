//Standard libraries. Useful when you need to get path for files and print out messages
#include <iostream>
#include <string>
using namespace std;

//OpenCV libraries
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"
using namespace cv;

int main(int argc, const char** argv) {

	VideoCapture captureObj;

	captureObj.open(0);

	if (!captureObj.isOpened()) {
		cout << "Error no camera stream" << endl;
		return -1;
	}

	//while(true)
	for (;;) {
		Mat frame;
		captureObj >> frame;

		imshow("Camera Stream", frame);


		if (waitKey(30) >= 0) {
			break;
		}
	}

	captureObj.release();

	return 0;

}