#include <iostream>


using namespace std;
template <class t>
class stack
{
	struct node
	{
		t item;
		node* next;
	};
	node* top, * current;
public:
	stack()
	{
		top = NULL;
	}
	void push(t newItem)
	{
		node* newItemPtr = new node;
		if (newItemPtr == NULL)
			cout << "stack push cannot allocate memory" << endl;
		else
		{
			newItemPtr->item = newItem;
			newItemPtr->next = top;
			top = newItemPtr;
		}
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	void pop()
	{
		if (isEmpty())
			cout << "stqack empty on pop" << endl;
		else
		{
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void pop(t& stackTop)
	{
		if (isEmpty())
			cout << "stqack empty on pop" << endl;
		else
		{
			stackTop = top->item;
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void getTop(t& stackTop)
	{
		if (isEmpty())
			cout << "stqack empty on pop" << endl;
		else
		{
			stackTop = top->item;
		}
	}
	void print()
	{
		current = top;
		cout << "\nItems in the stack: ";
		cout << "[";
		while (current != NULL)
		{
			cout << current->item << " ";
			current = current->next;
		}
		cout << "]\n";
	}
};

//int main()
//{
//	stack <int> s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.push(50);
//	s.print();
//	s.pop();
//	s.print();
//	int x = 0;
//	s.getTop(x);
//	cout << x << endl;
//
//
//}
