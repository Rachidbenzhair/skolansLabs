#include "Car.h"
#include<iostream>

using namespace std;

int Car::count = 0; // en static varibel måste intieras utanför classen

Car::Car(string ma, int mo, string co):maker(ma), modell (mo), color (co)// Detta är Overlaod constractur
{
	count++;
}

Car::Car() //Detta är defualt constractur
{
	maker = "honda";
	modell = 2019;
	color = "red";
	count++;
}

Car::~Car()
{
	/*cout<<"hej med dig"<< endl;*/
	count--;

}

void Car::setMaker(string m)
{
	maker = m;
}

string Car::getMaker()
{
	return maker;

}

void Car::setModell(int m)
{
	modell = m;
}

int Car::getModell()
{
	return modell;
}

void Car::setColor(string m)
{
	color = m;
}

string Car::getcolor()
{
	return color;
}

int Car::GetCar_count()
{
	return count;
}
