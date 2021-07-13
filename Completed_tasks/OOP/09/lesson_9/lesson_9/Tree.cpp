#include "Tree.h"

Tree* Tree::instance = nullptr;

Tree::Tree()
{
	root = nullptr;
}

Tree* Tree::getInstance()
{
	if (instance == nullptr) {
		instance = new Tree();
	}
	return instance;
}

Tree::~Tree()
{
	clear(root);
}

void Tree::add(Bus bus)
{
	Leaf* leaf = new Leaf(bus);

	//������ ������?
	if (root == nullptr) {
		root = leaf;
	}
	else {
		//����� ���� � �������� ����� �������� ����� ����
		Leaf* srchNode = next(leaf->bus.getNum());// �������� ������
		if (strcmp(srchNode->bus.getNum(), leaf->bus.getNum()) > 0) {
			srchNode->right = leaf;
		}
		else {
			srchNode->left = leaf;
		}
		leaf->parent = srchNode;
	}
}

Leaf* Tree::next(char* str)
{
	Leaf* tmp = root;
	Leaf* node = root;

	while (tmp != nullptr) {
		node = tmp;
		if (strcmp(tmp->bus.getNum(), str) > 0) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}
	return node;
}

Leaf* Tree::min(Leaf* node)
{
	//��������� ��� ������ ������
	Leaf* tmp = node;
	//��������� �� ��������� �������
	Leaf* leaf = node;

	while (tmp != nullptr) {
		leaf = tmp;
		tmp = tmp->left;
	}
	return leaf;
}

Leaf* Tree::max()
{
	Leaf* tmp = root;
	Leaf* leaf = root;
	while (tmp != nullptr) {
		leaf = tmp;
		tmp = tmp->right;
	}
	return leaf;
}

Leaf* Tree::search(Leaf* node, char* str)
{
	//��������� ��� ������ ������
	Leaf* tmp = node;

	while (tmp != nullptr) {
		if (strcmp(tmp->bus.getNum(), str) == 0) {
			return tmp;
		}
		if (strcmp(tmp->bus.getNum(), str) > 0) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}
	return nullptr;
}

Leaf* Tree::getRoot() const
{
	return root;
}

void Tree::print(Leaf* node)
{
	if (node != nullptr) {
		// ����� ����� � ������� �����������, ��� �� � ������� ��������, �� ������ left � right �������
		print(node->left);
		node->bus.showBus();
		print(node->right);
	}
}

void Tree::writeBus(Leaf* node)
{
	ofstream os("myFile.txt", ios::out | ios::binary | ios::app);
	if (!os.is_open()) {
		cout << "Error\n";
	}
	else {
		if (node != nullptr) {
			writeBus(node->left);
			os << node->bus << "\n";
			os.close();
			writeBus(node->right);			
		}
	}	
}

void Tree::clear(Leaf* node)
{
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		Leaf* parent = node->parent;

		//�������� ��������� ����
		if (node->parent == nullptr) {
			delete root;
			root = nullptr;
		}
		else {
			// ����� ��������� ������ ������, ����� ���� �� �������, ����� ��� ������
			// 1-� ������� ���������� ���������� �� ����� ���� ����. 2-� - � ���� ��� ����� ������ ��� ����� ����, ����� �� ��� ������� � ����������� ������ nullptr. � else �� �� ��� �������
			if (parent->left != nullptr &&
				strcmp(node->bus.getNum(), parent->left->bus.getNum()) == 0) {
				delete node;
				parent->left = nullptr;
			}
			else if (parent->right != nullptr &&
				strcmp(node->bus.getNum(), parent->right->bus.getNum()) == 0) {
				delete node;
				parent->right = nullptr;
			}
		}
	}
}

void Tree::delOneLeaf(Leaf* node) {
	if (node != nullptr) {
		// case 1: ���� ��� ������ � � ���� ��� �����������
		if (node->parent == nullptr && node->left == nullptr && node->right == nullptr) {
			// ����� �������� ����� clear(), ���� ��� �����������
			clear(node);
		}
		// case 2: ��� �������
		else if (node->left != nullptr && node->right != nullptr) {
			// ��� ������ node ����� ������ ����������� ������� � ������ ��������� node
			Leaf* found = min(node->right);
			// ����� ����, ��� �� ����� �����������, �� ������ ���������, ���� �� � ���� ������ �������
			if (found->right == nullptr) {
				// ���� ��� - �������� ��� �������
				// �� ����� ���� �� ����� �������� ��� node			
				node->bus = found->bus;
				clear(found);
			}
			else {
				// ���� ���� - �������� � ��������
				node->bus = found->bus;
				delNodeWithChild(found);
			}
		}

		// ����� � node ��� ��������� ��� ���� ������ ����
		else {
			// case 3: ���� � node ��� �����������
			if (node->left == nullptr && node->right == nullptr) {
				clear(node);
			}
			// case 4: ���� ������ ����
			else {
				delNodeWithChild(node);
			}
		}
		cout << "Removed.\n";
	}
	else {
		cout << "Try again.\n";
	}
}

bool Tree::nodeIsLeft(Leaf* node)
{
	Leaf* parentOfNode = node->parent;
	bool nodeIsLeft = false;
	if (parentOfNode->left != nullptr &&
		strcmp(node->bus.getNum(), parentOfNode->left->bus.getNum()) == 0) {
		nodeIsLeft = true;
	}
	return nodeIsLeft;
}

void Tree::delNodeWithChild(Leaf* node)
{
	// ������� node � ��������� ������������ �� ��� �����
	Leaf* parentOfNode = node->parent;
	if (node->left == nullptr && node->right != nullptr) {
		// case 5: ���� ������ � ���� �������
		if (node->parent == nullptr) {
			node->right->parent = nullptr;
			root = node->right;
			delete node;
			return;
		}
		// ����������� �������� � �������� node
		node->right->parent = parentOfNode;
		// � ����������� �� ����, ����� ��� ������ node, ����������� ��� ������ ��������� � ������� ��������� ��������
		(nodeIsLeft(node)) ? parentOfNode->left = node->right : parentOfNode->right = node->right;
		delete node;
	}
	// ���� ��������� ������ ���� � ��� ����� - ������ �� �� ��� � ���� ��� ��� ������
	else if (node->left != nullptr && node->right == nullptr) {
		if (node->parent == nullptr) {
			node->left->parent = nullptr;
			root = node->left;
			delete node;
			return;
		}
		node->left->parent = parentOfNode;
		(nodeIsLeft(node)) ? parentOfNode->left = node->left : parentOfNode->right = node->left;
		delete node;
	}
}

