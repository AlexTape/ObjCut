#include "StdAfx.h"
#include "mouseCut.h"

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <io.h>

void mouseCut::CallBackFunc(int event, int x, int y, int flags, void* objRect)
{
	CvRect* roi = static_cast<CvRect*>(objRect);

	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		roi->x = x;
		roi->y = y;
	}
	else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON)
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_LBUTTONUP)
	{
		cout << "Left button of the mouse is leave- position (" << x << ", " << y << ")" << endl;
		roi->width = x - roi->x;
		roi->height = y - roi->y;
		if (roi->width == 0 || roi->height == 0)
		{
			cout << "Try Again with the right way!!!" << endl;
		}
	}
}

void mouseCut::cutAndSave(string inputPath)
{
	Mat img;
	Mat croppedObj;
	Rect objRect;
	vector<string> files;
	vector<string> filestif;
	string format = ".bmp";
	string formattif = ".tif";
	FileOperation::GetAllFormatFiles(inputPath, files, format);
	FileOperation::GetAllFormatFiles(inputPath, filestif, formattif);

	for (size_t j = 0; j < filestif.size(); j++)
	{
		files.push_back(filestif[j]);
	}
	cout << "Number" << files.size() << endl;
	int imageNumb = files.size();
	for (int i = 0; i < imageNumb; i++)
	{
		stringstream ss(stringstream::in | stringstream::out);
		ss << files[i];
		string filename = FileOperation::getFilename(ss.str());

		img = imread(ss.str());
		if (img.empty())
		{
			cout << "Error loading the image" << endl;
			break;;
		}

		try
		{
			namedWindow("My Window", 0);
			resizeWindow("My Window", 600, 800);
			setMouseCallback("My Window", CallBackFunc, static_cast<void*>(&objRect));
			imshow("My Window", img);
			char option;
			do
			{
				option = cvWaitKey(0);
				cout << option << endl;
				//stringstream ss_(stringstream::in | stringstream::out);
				croppedObj = img(objRect).clone();
				switch (option)
				{
				case '1':
					save(filename, option, croppedObj);
					break;
				case '2':
					save(filename, option, croppedObj);
					break;
				case '3':
					save(filename, option, croppedObj);
					break;
				case '4':
					save(filename, option, croppedObj);
					break;
				case '5':
					save(filename, option, croppedObj);
					break;
				case '6':
					save(filename, option, croppedObj);
					break;
				case '7':
					save(filename, option, croppedObj);
					break;
				case '8':
					save(filename, option, croppedObj);
					break;
				case '9':
					save(filename, option, croppedObj);
					break;
				default:
					break;
				}
			}
			while (option != 13);
		}
		catch (const exception)
		{
			cout << "Try Again with the right way!!!" << endl;
		}

		destroyAllWindows();
		croppedObj.release();
	}
}

void mouseCut::save(string filename, char option, Mat croppedObj)
{
	stringstream ss(stringstream::in | stringstream::out);
	string root_path = "CuttedObj\\" + string(1, option) + "\\" + filename + "_" + string(1, option);
	ss << root_path << ".jpg";
	if ((_access(ss.str().c_str(), 0)) != -1)
	{
		do
		{
			cout << ss.str() << endl;
			ss.clear();
			ss.str("");
			cout << ss.str() << endl;
			root_path = root_path + "_add";
			cout << root_path << endl;
			ss << root_path << ".jpg";
			cout << ss.str() << endl;
		}
		while ((_access(ss.str().c_str(), 0)) != -1);
	}
	cout << ss.str() << endl;
	imwrite(ss.str(), croppedObj);
}
