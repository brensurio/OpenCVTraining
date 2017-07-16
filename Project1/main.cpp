#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

void salt(cv::Mat &image, int n) 
{
	for (int  k = 0; k < n; k++)
	{
		// rand() is the MFC random number generator
		// try qrand() with Qt
		int i = rand() % image.cols;
		int j = rand() % image.rows;

		if (image.channels() == 1)
		{
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3)
		{
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}

int main(int argc, char** argv)
{
	// Open the image
	cv::Mat img = cv::imread("boldt.jpg");

	// Call the function to add noise
	salt(img, 3000);

	// Display image
	cv::namedWindow("Image");
	cv::imshow("Image", img);
	cv::waitKey();

	return 0;
}