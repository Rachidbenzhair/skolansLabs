#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <map>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <random>
#include <climits>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

template <class t>
class linkedList
{
	struct Node
	{
		t item;
		Node* next;
	};
public:
	Node* first;
	Node* last;
	int length;

	linkedList()
	{
		first = last = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		return length == 0;
	}
	void insertFirst(t element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		if (length == 0)
		{
			first = last = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = first;
			first = newNode;
		}
		length++;
	}
	void insertLast(t element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		if (length == 0)
		{
			first = last = newNode;
			newNode->next = NULL;
		}
		else
		{
			last->next = newNode;
			newNode->next = NULL;
			last = newNode;
		}
		length++;
	}
	void insertAtPos(t pos, t element)
	{
		if (pos<0 || pos>length)
			cout << "out of range";
		else
		{
			Node* newNode = new Node;
			newNode->item = element;
			if (pos == 0)
				insertFirst(element);
			else if (pos == length)
				insertLast(element);
			else
			{
				Node* Cur = first;
				for (size_t i = 1; i < pos; i++)
				{
					Cur = Cur->next;
				}
				newNode->next = Cur->next;
				Cur->next = newNode;
				length++;
			}
		}
	}
	void removeFirst()
	{
		if (length == 0)
			cout << "Empty List Can´t Remove" << endl;
		else if (length == 1)
		{
			delete first;
			last = first = NULL;
			length--;
		}
		else
		{
			Node* current = first;
			first = first->next;
			delete current;
			length--;
		}
	}
	void removeLast()
	{
		if (length == 0)
			cout << "Empty List Can´t Remove" << endl;
		else if (length == 1)
		{
			delete last;
			last = first = NULL;
			length--;
		}
		else
		{
			Node* current = first->next;
			Node* prev = first;
			while (current != last)
			{
				prev = current;
				current = current->next;
			}
			delete current;
			prev->next = NULL;
			last = prev;
			length--;
		}
	}
	void remove(t element)
	{
		if (isEmpty())
		{
			cout << "Empty List Can´t Remove";
			return;
		}
		Node* current, * prev;
		if (first->item == element)
		{
			current = first;
			first = first->next;
			delete current;
			length--;
			if (length == 0)
				last = NULL;
		}
		else
		{
			current = first->next;
			prev = first;
			while (current != NULL)
			{
				if (current->item == element)
					break;
				prev = current;
				current = current->next;
			}

			if (current == NULL)
				cout << "The item is not there\n";
			else
			{
				prev->next = current->next;
				if (last == current) //delete the last item
					last = prev;
				delete current;
				length--;
			}
		}
	}
	void removeAtIndex(t pos)
	{
		if (pos<0 || pos>length)
			cout << "out of range";
		Node* current, * prev;
		if (pos == 0)
		{
			current = first;
			first = first->next;
			delete current;
			length--;
			if (length == 0)
				last = NULL;
		}
		else
		{
			current = first->next;
			prev = first;
			for (size_t i = 1; i < pos; i++)
			{
				prev = current;
				current = current->next;
			}

			prev->next = current->next;
			if (last == current)
				last = prev;
			delete current;
			length--;
		}

	}
	void reverse()
	{
		Node* prev, * next, * curr;
		prev = NULL;
		curr = first;
		next = curr->next;
		while (next != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		first = prev;
	}
	t search(t element)
	{
		Node* current = first;
		int pos = 0;
		while (current != NULL)
		{
			if (current->item == element)
				return pos;
			current = current->next;
			pos++;
		}
		return-1;
	}


	void print()
	{
		Node* Cur = first;
		while (Cur != NULL)
		{
			cout << Cur->item << " ";
			Cur = Cur->next;
		}
		cout << endl;
	}
	t removeOddSumEven()
	{
		t sum = first->item;
		Node* current = first->next;
		Node* prev = first;

		while (current != NULL)
		{
			if (current->item % 2 == 0)
			{
				sum += current->item;
				prev = current;
				current = current->next;
			}
			else
			{
				prev->next = current->next;
				delete current;
				length--;
				current = prev->next;
			}
		}
		return sum;
	}
	t listSize()
	{
		return length;
	}
	void clearList()
	{
		Node * current;
		while (first != NULL)
		{
			current = first;
			first = first->next;
			delete current;
		}
		last = NULL;
		length = 0;
	}

};


//int main()
//{
//	linkedList <int> L1;
//	L1.insertFirst(10);
//	L1.insertFirst(7);
//	L1.insertFirst(30);
//	L1.insertFirst(40);
//	L1.insertFirst(0);
//	L1.print();
//	L1.insertAtPos(1, 100);
//	L1.print();
//	L1.insertLast(200);
//	L1.print();
//	L1.insertFirst(400);
//	L1.print();
//	L1.removeFirst();
//	L1.print();
//	L1.removeLast();
//	L1.print();
//	L1.remove(100);
//	L1.print();
//	L1.removeAtIndex(1);
//	L1.print();
//	L1.reverse();
//	L1.print();
//	cout << L1.search(30) << endl;
//	L1.removeOddSumEven();
//	L1.print();
//	cout << L1.listSize() << endl;
//	L1.clearList();
//	L1.print();
//
//}