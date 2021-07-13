#include <iostream>
#include <time.h>
#include "MyArray.h";
using std::cout;
using std::endl;

int main() {
	srand(time(0));
	// первый массив
	MyArray arr1(3);
	++arr1;
	++arr1;
	++arr1;
	++arr1;
	++arr1;
	cout << " arr1:\n";
	arr1.print();

	cout << "\n arr1 --\n";
	--arr1;
	arr1.print();

	cout << "\n\nCapacity: " << arr1.getCapacity() << endl;
	cout << "Size: " << arr1.getSize() << endl;

	// перегрузка []
	cout << "\n arr1[0]:\n";
	cout << arr1[0] << endl;

	// второй массив
	cout << "\n array2 \n";
	MyArray arr2(3);
	++arr2;
	++arr2;
	++arr2;
	arr2.print();

	// сумма
	cout << "\n\n arr1 + arr2: \n";
	MyArray sumArr;
	sumArr = arr1 + arr2;
	sumArr.print();

	// разница
	cout << "\n\n arr1 - arr2: \n";
	MyArray subArr;
	subArr = arr1 - arr2;
	subArr.print();

	return 0;
}