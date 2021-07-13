#include <iostream>
#include "Stack.h"

using std::cout;


int main() {
	Stack stack(2);
	stack.push((char*)"Natasha");
	stack.push((char*)"Olya");
	stack.push((char*)"Tanya");

	stack.showStack();
	
	stack.showExtracted();

	// получение элемента без выталкивания
	cout << "\n\nOne of the strings: ";
	stack.getElement(2).showStr();

	cout << "\n\nCount of strings: " << stack.getTop() + 1 << "\n";
	
	return 0;
}