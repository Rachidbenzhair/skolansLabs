#include <string>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

//Rectangle Header file
class Rectangle
{
private:
	int height, width;
public:
	//structor
	Rectangle(int, int);
	//Function
	int area();
	int perimeter();
	void print();
	//Setters
	void setHeight(int);
	void setWidth(int);
	// Getters
	int getHeight();
	int getWidth();

};
//Rectangle cpp file
//Function
Rectangle::Rectangle(int h, int w)
{
	setHeight(h);
	setWidth(w);

}
int Rectangle::area()
{
	return height * width;
}
int Rectangle::perimeter()
{
	return 2 * (height + width);
}
void Rectangle::print()
{
	cout << Rectangle::area();
}
//Setters
void Rectangle::setHeight(int h)
{
	height = h;
}
void Rectangle::setWidth(int w)
{
	width = w;
}
// Getters
int Rectangle::getHeight()
{
	return height;
}
int Rectangle::getWidth()
{
	return width;
}
//int main()
//{
//	Rectangle r1 = Rectangle(2, 2);
//	Rectangle r2(24, 57);
//	r1.print();
//
//
//
//	return 0;
//
//}