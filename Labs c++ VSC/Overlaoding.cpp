#include "Overlaoding.h"

int Overlaoding::add(int num1, int num2)
{
    return num1 + num2;
}

int Overlaoding::add(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

int Overlaoding::add(int num1, int num2, int num3, int num4)
{
    return num1 + num2 + num3 + num4;
}

float Overlaoding::add(float num1, float num2, float num3)
{
    return num1 + num2 + num3;
}

string Overlaoding::add(string a, string b)
{
    return a + " " + b;
}
Overlaoding::Overlaoding()
{
}
Overlaoding::~Overlaoding()
{
}
