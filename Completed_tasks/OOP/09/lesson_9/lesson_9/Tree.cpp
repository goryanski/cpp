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

	//дерево пустое?
	if (root == nullptr) {
		root = leaf;
	}
	else {
		//поиск узла к которому будет добавлен новый узел
		Leaf* srchNode = next(leaf->bus.getNum());// передаем строку
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
	//указатель для обхода дерева
	Leaf* tmp = node;
	//указатель на найденный элемент
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
	//указатель для обхода дерева
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
		// вывод будет в порядке возрастания, что бы в порядке убывание, то меняем left и right местами
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

		//удаление корневого узла
		if (node->parent == nullptr) {
			delete root;
			root = nullptr;
		}
		else {
			// перед удалением должны понять, какой узел мы удаляем, левый или правый
			// 1-е условие определеяе существует ли вобще этот узел. 2-е - и если они равны значит это левый узел, тогда мы его удаляем и присваиваем левому nullptr. в else то же для правого
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
		// case 1: если это корень и у него нет поддеревьев
		if (node->parent == nullptr && node->left == nullptr && node->right == nullptr) {
			// можем вызывать метод clear(), если нет поддеревьев
			clear(node);
		}
		// case 2: два потомка
		else if (node->left != nullptr && node->right != nullptr) {
			// для замены node будем искать минимальный элемент в правом поддереве node
			Leaf* found = min(node->right);
			// после того, как мы нашли минимальный, мы должны проверить, есть ли у него правый потомок
			if (found->right == nullptr) {
				// если нет - удаление без потомка
				// но перед этим им нужно заменить наш node			
				node->bus = found->bus;
				clear(found);
			}
			else {
				// если есть - удаление с потомком
				node->bus = found->bus;
				delNodeWithChild(found);
			}
		}

		// иначе у node нет поддерева или есть только одно
		else {
			// case 3: если у node нет поддеревьев
			if (node->left == nullptr && node->right == nullptr) {
				clear(node);
			}
			// case 4: если только одно
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
	// удаляем node и поддерево перевешиваем на его место
	Leaf* parentOfNode = node->parent;
	if (node->left == nullptr && node->right != nullptr) {
		// case 5: если корень и один потомок
		if (node->parent == nullptr) {
			node->right->parent = nullptr;
			root = node->right;
			delete node;
			return;
		}
		// привязываем напрямую к родителю node
		node->right->parent = parentOfNode;
		// в зависимости от того, левый или правый node, привязываем его правое поддерево к нужному поддереву родителя
		(nodeIsLeft(node)) ? parentOfNode->left = node->right : parentOfNode->right = node->right;
		delete node;
	}
	// если поддерево только одно и оно левое - делаем то же что и выше ток для левого
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

