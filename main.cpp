#include<opencv2/opencv.hpp>
#include<iostream>
#include<Detector.hpp>

using namespace cv;
using namespace std;

int main()
{
	
	Detector _pic;
	Mat pic;	
	Point point;
	pic = imread("test.JPG");
	_pic.set_img(pic);
	_pic.detect();
	_pic.print();
	
	return 0;
}
