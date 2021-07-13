#include<iostream>
#include "Array.h"
using std::cout;
using std::cin;

int main() {
	int size = 5;
	Array arr(size);
	arr.fillArr();
	arr.printArr();

	cout << "\n Add to end: \n";
	arr.addEnd(777);
	arr.printArr();

	cout << "\n Delete from end: \n";
	arr.delEnd();
	arr.printArr();

	cout << "\n Sorted array: \n";
	arr.sortArr();
	arr.printArr();

	cout << "\n";
	arr.min_max();

	cout << "\n New array: \n";
	Array arr2 = arr;
	arr2.printArr();

	system("pause");
	return 0;
}