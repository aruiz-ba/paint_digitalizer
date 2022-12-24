#include "./includes/paint_cutter.h"

void error_message (string message)
{
		cout << endl
			<< message << endl
			<< "Press a key to terminate";
		cin.get();
}

int save_image(Mat image, string path, string name)
{
	string str = path + name;
	bool check = imwrite(path + name, image);
	
	if (check == false) {
		cout << "Saving the image, FAILED" << endl;
		cin.get();
		return -1;
	}
	return 0;
}

int create_mask_from_green_screen(Mat image)
{
	Mat hsv,mask;
	
	cvtColor(image,hsv,COLOR_BGR2HSV);
	inRange(hsv,Scalar(40,0,0),Scalar(80,255,255),mask);
	image.setTo(Scalar(0,0,0),mask);

	//Maybe you should adjust this threshold to work just with green
	//to make it more percise
	threshold(image, mask, 150, 255, THRESH_BINARY);
	return(save_image(mask, "./tmp/", "tmp_mask.jpg"));
}

int main(int argc, char **argv)
{
	Mat mask, original, cutted_image, image;

	if (argc != 2)
	{
		error_message("ERROR! Wrong number of arguments");
	}
	image = imread(argv[1]);
	if (image.empty())
	{
		error_message("ERROR! Unable to read the image");
		return 0;
	}
	if (create_mask_from_green_screen(image) == -1)
	{
		error_message("ERROR! Error saving mask");
		return 0;
	}

	mask = imread("tmp/tmp_mask.jpg");
	original = imread(argv[1]);
	cutted_image = cut_image(mask, original);

	save_image(cutted_image, "./results/", "test.jpg");

	return 0;
}
