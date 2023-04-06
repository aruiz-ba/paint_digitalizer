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

// My old version but with the color range better adjusted to green screen
//int create_mask_from_green_screen(Mat image)
//{
//	Mat hsv,mask;
//	
//	cvtColor(image,hsv,COLOR_BGR2HSV);
//	inRange(hsv,Scalar(50,0,0),Scalar(70,255,255),mask);
//	image.setTo(Scalar(0,0,0),mask);
//
//	//Maybe you should adjust this threshold to work just with green
//	//to make it more percise
//	threshold(image, mask, 150, 255, THRESH_BINARY);
//	return(save_image(image, "./tmp/", "tmp_mask.jpg"));
//}
//

//Using morphological operations to fill small gaps
int create_mask_from_green_screen(Mat image)
{
    Mat hsv, mask;
    
    // Convert to HSV color space
    cvtColor(image, hsv, COLOR_BGR2HSV);
    
    // Create binary mask using green hue range
    inRange(hsv, Scalar(50, 0, 0), Scalar(70, 255, 255), mask);
    
    // Use morphological operations to fill gaps and holes
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    erode(mask, mask, kernel);
    dilate(mask, mask, kernel);
    
    // Apply binary mask to original image
    image.setTo(Scalar(0, 0, 0), mask);
    
    // Apply threshold to refine mask
    double threshold_value = 200;
    threshold(image, mask, threshold_value, 255, THRESH_BINARY);
    
    // Save mask to file and return status
    return save_image(mask, "/var/www/html/cut_image/tmp/", "tmp_mask.jpg");
}


//int create_mask_from_green_screen(Mat image)
//{
//    // Convert image to YCrCb color space
//    Mat ycrcb;
//    cvtColor(image, ycrcb, COLOR_BGR2YCrCb);
//
//    // Create mask based on Cr and Cb channels
//    Mat mask;
//    inRange(ycrcb, Scalar(0, 133, 77), Scalar(255, 173, 127), mask);
//
//    // Set masked pixels to black
//    image.setTo(Scalar(0, 0, 0), mask);
//
//    // Save masked image
//    return save_image(image, "./tmp/", "tmp_mask.jpg");
//}

////Using grabcut method
//int create_mask_from_green_screen(Mat image)
//{
//    Mat mask, bgModel, fgModel;
//    
//    // Specify initial foreground and background seeds
//    Rect rect(50, 50, image.cols-100, image.rows-100);
//    Mat bgdModel = Mat::zeros(1, 65, CV_64F);
//    Mat fgdModel = Mat::zeros(1, 65, CV_64F);
//    
//    // Run GrabCut algorithm
//    grabCut(image, mask, rect, bgdModel, fgdModel, 5, GC_INIT_WITH_RECT);
//    
//    // Convert mask to binary
//    mask = (mask == GC_PR_FGD) | (mask == GC_FGD);
//    mask.convertTo(mask, CV_8UC1, 255);
//    
//    // Save mask to file and return status
//    return save_image(mask, "./tmp/", "tmp_mask.jpg");
//}


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

	mask = imread("/var/www/html/cut_image/tmp/tmp_mask.jpg");
	original = imread(argv[1]);
	cutted_image = cut_image(mask, original);

	save_image(cutted_image, "/var/www/html/cut_image/", "latest.jpg");

	return 0;
}
