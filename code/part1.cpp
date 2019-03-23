#include "stdafx.h"
#include<iostream>  
#include <opencv2\core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include "part1.h"

//for Mat
#define BLUE 0
#define GREEN 1
#define RED 2

//for histogram
#define red 0
#define green 1
#define min(a,b) ((a)<(b))?(a):(b)
using namespace cv;
using namespace std;

string part1(string filename)
{
	VideoCapture cap(filename); // open the video file for reading


	if (!cap.isOpened())
	{
		return "Can not open camera.\n";
	}

	int numFrames = (int)cap.get(CV_CAP_PROP_FRAME_COUNT);
	int frameH = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);		//#rows
	int frameW = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);		//#cols
	Size size(frameH, frameW);
	Mat result(frameW, numFrames, CV_8UC3, Scalar(0, 0, 0));//the result picture

															//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	int i = 0;
	int j;

	cout << numFrames << endl;
	getchar();
	for (i = 0; i < numFrames; i++)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			return "Cannot read the frame from video file";
		}
		frame = frame.t();//transpose the matrix
		int midcol = frame.rows / 2;
		//for (i = 0; i < frame.rows / 2;i++)
		for (j = 0; j < frameW; j++) {
			result.at<Vec3b>(j, i)[0] = frame.at<Vec3b>(j, midcol)[0];
			result.at<Vec3b>(j, i)[1] = frame.at<Vec3b>(j, midcol)[1];
			result.at<Vec3b>(j, i)[2] = frame.at<Vec3b>(j, midcol)[2];

		}
		cout << i << endl;
	}

	// create a window named "..."
	namedWindow("Result for Part 1");
	// display the result in the window
	imshow("Result for Part 1", result);
	// wait for 6000 ms and then close the window
	waitKey(0);
	return "";
}

string part2(string filename, int with_thr=1)
{
	VideoCapture cap(filename); // open the video file for reading


	if (!cap.isOpened())
	{
		return "Can not open camera.\n";
	}

	int numFrames = (int)cap.get(CV_CAP_PROP_FRAME_COUNT);
	int frameH = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);		//#rows
	int frameW = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);		//#cols
	Size size(frameH, frameW);
	Mat result(frameW, numFrames-1, CV_8UC1, Scalar(0, 0, 0));//the result picture

															//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	Mat frame;
	int n =(int) (1 + log2(frameH));
	//form: (n*i + j)*2 + color
	vector<double> hist(n*n), last_hist(n*n);
	int is_init = 1;
	int row_rate = 1 / n, col_rate = 1 / n;
	int row_index, col_index;
	int t = 0;
	double T;
	for (int j = 0; j < frameW; j++) {
		is_init = 1;
		t = 0;
		while(cap.read(frame)){
			/*
			namedWindow("Result");
			// display the result in the window
			imshow("Result", frame);
			waitKey(0);
			*/
			for (int i = 0; i < frame.rows; i++) {
				int sum = frame.at<Vec3b>(i, j)[RED] + frame.at<Vec3b>(i, j)[BLUE] + frame.at<Vec3b>(i, j)[GREEN];
				double r = 0 ,g = 0;
				if (sum) {
					r = 1.0*frame.at<Vec3b>(i, j)[RED] / sum;
					g = 1.0*frame.at<Vec3b>(i, j)[GREEN] / sum;
				}
				row_index = r *n;
				col_index = g *n;
				if (row_index >= n) {
					row_index = n-1;
				}
				if (col_index >= n) {
					col_index = n-1;
				}
				hist[row_index*n + col_index]++;
			}
			for (auto&cell : hist) {
				cell = cell / frameH;
			}
			if (!is_init) {
				T = 0;
				for (row_index = 0; row_index < n; row_index++) {
					for (col_index = 0; col_index < n; col_index++) {
						T += min(hist[row_index*n + col_index], last_hist[row_index*n + col_index]);
					}
				}
				if(with_thr)result.at<uchar>(j, t++) = (T>0.7)?255:0;
				else result.at<uchar>(j, t++) = T*256;
			}
			else {
				is_init = 0;
			}
			last_hist = hist;
			for (auto& cell : hist) {
				cell = 0;
			}
		}
		cap.set(CV_CAP_PROP_POS_FRAMES, 0);

	}
	// create a window named "..."
	namedWindow("Result for Part 2");
	// display the result in the window
	imshow("Result for Part 2", result);
	// wait for 6000 ms and then close the window
	waitKey(0);
	return "";
}