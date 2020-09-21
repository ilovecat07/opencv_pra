#include<Detector.hpp>
void Detector::set_img(Mat img)
{
	cvtColor(img, img, COLOR_BGR2HSV);
	Mat red_img, yel_img, blue_img;
	inRange(img, Scalar(100, 90, 90), Scalar(124, 255, 255), blue_img);
	inRange(img, Scalar(25, 90, 90), Scalar(40, 255, 255), yel_img);
	inRange(img, Scalar(-20, 90, 90), Scalar(20, 255, 255), red_img);
	bitwise_or(yel_img, red_img, _img);
	bitwise_or(_img, blue_img, _img);
	GaussianBlur(_img,_img,Size(3,3),0,0,4);
	threshold(_img,_img,100, 100, THRESH_BINARY);
	//Canny(img, img, 128, 255, 3);
}


vector<Point> Detector::detect()
{
	vector<vector<Point>> contours;
	findContours(_img, contours, noArray(), RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	vector<Moments> mu(contours.size());
	for (int i = 0;i < contours.size();i++)
	{
		mu[i] = moments(contours[i], true);
	}

	vector<Point2f> mc(contours.size());
	for (int i = 0;i < contours.size();i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
		_Points.push_back(mc[i]);
	}


	_img = Mat::zeros(_img.size(), CV_8UC1);
	for (int i = 0;i < contours.size();i++)
	{
		drawContours(_img, contours, i, Scalar::all(255), 2, 8, noArray(), 0, Point());
		circle(_img, mc[i], 4, Scalar::all(255), -1, 8, 0);
	}
	namedWindow("pic");
	imshow("pic", _img);
	waitKey(0);
	destroyWindow("pic");

	return _Points;
}

void Detector::print()
{
	cout << _Points << endl;
}
