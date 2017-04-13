// ObjCut.cpp :small program for cut the resonable Object.
// Cutting with mouse leftbutton and to press button 1....9 for choosing the destination of the Objs, which you want to save. And pressing the ENTER button to change to the next image.

#include "stdafx.h"
#include "mouseCut.h"

int main(int argc, _TCHAR* argv)
{
	static string img_path = "ObjImages";
	mouseCut::cutAndSave(img_path);
	return 0;
}
