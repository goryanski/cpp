#include "Application.h"

Application::Application(AutoShop* autoShop)
{
	this->autoShop = autoShop;
}

void Application::menu()
{
	cout << "\nChoice option:\n";

	cout << "[1] find By Brand\n";
	cout << "[2] find By Model\n";
	cout << "[3] find By Color\n";
	cout << "[4] find By Price\n";
	cout << "[5] find By Year\n";
	cout << "[6] find By Country\n";
	cout << "[7] find Cheapest Car\n";
	cout << "[8] find Most Expensive Car\n\n";

	cout << "[9] print By Color\n";
	cout << "[10] print By Year\n";
	cout << "[11] print By Country\n";
	cout << "[12] print By Price\n\n";

	cout << "[0] Exit\n";
	cout << "Your choice: ";
}

void Application::start()
{
	int action;
	int year;
	double price;
	string str;
	while (true) {
		system("cls");
		menu();
		cin >> action;

		switch (action)
		case FIND_BY_BRAND: {
			cout << "Enter brand: ";
			cin >> str;
			autoShop->findByBrand(str);		
			break;
		case FIND_BY_MODEL:
			cout << "Enter model: ";
			cin >> str;
			autoShop->findByModel(str);
			break;
		case FIND_BY_COLOR:
			cout << "Enter color: ";
			cin >> str;
			autoShop->findByColor(str);
			break;
		case FIND_BY_PRICE:
			cout << "Enter price: ";
			cin >> price;
			autoShop->findByPrice(price);
			break;
		case FIND_BY_YEAR:
			cout << "Enter year: ";
			cin >> year;
			autoShop->findByYear(year);
			break;
		case FIND_BY_COUNTRY:
			cout << "Enter country: ";
			cin >> str;
			autoShop->findByCountry(str);
			break;
		case FIND_CHEAPEST:
			autoShop->findCheapestCar();
			break;
		case FIND_EXPENSIVE:
			autoShop->findMostExpensiveCar();
			break;
		case PRINT_BY_COLOR:
			cout << "Enter color: ";
			cin >> str;
			autoShop->printByColor(str);
			break;
		case PRINT_BY_YEAR:
			cout << "Enter year: ";
			cin >> year;
			autoShop->printByYear(year);
			break;
		case PRINT_BY_COUNTRY:
			cout << "Enter country: ";
			cin >> str;
			autoShop->printByCountry(str);
			break;
		case PRINT_BY_PRICE:
			cout << "Enter price: ";
			cin >> price;
			autoShop->printByPrice(price);
			break;
		case EXIT:
			exit(EXIT_SUCCESS);
			break;			
		}
		system("pause");
	}
}


