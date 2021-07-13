#pragma once
#include "Bus.h"

struct Leaf {
	Bus bus;
	Leaf* parent;
	Leaf* left;
	Leaf* right;
	Leaf(Bus bus);
};

