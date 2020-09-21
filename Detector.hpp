
class Detector
{
private:

	Mat _img;
	vector<Point> _Points;

public:

	void set_img(Mat img);
	vector<Point> detect();
	void print();
};
