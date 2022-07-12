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
#include<cassert>

using namespace std;

template <class t>

class linkedQueue
{
private:
	struct Node
	{
		t item;
		Node* next;

	};
	Node* frontPtr;
	Node* rearPtr;
	int length;
public:
	linkedQueue() //:frontPtr(NULL),rearPtr(NULL),length(0)
	{
		frontPtr = rearPtr = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		//return length==0;
		if (rearPtr == NULL)
		{
			return true;
		}
		else
			return false;
	}
	void enqueue(t element)
	{
		if (isEmpty())
		{
			frontPtr = new Node;
			frontPtr->item = element;
			frontPtr->next = NULL;
			rearPtr = frontPtr;
			length++;
		}
		else
		{
			Node* newPtr = new Node;
			newPtr->item = element;
			newPtr->next = NULL;
			rearPtr->next = newPtr;
			rearPtr = newPtr;
			length++;
		}

	}
	void denqueue()

	{
		if (isEmpty())
			cout << "Empty Queue, cannot Dequeue...!";
		else
		{

			Node* tempPtr = frontPtr;
			if (frontPtr == rearPtr)
			{
				frontPtr = NULL;
				rearPtr = NULL;
				length--;
			}
			else
			{
				length--;
				frontPtr = frontPtr->next;
				tempPtr->next = NULL;
				delete tempPtr;
			}
		}

	}
	t getFront()
	{
		assert(!isEmpty());
		return frontPtr->item;
	}
	t getRear()
	{
		assert(!isEmpty());
		return rearPtr->item;
	}
	void clearQueue()
	{
		Node* current;
		while (frontPtr != NULL)
		{
			current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
		}
		rearPtr = NULL;
		length = 0;

	}
	void printQueue()
	{
		Node* currentPtr = frontPtr;
		cout << "items in Queue : [ ";
		while (currentPtr != NULL)
		{
			cout << currentPtr->item << " ";
			currentPtr = currentPtr->next;
		}
		cout << "]\n";

	}
	int getSize()
	{
		return length;
	}
	void search(t item)
	{
		Node* cur = frontPtr;
		bool flag = true;
		while (cur != NULL)
		{
			if (cur->item == item)
			{
				cout << "the item :" << item << " found" << endl;
				flag = false;
				break;
			}
			cur = cur->next;
		}
		if (flag)
			cout << "the item : " << item << " not found" << endl;

	}


};
//
//int main()
//{
//	linkedQueue<string> q1;
//	q1.enqueue("sami");
//	q1.enqueue("rachid");
//	q1.enqueue("lisa");
//	q1.enqueue("amin");
//	q1.printQueue();
//	q1.denqueue();
//	q1.printQueue();
//	q1.printQueue();
//	q1.search("sami");
//	cout << q1.getFront() << endl;
//	cout << q1.getRear() << endl;
//	cout << q1.getSize() << endl;
//	q1.clearQueue();
//	q1.printQueue();
//	q1.search("sami");
//
//}
