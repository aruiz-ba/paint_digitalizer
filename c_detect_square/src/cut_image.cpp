#include "../includes/paint_cutter.h"

int top_cut(ci_object ci)
{
	ci.x = 0;
	ci.y = 0;
	while (ci.y < ci.height) 
	{
		ci.copy_pixel();
		while (ci.x < ci.lenght) 
		{
			ci.copy_pixel();
			if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
			{
				break;
			}
			ci.x++;
		}
		if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
		{
			break;
		}
		ci.x = 0;
		ci.y++;
	}
	return (ci.y);
}

int bottom_cut(ci_object ci)
{
	ci.x = ci.lenght - 1;
	ci.y = ci.height - 1;
	while (ci.y > 0) 
	{
		ci.copy_pixel();
		while (ci.x > 0) 
		{
			ci.copy_pixel();
			if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
			{
				break;
			}
			ci.x--;
		}
		if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
		{
			break;
		}
		ci.x = ci.lenght - 1;
		ci.y--;
	}
	return (ci.y);
}

int left_cut(ci_object ci)
{
	ci.x = 0;
	ci.y = 0;
	while (ci.x < ci.lenght) 
	{
		ci.copy_pixel();
		while (ci.y < ci.height) 
		{
			ci.copy_pixel();
			if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
			{
				break;
			}
			ci.y++;
		}
		if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
		{
			break;
		}
		ci.y = 0;
		ci.x++;
	}
	return (ci.x);
}

int right_cut(ci_object ci)
{
	ci.x = ci.lenght - 1;
	ci.y = ci.height - 1;
	while (ci.x > 0) 
	{
		ci.copy_pixel();
		while (ci.y > 0) 
		{
			ci.copy_pixel();
			if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
			{
				break;
			}
			ci.y--;
		}
		if(ci.blue != 0 && ci.green != 0 && ci.red != 0)
		{
			break;
		}
		ci.y = ci.height - 1;
		ci.x--;
	}
	return (ci.x);
}

Mat		cut_image(Mat mask, Mat image)
{
	ci_object ci;

	ci.img = mask;
	ci.lenght = mask.cols;
	ci.height = mask.rows;

	int y_top = top_cut(ci);
	int y_bottom = bottom_cut(ci);
	int x_right = right_cut(ci);
	int x_left = left_cut(ci);

	//printf("Cols and rows: %i %i\n", mask.cols, mask.rows);
	//printf("%i %i %i %i", y_top, y_bottom, x_right, x_left);

 	return(image(Range(y_top, y_bottom), Range(x_left,x_right)));
}
