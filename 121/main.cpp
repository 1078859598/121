#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	int cnt = 0;
	VideoCapture capVideo(0);

	while (1)
	{

		Mat frame;
		Mat grayMat;
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0)
		{
			frame.copyTo(bgMat);
		}
		else
		{
			absdiff(frame, bgMat, subMat);

			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b_subMat", bny_subMat);
			imshow("subMat", subMat);
			waitKey(30);
		}
		cnt++;
	}

}