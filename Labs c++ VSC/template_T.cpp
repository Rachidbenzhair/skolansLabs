#include <iostream>
using namespace std;

template<class T>
class Arithmetic
{
private:
	T a;
	T b;

public:
	Arithmetic(T a, T b);
	T add();
	T sub();
};
template<class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
	this->a = a;
	this->b = b;
}
template<class T>
T Arithmetic<T>::add()
{
	T c;
	c = a + b;
	return c;
}
template<class T>
T Arithmetic<T>::sub()
{
	T c;
	c = a - b;
	return c;
}
void Arithmetic_print()
{
	Arithmetic<float> ar(10.99, 5.44);
	cout << ar.add() << endl;
	cout << ar.sub() << endl;

}

class Roctangle
{

private:
	int length;
	int breadth;
public:
	Roctangle(int l, int b)
	{
		length = l;
		breadth = b;
	}
	int area()
	{
		return length * breadth;
	}
	void changelength(int s)
	{
		length = s;

	}

};



//int main()
//{
//	Roctangle r(10, 5);
//	cout << r.area() << endl;
//	r.changelength(20);
//	cout << r.area() << endl;
//}

