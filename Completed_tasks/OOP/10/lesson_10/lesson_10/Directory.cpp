#include "Directory.h"

void Directory::show(const char* path, bool isRecursive)
{
	char buff[1000];
	strcpy_s(buff, path);
	strcat_s(buff, "\\");
	strcat_s(buff, "*.*");

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(buff, info);
	do
	{
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
			if (info->attrib == _A_SUBDIR) {
				if (isRecursive) {
					strcpy_s(buff, path);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					show(buff, isRecursive);
				}
				cout << "DIR - " << info->name << "(" << info->attrib << ")" << endl;
			}
			else {
				cout << "FILE - " << info->name << "(" << info->attrib << ")" << endl;
			}
		}
	} while (_findnext(handle, info) == 0);

	_findclose(handle);
}

void Directory::copyDirectory(char* pathStart, char* pathEnd, bool isRecursive)
{
	char buff[1000];
	strcpy_s(buff, pathStart);
	strcat_s(buff, "\\");
	strcat_s(buff, "*.*");
	char buff2[1000];

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(buff, info);
	do {
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
			if (info->attrib & _A_SUBDIR) {
				if (isRecursive) {
					strcpy_s(buff, pathStart);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					strcpy_s(buff2, pathEnd);
					strcat_s(buff2, "\\");
					strcat_s(buff2, info->name);
					_mkdir(buff2);
					copyDirectory(buff, buff2, isRecursive);
				}
			}
			else if (info->attrib == 33) {
				moveMenu();
				int ch;
				cin >> ch;
				switch (ch) {
				case 1:
					strcpy_s(buff, pathStart);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					strcpy_s(buff2, pathEnd);
					strcat_s(buff2, "\\");
					strcat_s(buff2, info->name);
					copyFile(buff, buff2);
					break;
				case 2:
					// ничего не делаем
					break;
				case 3:
					exit(0);
					break;
				}
			}
			else {
				strcpy_s(buff, pathStart);
				strcat_s(buff, "\\");
				strcat_s(buff, info->name);
				strcpy_s(buff2, pathEnd);
				strcat_s(buff2, "\\");
				strcat_s(buff2, info->name);
				copyFile(buff, buff2);
			}
		}
	} while (_findnext(handle, info) == 0);
	_findclose(handle);
}

void Directory::moveDirectory(char* pathStart, char* pathEnd, bool isRecursive)

{
	char buff[1000];
	strcpy_s(buff, pathStart);
	strcat_s(buff, "\\");
	strcat_s(buff, "*.*");
	char buff2[1000];

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(buff, info);
	do {
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
			if (info->attrib == _A_SUBDIR) {
				if (isRecursive) {
					strcpy_s(buff, pathStart);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					strcpy_s(buff2, pathEnd);
					strcat_s(buff2, "\\");
					strcat_s(buff2, info->name);
					moveDirectory(buff, pathEnd, isRecursive);
				}
				rename(buff, buff2);
			}
			else if (info->attrib == 33) {
				moveMenu();
				int ch;
				cin >> ch;
				switch (ch) {
				case 1:
					strcpy_s(buff, pathStart);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					strcpy_s(buff2, pathEnd);
					strcat_s(buff2, "\\");
					strcat_s(buff2, info->name);
					rename(buff, buff2);
					break;
				case 2:
					// ничего не делаем
					break;
				case 3:
					exit(0);
					break;
				}
			}
			else {
				strcpy_s(buff, pathStart);
				strcat_s(buff, "\\");
				strcat_s(buff, info->name);
				strcpy_s(buff2, pathEnd);
				strcat_s(buff2, "\\");
				strcat_s(buff2, info->name);
				rename(buff, buff2);
			}
		}
	} while (_findnext(handle, info) == 0);
	_findclose(handle);
}

void Directory::removeDirectory(char* pathDel, bool isRecursive)
{
	char buff[1000];
	strcpy_s(buff, pathDel);
	strcat_s(buff, "\\");
	strcat_s(buff, "*.*");

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(buff, info);
	do {
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
			if (info->attrib & _A_SUBDIR) {
				if (isRecursive) {
					strcpy_s(buff, pathDel);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					removeDirectory(buff, isRecursive);
				}
				remove(buff);
				_rmdir(buff);
			}
			else if (info->attrib == 33) {
				delMenu();
				int ch;
				cin >> ch;
				switch (ch) {
				case 1:
					strcpy_s(buff, pathDel);
					strcat_s(buff, "\\");
					strcat_s(buff, info->name);
					remove(buff);
					break;
				case 2:
					// ничего не делаем
					break;
				case 3:
					exit(0);
					break;
				}
			}
			else {
				strcpy_s(buff, pathDel);
				strcat_s(buff, "\\");
				strcat_s(buff, info->name);
				remove(buff);
			}
		}
	} while (_findnext(handle, info) == 0);
	_findclose(handle);
}

void Directory::moveMenu()
{
	cout << "[1] - move\n";
	cout << "[2] - skip\n";
	cout << "[3] - cancel\n";
	cout << "Choice: ";
}

void Directory::delMenu()
{
	cout << "[1] - remove\n";
	cout << "[2] - skip\n";
	cout << "[3] - cancel\n";
	cout << "Choice: ";
}

void Directory::copyFile(const char* source, const char* destination)
{
	ifstream src(source, ios::in | ios::binary);
	ofstream dest(destination, ios::out | ios::binary);
	dest << src.rdbuf();
	src.close();
	dest.close();
}
