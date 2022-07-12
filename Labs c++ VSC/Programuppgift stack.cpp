#include <stdio.h>
#include<stdlib.h>



struct Node
{
	int data;
	struct Node* next;
}*first = NULL;



void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		RDisplay(p->next);
		printf("%d ", p->data);

	}
}
int count(struct Node* p)
{

	/*1. create a temp node pointing to head*/
	Node* temp = p;

	/*2. create a variable to count nodes*/
	int i = 0;

	/*3. if the temp node is not null increase
	   i by 1 and move to the next node, repeat
	   the process till the temp becomes null*/
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}

	/*4. return the count*/
	return i;
}

int Rcount(struct Node* p)
{
	if (p != NULL)
		return Rcount(p->next) + 1;
	else
		return 0;
}
int sum(struct Node* p)
{
	int s = 0;
	while (p != NULL)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}
int Rsum(struct Node* p)
{
	if (p != NULL)
		return Rsum(p->next) + p->data;
	else
		return 0;
}
int Max(struct Node* p)
{
	int max = INT_MIN;
	while (p != NULL) {

		/* If max is less then head->data then
		 assign value of head->data to max
		 otherwise node point to next node.*/
		if (max < p->data)
			max = p->data;
		p = p->next;
	}
	return max;
	/* Function that returns smallest element
	 from the linked list.*/
}

int Min(struct Node* p)
{

	/* Declare a min variable and initialize*/
		/* it with INT_MAX value.
		 INT_MAX is integer type and its value
		 is 32767 or greater.*/
	int min = INT_MAX;

	/* Check loop while head not equal to NULL*/
	while (p != NULL)
	{

		/*If min is greater then head->data then
		assign value of head->data to min
		otherwise node point to next node.*/
		if (min > p->data)
			min = p->data;

		p = p->next;
	}
	return min;
}




//
//int main()
//{
//	struct Node* temp;
//	int A[] = { 3,5,7,10,25,8,32,2 };
//	create(A, 8);
//	Display(first);
//
//	printf("count %d\n", Rcount(first));
//	printf("count %d\n", count(first));
//	printf("Sum %d\n", sum(first));
//	printf("Sum %d\n", Rsum(first));
//	printf("Max %d\n", Max(first));
//	printf("Min %d\n", Min(first));
//
//
//	return 0;
//}
