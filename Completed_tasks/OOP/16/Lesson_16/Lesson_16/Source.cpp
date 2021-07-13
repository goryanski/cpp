#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;

int main() {
	vector<int> nums;

	cout << "Enter num: ";
	int num;
	cin >> num;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(num*num);
		cout << nums[i] << "\t";
	}

	return 0;
}