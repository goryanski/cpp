#pragma once
#include "Leaf.h"
#include <fstream>
using std::ofstream;
using std::ios;

class Tree {
	static Tree* instance;
	Leaf* root;
	Tree();
public:	
	static Tree* getInstance();
	~Tree();
	void add(Bus bus);
	Leaf* next(char* str);
	Leaf* min(Leaf* node);
	Leaf* max();
	Leaf* search(Leaf* node, char* str);
	Leaf* getRoot() const;
	void print(Leaf* node);
	void writeBus(Leaf* node);
	void clear(Leaf* node);
	void delOneLeaf(Leaf* node);
	// для delOneLeaf
	bool nodeIsLeft(Leaf* node);
	void delNodeWithChild(Leaf* node);
};
