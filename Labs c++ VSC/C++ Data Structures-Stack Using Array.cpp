#include<iostream>
using namespace std;

const int MAX_SIZE = 50;

template<class t>

class stack {
	int top;
	t item[MAX_SIZE];
public:
	stack()
	{
		top = -1;
	}
	bool isEmpty()
	{
		return top < 0;
	}
	bool isFull()
	{
		return top == MAX_SIZE - 1;
	}
	void push(t Element)
	{
		if (top >= MAX_SIZE - 1)
		{
			cout << "Stack is full";
		}
		else
		{
			top++;
			item[top] = Element;
		}
	}
	void pop()
	{
		if (isEmpty())
			cout << "stack is empty";
		else
			top--;
	}
	t peek(t index)
	{
		int x = -1;
		if (top - index + 1 < 0)
			cout << "invalid Index" << endl;
		else
		{
			x = item[top - index + 1];

		}
		return x;
	}

	t stackTop()
	{
		int x = -1;
		if (isEmpty())
			cout << "stack is empty";
		else 
		{
			x= item[top];
		}
		return x;
	}
	void print()
	{
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;

	}
};


//int main()
//{
//
//	stack<int>s;
//	s.push(8);
//	s.push(11);
//	s.push(15);
//	s.push(30);
//	s.print();
//	s.pop();
//	s.print();
//	cout << "Peek is: " << s.peek(2) << endl;
//	cout << "StackTop is: " << s.stackTop() << endl;
//	s.print();
//
//}