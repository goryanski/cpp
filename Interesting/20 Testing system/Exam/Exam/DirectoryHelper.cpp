#include "DirectoryHelper.h"

vector<string> DirectoryHelper::readDirectory(string path)
{
	// это будет вектор с нашими данными 
	vector<string> data;

	path += "\\*.*";

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(path.c_str(), info);

	if (handle != -1) {
		do {
			if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0) {
				data.push_back(info->name);
			}
		} while (_findnext(handle, info) != -1);

		_findclose(handle);
		delete info;
	}

	return data;
}

bool DirectoryHelper::showFolderContents(string folderPath)
{
	vector<string> data = readDirectory(folderPath);
	int a = 0;
	if (!data.empty()) {
		int counter = 0;
		for_each(data.begin(), data.end(), [counter](string s) mutable {
			cout << "[" << ++counter << "] " << s << endl;
		});
		return true;
	}
	else {
		cout << "Storage is empty" << endl;
		return false;
	}
}

void DirectoryHelper::copyFiles()
{
	cout << "Enter full path to move applicatoin files" << endl;
	string path;
	cin.ignore(32767, '\n');
	getline(cin, path);

	// прежде чем копировать создадим две папки (для тестов и ответов) в том месте, куда нужно 
	// будет скопировать наши файлы. это нужно для удобства и поскольку файлы в тестах и ответах 
	// имеют одинаковые названия, при копировании файлы презатрутся
	string newTestsFolder = path + "//tests";
	
	// сразу проверим, если _mkdir не вернет 0, то папка не создалась - указан не правильный путь
	if (_mkdir(newTestsFolder.c_str())) {
		cout << "Incorrect path, try again" << endl;
	}
	else {
		string newAnswersFolder = path + "//answers";
		_mkdir(newAnswersFolder.c_str());

		// пути, куда копируем файлы
		char* destinationTests = const_cast<char*>(newTestsFolder.c_str()); 
		char* destinationAnswers = const_cast<char*>(newAnswersFolder.c_str());

		Utils* utils = Utils::getInstance();

		// пути, откуда копируем
		char* pathTests = const_cast<char*>(utils->TESTS_DIRECTORY_PATH.c_str()); 
		char* pathAnswers = const_cast<char*>(utils->ANSWERS_DIRECTORY_PATH.c_str());

		copyDirectory(pathTests, destinationTests, true);
		copyDirectory(pathAnswers, destinationAnswers, true);
		cout << "Success." << endl;
	}
	system("pause");
}

void DirectoryHelper::copyFile(const char* source, const char* destination)
{
	ifstream src(source, ios::in | ios::binary); // открыкаем файл, который будем копировать 
	ofstream dest(destination, ios::out | ios::binary); // куда копируем
	dest << src.rdbuf(); // ф-ция позволяет скпировать все содержимое файла

	src.close();
	dest.close();
}

void DirectoryHelper::copyDirectory(char* pathStart, char* pathEnd, bool isRecursive)
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

void DirectoryHelper::createDirectory(string path)
{
	string findPath = path + "\\*.*";

	_finddata_t* info = new _finddata_t;
	long handle = _findfirst(findPath.c_str(), info);
	delete info;

	//папка не найдена
	if (handle == -1) {
		_mkdir(path.c_str());
	}
	_findclose(handle);
}

void DirectoryHelper::removeDirectory(char* pathDel, bool isRecursive)
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