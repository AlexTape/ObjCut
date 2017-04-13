#pragma once

#include <opencv2/core/core.hpp>

#include "FileOperation.h"


using namespace std;
using namespace cv;

class mouseCut
{
public:
	static void CallBackFunc(int event, int x, int y, int flags, void* objRect);
	static void cutAndSave(string inputPath);
	static void save(string filename, char option, Mat croppedObj);
};
