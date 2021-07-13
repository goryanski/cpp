#pragma once
#include <iostream>
#include <direct.h>
#include <io.h>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

class Directory {
public:
	static void show(const char* path, bool isRecursive = false);
	static void  copyDirectory(char* pathStart, char* pathEnd, bool isRecursive);
	static void  moveDirectory(char* pathStart, char* pathEnd, bool isRecursive);
	static void  removeDirectory(char* pathDel, bool isRecursive);
	static void moveMenu();
	static void delMenu();
	static void copyFile(const char* source, const char* destination);
};
