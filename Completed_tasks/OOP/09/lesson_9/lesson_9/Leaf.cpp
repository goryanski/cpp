#include "Leaf.h"

Leaf::Leaf(Bus bus)
{
	this->bus = bus;
	parent = left = right = nullptr;
}