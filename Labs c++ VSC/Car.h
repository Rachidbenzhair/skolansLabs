#pragma once
#include<string>
using namespace std;

class Car
{
private:
	string maker;
	int modell;
	string color;
	static int count; // static så att hela classen har tillgång till den(andra objekt kan få samma information)
public:
	void setMaker(string m);
	string getMaker();
	void setModell(int m);
	int getModell();
	void setColor(string m);
	string getcolor();
	int GetCar_count();

	Car(string ma, int mo,string co); // Detta är Overlaod constractur
	Car();//Detta är defualt constractur
	~Car();

};

