#pragma once
#include<iostream>
using namespace std;

struct Node {
	int value;
	int occurence;
	Node* next;
};
typedef Node* nodepointer;

class LinkedList
{
private:
	nodepointer head;
public:
	LinkedList();
	void AddNode(int v, int o);
	void printLinked();
	int sum();
	void RemoveNode(int v);
};
LinkedList::LinkedList() :head(nullptr)
{

}

void LinkedList::AddNode(int v, int o)
{
	if (o == 0)
	{
		return;
	}
	nodepointer temp = new Node;
	if (head == nullptr)
	{
		temp->value = v;
		temp->occurence = o;
		temp->next = nullptr;
		head = temp;
	}
	else
	{
		temp->value = v;
		temp->occurence = o;
		temp->next = head;
		head = temp;
	}
	///*if (o == 0)
	//{
	//	exit(1);
	//}*/
	//nodepointer temp = new Node;
	////int specifier = 0;
	//if (head == nullptr)
	//{
	//	temp->value = v;
	//	temp->occurence = o;
	//	temp->next = nullptr;
	//	head = temp;
	//	//specifier++;
	//}

	///*o -= specifier;
	//for (int i = 0; i < o; i++)
	//{*/
	//else
	//{
	//	temp = new Node;
	//	temp->value = v;
	//	temp->occurence = o;
	//	temp->next = head;
	//	head = temp;
	//}
	///*}*/
}

void LinkedList::printLinked()
{
	nodepointer p = head;
	while (p != NULL)
	{
		cout << "Number: " << p->value << " " << " Occurence: " << p->occurence << endl;
		p = p->next;
	}
}

int LinkedList::sum()
{
	int Sum = 0;
	nodepointer p = head;
	while (p != NULL)
	{
		Sum += p->value;
		p = p->next;
	}

	return Sum;
}

void LinkedList::RemoveNode(int v)
{
	if (head == nullptr)
	{
		cout << "Nothing to delete";
		return;
	}
	nodepointer p = head, s = p;
	if (head->value == v)
	{
		head = p->next;
		delete p;
		return;
	}
	while ((p->value != v) && (p->next != NULL))
	{
		s = p;
		p = p->next;
	}

	if (p->next == NULL)
	{
		s->next = NULL;
		delete p;
		return;
	}
	else
	{
		s->next = p->next;
		delete p;
		return;
	}

}