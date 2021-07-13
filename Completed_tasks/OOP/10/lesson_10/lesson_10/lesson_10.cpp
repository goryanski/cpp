#include <iostream>
#include "Directory.h"
using std::cout;

//params:
//copy.exe path1 path2
//move.exe path1 path2
//delete.exe path
int main(int argc, char* argv[])
{
	char action[100];
	char pathStart[100];
	char pathEnd[100];
	if (argc > 1) {
		strcpy_s(action, argv[1]);
		if (strcmp(action, "copy.exe") == 0) {			
			strcpy_s(pathStart, argv[2]);			
			strcpy_s(pathEnd, argv[3]);
			Directory::copyDirectory(pathStart, pathEnd, true);
		}

		else if (strcmp(action, "move.exe") == 0) { 
			strcpy_s(pathStart, argv[2]);
			strcpy_s(pathEnd, argv[3]);
			Directory::moveDirectory(pathStart, pathEnd, true);
		}

		else if (strcmp(action, "delete.exe") == 0) {
			strcpy_s(pathStart, argv[2]);
			Directory::removeDirectory(pathStart, true);
		}
	}
	else {
		cout << "There're no params\n";
	}
	return 0;
}