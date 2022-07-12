#include <stdio.h>
#include<stdlib.h>
using namespace std;

void fun(int n)
{
	if (n > 0)
	{
		fun(n - 1); //Head recursive
		printf("%d", n);
		//fun(n - 1);// Head recursive	
	}
}
int Xfun(int n)
{
	static int x = 0;
	if (n > 0)
	{
		x++;
		return Xfun(n - 1) + x;
	}

}
int tfun(int n)
{

	if (n > 0)
	{

		return tfun(n - 1) + n;
	}
}

void treefun(int n) // tree recursion det kommer inte mer �n det som skickas med det bara upprepas
{
	if (n > 0)
	{

		printf("%d", n);
		fun(n - 1);
		fun(n - 1);
	}
}

//indirect Recursion �r n�r att funktionen kallar p� sig p� ett indirekt s�tt exmpel 
//funA kallar p� funB som kallar p� funC som kallar p� funA

void funB(int n);
void funA(int n)
{
	if (n > 0)
	{
		printf("%d\n", n);
		funB(n - 1);
	}
}
void funB(int n)
{
	if (n > 1)
	{
		printf("%d\n", n);
		funA(n / 2);
	}
}

//Nestd Recursion 
// N�r en funktion kallar p� sig men calling funktion �ven anv�nder som prameter
int funN(int n)
{
	if (n > 100)
	{
		return n - 10;
		
	}
	return funN(funN(n + 11));
}

//summa av 1.2.3.4.5

int sum(int n)
{
	if (n==0)
	{
		return 0;
		
	}
	else
	{
		return sum(n-1) + n;
	}
	
}

//1*2*3*4*5 factorial
// kan aldrig bli mindre �n 1 

int fact(int n)
{
	if (n == 0)
	{
		return 1;

	}
	else
	{
		return fact(n - 1) * n;
	}

}
//power function
int power(int m, int n)
{
	if (n == 0)
	{
		return 1;

	}
	else
	{
		return power( m,n - 1) * m;
	}
}

//int main()
//{
//	int r = power(9,3);
//	printf("%d\n", r);
//	return 0;
//}
//

