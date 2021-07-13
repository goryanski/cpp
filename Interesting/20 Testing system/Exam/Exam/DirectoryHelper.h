#pragma once
#include <iostream>
#include <direct.h>
#include <io.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "Utils.h"
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::for_each;
using std::cin;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;

class DirectoryHelper
{
public:
	// метод будет возвращать имена файлов и папок из дирректории, путь к которой передадим в 
	// параметрах
	static vector<string> readDirectory(string);
	static bool showFolderContents(string);
	static void copyFiles();
	static void copyFile(const char*, const char*);
	static void copyDirectory(char*, char*, bool);
	static void createDirectory(string);
	static void removeDirectory(char*, bool);
};

