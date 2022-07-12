#include<iostream>
using namespace std;

class shape
{
public:
	virtual float area()
	{
		return 0;
	}
	virtual float perimeter()
	{
		return 0;
	}

};
class Rectangle :public shape
{
private:
	float width;
	float height;
	float pi = 3.14;
	float radius;

public:
	Rectangle(float a = 0, float b = 0)
	{
		width = a;
		height = b;
	}

	float area()
	{
		cout << "rectangle area: " << (width * height) << endl;
		return (width * height);
	}
	float perimeter()
	{
		cout << "perimeter : " << (width * 2) + (height * 2) << endl;
		return (width * 2) + (height * 2);
	}


};
class circle : public shape
{
private:
	float pi = 3.14;
	float radius;

public:
	circle(float r = 0)
	{
		radius = r;
	}

	float area()
	{
		cout << "circle area: " << (radius * radius) * pi << endl;
		return (radius * radius) * pi;
	}
	float perimeter()
	{
		cout << "circle perimeter : " << 2 * pi * radius << endl;
		return 2 * pi * radius;
	}
};

//int main()
//{
//	shape* p1 = new rectangle(10, 16);
//	p1->area();
//	p1->perimeter();
//
//	shape* p2 = new circle(7.9);
//	p2->area();
//	p2->perimeter();
//

//}