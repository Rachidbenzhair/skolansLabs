#include <iostream>
#include<string>



using namespace std;
const int MAX_SIZE = 100;
template <class t>
class geniric_stack
{
private:
	int top;
	t item[100];
public:
	//stack():top (-1)går bra med denna rad bara
	geniric_stack()
	{
		top = -1;
	}
	void push(t element)
	{
		if (top >= MAX_SIZE - 1)
		{
			cout << "stack full on push" << endl;
		}
		else
		{
			top++;
			item[top] = element;
		}
	}
	bool isEmpety()
	{
		//return top < 0; går bra med denna rad bara
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void pop()
	{
		if (isEmpety())
			cout << "stack empety on pop" << endl;
		else
			top--;
	}
	void pop(t & element)
	{
		if (isEmpety())
			cout << "stack empety on pop" << endl;
		else
			element = item[top];
		top--;
	}
	void getTop(t & stacktop)
	{
		if (isEmpety())
			cout << "stack empety on getTop" << endl;
		else
		{
			stacktop = item[top];
			cout << stacktop << endl;
		}
	}
	void print()
	{
		cout << "[";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;
	}
};
void geniric_stack_f()
{
	geniric_stack <string> s;
	s.push("Rachid");
	s.push("Sami");
	s.push("Lisa");
	s.push("Ahmed");
	string y = " ";
	s.getTop(y);
	s.print();
	s.pop();
	s.getTop(y);
	s.print();
	s.push("Said");
	s.getTop(y);
	s.print();


}


class vanlig_stack
{
private:
	int top;
	int item[100];
public:
	//stack():top (-1)går bra med denna rad bara
	vanlig_stack()
	{
		top = -1;
	}
	void push(int element)
	{
		if (top >= MAX_SIZE - 1)
		{
			cout << "stack full on push" << endl;
		}
		else
		{
			top++;
			item[top] = element;
		}
	}
	bool isEmpety()
	{
		//return top < 0; går bra med denna rad bara
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void pop()
	{
		if (isEmpety())
			cout << "stack empety on pop" << endl;
		else
			top--;
	}
	void pop(int& element)
	{
		if (isEmpety())
			cout << "stack empety on pop" << endl;
		else
			element = item[top];
		top--;
	}
	void getTop(int& stacktop)
	{
		if (isEmpety())
			cout << "stack empety on getTop" << endl;
		else
		{
			stacktop = item[top];
			cout << stacktop << endl;
		}
	}
	void print()
	{
		cout << "[";
			for (int i = top; i >= 0; i--)
			{
				cout << item[i] << " ";
			}
			cout << "]";
			cout << endl;
	}
};
void vanlig_stack_f()
{
	vanlig_stack s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	int y = 0;
	s.getTop(y);
	s.print();
	s.pop();
	s.getTop(y);
	s.print();
	s.push(30);
	s.getTop(y);
	s.print();


}


//int main()
//{
//	vanlig_stack_f();
//	geniric_stack_f();
//	
//
//}