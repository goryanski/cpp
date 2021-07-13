#include "Application.h"

Application::Application(FileManipulation* fileManipulation)
{
	this->fileManipulation = fileManipulation;
}

void Application::menu()
{
	cout << "Menu:\n";
	cout << "[1] Add country and cities\n";
	cout << "[2] Delete country and cities\n";
	cout << "[3] Change name of city\n";
	cout << "[4] Find cities by contry\n";
	cout << "[5] Get count of cities by country\n";
	cout << "[6] Print list of countries\n";
	cout << "[7] Print all world\n";
	cout << "[0] Exit\n";
	cout << "Your choice: ";
}

void Application::checkFile()
{
	// проверим, существует ли файл
	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst("World.txt", fileinfo);
	if (done == -1) {
		// если файл не существует - мы заходим в программу первый раз и запишем в файл страны по умолчанию
		// которые описаны в мэйне
		fileManipulation->writeToFile();
	}
	else {
		// файлы по умолчанию не записываем, а считываем существующий файл, (в котором по-любому есть страны)
		// таким образом программу можно использовать повторно, а все изменения остаются сохранены в файле
		fileManipulation->readFile();
	}
	//Очистка памяти
	_findclose(done);
	delete fileinfo;
}

void Application::start()
{
	checkFile();

	int action;
	while (true) {
		system("cls");
		menu();
		cin >> action;

		switch (action) {
		case ADD:			
			fileManipulation->addCountry();
			// после добавления перезапишем файл (так будем делать при всех изменениях)
			fileManipulation->writeToFile();
			break;
		case DELETE:
			fileManipulation->delCountry();		
			break;
		case CHANGE_CITY:	
			fileManipulation->changeCity();		
			break;
		case FIND_CITIES: {			
			// запишем в переменную только потому что ф-ция должна возвращать итератор для changeCity()
			auto result = fileManipulation->findCities();
			break;
		}
		case COUNT_CITIES:
			fileManipulation->getCountCities();
			break;
		case PRINT_COUNTRIES:
			fileManipulation->printCountries();
			break;
		case PRINT_ALL:
			fileManipulation->printAllWorld();
			break;
		case EXIT:
			exit(EXIT_SUCCESS);
			break;
		}
		system("pause");
	}
}
