#pragma once
#include <iostream>
using std::string;

class Utils
{
	static Utils* instance;
	Utils();
public:
	string USERS_STORAGE_PATH = "users.txt";
	string ADMIN_PATH = "admin.txt";

	string TESTS_DIRECTORY_PATH = "Tests";
	string ANSWERS_DIRECTORY_PATH = "Answers";

	string TEST_RESULTS = "testResults.txt";
	string SAVED_STATISTICS = "Saved statistics";
	
	static Utils* getInstance();
};


