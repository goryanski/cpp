#include "Worker.h"

Worker::Worker(int motivation, char* positon)
{
	this->motivation = motivation;
	strcpy_s(this->positon, positon);
}

void Worker::print()
{
	cout << "Motivation (from 1 to 10): " << motivation << "\n";
	cout << "Positon: " << positon << "\n";
}
