#include "President.h"

President::President(int countMoney, int countWorkers)
{
	this->countMoney = countMoney;
	this->countWorkers = countWorkers;
}

void President::print()
{
	cout << "Count money (all capital of company): " << countMoney << "\n";
	cout << "Count workers (all workers of company): " << countWorkers << "\n";
}
