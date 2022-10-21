#include<iostream>
#include<vector>
#include "LinkedList.h"
#include <algorithm>
using namespace std;

void insertAfter(int f, int s, vector<int>& v)
{
	vector<int>::iterator p;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == f)
		{
			p = v.begin() + (i + 1);
			v.insert(p, s);
			i++;
		}
	}
	cout << endl;
	cout << "After insert: " << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

LinkedList& Create(vector<int> & v)
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

	L.AddNode(v.at(v.size() -1), countEnd);
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


int main()
{
	int n = 0;
	cout << "Please enter the size of the vector that you want: ";
	cin >> n;
	vector<int>Number(n);
	cout << "Please enter " << n << " numbers in the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >>Number.at(i );
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << Number.at(i);
	}*/
	int firstValue, secondValue;
	cout << "Please enter the first and the second value repectively: ";
	cin >> firstValue >> secondValue;
	insertAfter(firstValue, secondValue, Number);
	cout << "The sum is: " << Create(Number).sum() << endl;

}