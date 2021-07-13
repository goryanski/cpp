#include "List.h"

List::List()
{
	head = tail = nullptr;
}

List::List(const List& obj)
{
	head = tail = nullptr;    
	//������ ������, �� �������� ��������    
	Node * tmp = obj.head;    
	//���� �� ����� ������    
	while(tmp != nullptr) {
		//���������� ������        
		addToTail(tmp->value);        
		tmp = tmp->next;    
	}
}

List::~List()
{
	removeAll();
}

bool List::isEmpty()
{
	return head == nullptr;
}

void List::addToTail(int value)
{
	Node* node = new Node();
	node->value = value;
	if (isEmpty()) {
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = node;
		tail->next = nullptr;
	}
}

void List::addToHead(int value)
{
	Node* node = new Node();
	node->value = value;
	if (isEmpty()) {
		head = tail = node;
	}
	else {
		node->next = head;
		head = node;
	}
}

void List::insert(int value, int num)
{	
	// ���� ����
	if (isEmpty()) {
		Node* node = new Node();
		node->value = value;
		head = tail = node;
	}
	// ���� ������ ������ �������
	else if (num == 1){
		addToHead(value);
	}
	else {
		Node* tmp = head;
		int counter = 0;
		while (counter < num - 2 && tmp != nullptr) {
			tmp = tmp->next;
			counter++;
		}
		// ���� ������ ��������� �������
		if (tmp->next == nullptr) {
			addToTail(value);
		}
		// ���� ������� � ��������
		else {
			Node* node = new Node();
			node->value = value;
			node->next = tmp->next;
			tmp->next = node;
		}		
	}
}

void List::removeHead()
{
	if (isEmpty()) {
		cout << "List is empty\n";
	}
	else {
		if (head->next == nullptr) {
			delete head;
			// ��� isEmpty
			head = nullptr;
		}
		else {
			Node* tmp = head->next;		
			delete head;
			head = tmp;
		}
	}
}

void List::removeTail()
{
	if (isEmpty()) {
		cout << "List is empty\n";
	}
	else if (head->next == nullptr) {
		delete head;
		// ��� isEmpty
		head = nullptr;
	}
	else {
		Node* tmp = head;
		// ����� �� ������ (tmp->next != nullptr), ��������� ���� ���� ��������
		while (tmp->next->next != nullptr) { //���� �� ����� �� ��������������
			tmp = tmp->next;
		}
		delete tail;
		tail = tmp;
		tail->next = nullptr;
	}
}

void List::removePos(int num)
{
	if (isEmpty()) {
		cout << "List is empty\n";
	}
	// ���� ����� ���� �������
	else if (head->next == nullptr) {
		delete head;
		// ��� isEmpty
		head = nullptr;
	}
	// ���� ������ ������ �������
	else if (num == 1) {
		removeHead();
	}
	else {
		Node* tmp = head;
		int counter = 0;
		// �� ��-�� ����� ���������
		while (counter < num - 2 && tmp != nullptr) {
			tmp = tmp->next;
			counter++;
		}
		// ���� ������ ��������� �������
		if (tmp->next->next == nullptr) {
			removeTail();
		}
		// ���� ������� � ��������
		else {
			Node* tmp2 = tmp->next;
			tmp->next = tmp2->next;
			delete tmp2;
		}
	}
}

void List::removeAll()
{
	while (!isEmpty()) {
		removeHead();
	}
}

List List::operator+(const List& obj)
{
	//������� �� ��������� ������ �������� ������� ������
	List Result = *this;
	// ����� ������ ������� ������
	Node* tmp = obj.head;
	//��������� �� ��������� ������ �������� ������� ������
	while (tmp != nullptr) { 
		Result.addToTail(tmp->value);
		tmp = tmp->next; 
	}
	return Result;
}

List& List::operator=(const List& obj)
{
	//�������� ������������ ������ ����   
	if (this == &obj) {
		return *this;
	}
	//�������� ������� ������    
	if (!this->isEmpty()) {
		this->~List();
	}  
	Node* tmp = obj.head;
	//�������� ��������    
	while (tmp != nullptr) {
		addToTail(tmp->value);
		tmp = tmp->next;
	}
	return *this;
}

List List::operator-(const List& obj)
{
	List Result;
	Node* tmp1 = head;
	Node* tmp2 = obj.head;
	while (tmp1 != nullptr) {
		int flag = 0;
		while (tmp2 != nullptr) {
			if (tmp1->value == tmp2->value) {
				flag = 1;
			}
			tmp2 = tmp2->next;
		}
		// ��� �� ������� ������� �� ���������� ����
		tmp2 = obj.head;
		if (flag == 0) {
			Result.addToTail(tmp1->value);
		}
		tmp1 = tmp1->next;
	}
	return Result;
}

void List::showList()
{
	if (!isEmpty()) {
		Node* tmp = head;
		//���� ��� ���� ��������    
		while (tmp != nullptr) { 
			cout << tmp->value << " ";
			//��������� �� ��������� �������        
			tmp = tmp->next;
		}
		cout << "\n\n";
	}
	else {
		cout << "List is empty\n";
	}	
}
