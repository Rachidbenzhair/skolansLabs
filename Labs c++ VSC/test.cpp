/*********************************************
 *  labs1.c
 *  Created on: 10 July 2022
 *  Copyright (c) 2022, Rachid Benzhair
 **********************************************/

#include<stdio.h>3
#include<stdlib.h>

int main()
{
	float degress[3];
	for (int i = 0; i < 3; i++)
	{
		printf("Skriv %d degress:  ", i + 1);
		fflush(stdin);; fflush(stdout);
		scanf("%f", &degress[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("\n student %d degress: %f ", i + 1, degress[i]);

	}


	return 0;

}
