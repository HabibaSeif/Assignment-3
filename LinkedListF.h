#pragma once
#include<iostream>
#include<algorithm>
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
	LinkedList& Create(vector<int>& v)
	{
		sort(v.begin(), v.end());
		/*for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i);
		}*/

		cout << endl;
		LinkedList L;
		int count = 1;
		int countEnd = 0;
		int value;
		for (int i = 0; i < (v.size() - 1); i++)
		{
			if (v[i] == (v[i + 1]))
			{
				count++;

			}
			else
			{
				L.AddNode(v.at(i), count);
				count = 1;
			}
		}

		vector<int>::iterator q;
		for (q = v.begin(); q != v.end(); q++)
		{
			if (*q == v.at(v.size() - 1))
			{
				countEnd++;
			}
		}

		L.AddNode(v.at(v.size() - 1), countEnd);
		cout << endl;
		L.printLinked();
		cout << "Please enter the value that you want to remove: ";
		cin >> value;
		if (find(v.begin(), v.end(), value) == v.end())
		{
			cout << "The value that you entered is not available";
		}
		else
		{
			L.RemoveNode(value);
		}
		cout << endl;
		cout << "Printing list after removing value: ";
		cout << endl;
		L.printLinked();
		//cout << "The sum is " << L.sum() << endl;
		return L;
	}
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
