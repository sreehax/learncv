#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#define CV_HAAR_FIND_BIGGEST_OBJECT 4
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0);
	CascadeClassifier face;
	if(!cap.isOpened()) {
		cerr << "error opening camera" << endl;
		exit(1);
	}
	if(!face.load("cascade.xml")) {
		cerr << "Couldn't load face cascade" << endl;
		exit(1);
	}
	Mat frame, gray;
	vector<Rect> faces;
	while(1) {
		cap >> frame;
		if(frame.empty()) {
			break;
		}
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		face.detectMultiScale(gray, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT, Size(30, 30), Size(200, 200));
		for (int i = 0; i < faces.size(); i++) {
			Rect r = faces[i];
			rectangle(frame, r, Scalar(0, 255, 0));
		}
		imshow("Frame", frame);
		char c = (char)waitKey(25);
		if(c == 27) {
			break;
		}
	}
	cap.release();
	destroyAllWindows();
	return 0;
}
