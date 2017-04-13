#pragma once

#include <vector>

using namespace std;

class FileOperation
{
public:
	static void GetAllFormatFiles(string& path, vector<basic_string<char>>& files, string& format);
	static string getFilename(string f_path);
	static int GetDirNumber(string fileNamePath);
};
