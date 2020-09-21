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
