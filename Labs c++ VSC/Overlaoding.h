#pragma once
#include<string>
using namespace std;
class Overlaoding
{

public:
	int add(int num1, int num2);
	int add(int num1, int num2, int num3);
	int add(int num1, int num2, int num3, int num4);
	float add(float num1, float num2, float num3);
	string add(string a, string b);

	Overlaoding();
	~Overlaoding();

};

