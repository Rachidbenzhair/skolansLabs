#include<iostream>
#include<stack>

using namespace std;


const int MAX_LENGTH = 100;
template <class t>
class arrayQeueType
{
	int rear;
	int front;
	int length;
	t arr[MAX_LENGTH];
public:
	arrayQeueType()
	{
		front = 0;
		rear = MAX_LENGTH - 1;
		length = 0;

	}
	int isEmpty()
	{
		return length == 0;

	}
	bool isFull()
	{
		return length == MAX_LENGTH;
	}
	void addQueue(t element)
	{
		if (isFull())
		{
			cout << "Queue Full Canoy enqueue...!";
		}
		else
		{
			rear = (rear + 1) % MAX_LENGTH;
			arr[rear] = element;
			length++;
		}


	}
	void deleteQueue()
	{
		if (isEmpty())
		{
			cout << "Empty Queue Can´t Dequeue..!";
		}
		else
		{
			front = (front + 1) % MAX_LENGTH;
			length--;
		}
	}
	 void frontQueue()
	{
		assert(!isEmpty());
		return arr[front];
	}
	t rearQueue()
	{
		assert(!isEmpty());
		return arr[rear];
	}
	void printQueue()
	{
		if (!isEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH)
			{
				cout << arr[i] << " ";
			}
			cout << arr[rear] << endl;
		}
		else
			cout << "Empty Queue";

	}
	void queueSearch(t element)
	{
		int pos = -1;
		if (!isEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH)
				if (arr[i] == element)
				{
					pos = i;
					break;
				}
			if (pos == -1)
			{
				if (arr[rear] == element)
					pos = rear;
			}
		}
		else
			cout << "Q is empty ! " << endl;
		return pos;
	}


};
//int main()
//{
//	arrayQeueType <string> q1;
//	q1.addQueue("sami");
//	q1.addQueue("rachid");
//	q1.addQueue("lisa");
//	q1.addQueue("amin");
//	q1.printQueue();
//	q1.deleteQueue();
//	q1.printQueue();
//
//}
//
