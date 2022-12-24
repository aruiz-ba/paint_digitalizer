#include <opencv2/opencv.hpp>
#include <cstdio>

using namespace cv;
using namespace std;

Mat			cut_image(Mat mask, Mat image);

class cut_coordx { 
  public: 
	  int x;
};

class ci_object { 
  public: 
	int		x;
	int		y;
	int		lenght;
	int		height;

	uchar	blue;
	uchar	green;
	uchar	red;
	Vec3b	intensity;
	Mat		img;

	void copy_pixel() {  // Method/function defined inside the class
		intensity = img.at<Vec3b>(y, x);
		blue = intensity.val[0];
		green = intensity.val[1];
		red = intensity.val[2];
    }
};
