//#include <iostream>
//#include <Windows.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <map>
//#include <iterator>
//#include <cstdlib>
//#include <ctime>
//#include <cmath>
//#include <climits>
//#include <random>
//#include <climits>
//#include <sstream>
//#include <iomanip>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//class Array_C
//{
//private:
//	int* A;
//	int size;
//	int length;
//public:
//	Array(int size)
//	{
//		this->size = size;
//		A = new int[size];
//	}
//
//	void create()
//	{
//		cout << " Enter number of element" << endl;
//		cin >> length;
//		cout << "Enter Alll of the element" << endl;
//		for (int i = 0; i < length; i++)
//		{
//			cout << "array element: " << i << "=" << endl;
//			cin >> A[i];
//		}
//	}
//
//	void print()
//	{
//		for (int i = 0; i < length; i++)
//		{
//			cout << A[i] << " ";
//		}
//
//	}
//	~Array()
//	{
//		delete[]A;
//		cout << "Array is desplay " << endl;
//	}
//
//};
//void Print_Class_array()
//{
//	Array arr(10);
//	arr.create();
//	arr.print();
//}
//
//struct Array
//{
//	int A[10];
//	int size;
//	int length;
//
//};
//void display(struct Array arr)
//{
//	printf("\nElement are: \n");
//	for (int i = 0; i < arr.length; i++)
//	{
//		printf("%d\n", arr.A[i]);
//	}
//}
//void append(struct Array* arr, int x)
//{
//	if (arr->length < arr->size)
//	{
//		arr->A[arr->length++] = x;
//	}
//}
//int insert(struct Array* arr, int index, int x)
//{
//	if (index >= 0 && index <= arr->length)
//	{
//		for (int i = arr->length; i > index; i--)
//		{
//			arr->A[i] = arr->A[i - 1];
//
//			arr->length++;
//		}
//		arr->A[index] = x;
//	}
//	return x;
//}
//int Delete(struct Array* arr, int index)
//{
//	int x = 0;
//	if (index >= 0 && index <= arr->length)
//
//	{
//		for (int i = index; i < arr->length - 1; i++)
//		{
//
//			x = arr->A[index];
//			arr->A[i] = arr->A[i + 1];
//			arr->length--;
//		}
//
//	}
//	return index;
//}
//
//void swap(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//int LenearSearch(struct Array* arr, int key)
//{
//	int i;
//	for (i = 0; i < arr->length; i++)
//	{
//		if (key == arr->A[i])
//		{
//			swap(&arr->A[i], &arr->A[i]);
//			return i;
//		}
//	}
//}
//int BinarySearch(struct Array arr, int key)
//{
//	int l, mid, h;
//	l = 0;
//	h = arr.length - 1;
//	while (1 <= h)
//	{
//		mid = (1 + h) / 2;
//		if (key == arr.A[mid])
//		{
//			return mid;
//		}
//		else if (key < arr.A[mid])
//		{
//			h = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//}
//
//int RBinSearch(int a[], int l, int h, int key)
//{
//
//	int mid = 0;
//
//	if (l <= h)
//	{
//		mid = (1 + h) / 2;
//		if (key == a[mid])
//		{
//			return mid;
//
//		}
//		else if (key < a[mid])
//		{
//			return RBinSearch(a, l, mid - 1, key);
//
//		}
//		else
//		{
//			return RBinSearch(a, mid + 1, h, key);
//
//		}
//
//	}
//}
//int Get(struct Array arr, int index)
//{
//	if (index >= 0 && index < arr.length)
//	{
//		return arr.A[index];
//	}
//}
//int Set(struct Array* arr, int index, int x)
//{
//	if (index >= 0 && index < arr->length)
//	{
//		return arr->A[index] = x;
//	}
//
//}
//int Max(struct Array arr)
//{
//	int max = arr.A[0];
//	for (int i = 1; i < arr.length; i++)
//	{
//		if (arr.A[i] > max)
//		{
//			max = arr.A[i];
//		}
//	}
//	return max;
//}
//int Min(struct Array arr)
//{
//	int min = arr.A[0];
//	for (int i = 1; i < arr.length; i++)
//	{
//		if (arr.A[i] > min)
//		{
//			min = arr.A[i];
//		}
//	}
//	return min;
//}
//
//int Sum(struct Array arr)
//{
//	int s = 0;
//	for (int i = 0; i < arr.length; i++)
//	{
//		s += arr.A[i];
//	}
//	return s;
//}
//float Avg(struct Array arr)
//{
//	return (float)Sum(arr) / arr.length;
//}
//void Reverse(struct Array* arr)
//{
//	int* B;
//	int i, j;
//	B = (int*)malloc(arr->length * sizeof(int));
//
//	for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
//	{
//		B[j] = arr->A[i];
//	}
//	for (i = 0; i < arr->length; i++)
//	{
//		arr->A[i] = B[i];
//	}
//}
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//
//
//
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void RDisplay(struct Node* p)
//{
//	if (p != NULL)
//	{
//		RDisplay(p->next);
//		printf("%d ", p->data);
//
//	}
//}
//int count(struct Node* p) {
//
//	//1. create a temp node pointing to head
//	Node* temp = p;
//
//	//2. create a variable to count nodes
//	int i = 0;
//
//	//3. if the temp node is not null increase 
//	//   i by 1 and move to the next node, repeat
//	//   the process till the temp becomes null
//	while (temp != NULL)
//	{
//		i++;
//		temp = temp->next;
//	}
//
//	//4. return the count
//	return i;
//}
//
//int Rcount(struct Node* p)
//{
//	if (p != NULL)
//		return Rcount(p->next) + 1;
//	else
//		return 0;
//}
//int sum(struct Node* p)
//{
//	int s = 0;
//	while (p != NULL)
//	{
//		s += p->data;
//		p = p->next;
//	}
//	return s;
//}
//int Rsum(struct Node* p)
//{
//	if (p != NULL)
//		return Rsum(p->next) + p->data;
//	else
//		return 0;
//}
//int Max(struct Node* p)
//{
//	int max = INT_MIN;
//	while (p != NULL) {
//
//		// If max is less then head->data then
//		// assign value of head->data to max
//		// otherwise node point to next node.
//		if (max < p->data)
//			max = p->data;
//		p = p->next;
//	}
//	return max;
//	// Function that returns smallest element
//	// from the linked list.
//}
//
//int Min(struct Node* p)
//{
//
//	// Declare a min variable and initialize
//		// it with INT_MAX value.
//		// INT_MAX is integer type and its value
//		// is 32767 or greater.
//	int min = INT_MAX;
//
//	// Check loop while head not equal to NULL
//	while (p != NULL) 
//	{
//
//		// If min is greater then head->data then
//		// assign value of head->data to min
//		// otherwise node point to next node.
//		if (min > p->data)
//			min = p->data;
//
//		p = p->next;
//	}
//	return min;
//}
//
//
//
//
////
//////int main()
//////{
//////	struct Node* temp;
//////	int A[] = { 3,5,7,10,25,8,32,2 };
//////	create(A, 8);
//////	Display(first);
//////
//////	printf("count %d\n", Rcount(first));
//////	printf("count %d\n", count(first));
//////	printf("Sum %d\n", sum(first));
//////	printf("Sum %d\n", Rsum(first));
//////	printf("Max %d\n", Max(first));
//////	printf("Min %d\n", Min(first));
//////
//////
//////	return 0;
//////}
////
//////
//////int main()
//////{
//////	struct Array arr1 = { {2,3,4,12,3,15,8,30},10,8 };
//////	printf()
//////
//////		int userinput = 0;
//////	int userinput0 = 0;
//////	int userinput1 = 0;
//////	int	userinput2 = 0;
//////	int  userinput3 = 0;
//////	printf("chose Below\n");
//////	printf("1: lagg till element: \n");
//////	printf("2: Ersatt till element: \n");
//////	printf("3: ta bort element: \n");
//////	printf("4: enkel search element: \n");
//////	printf("5: ange Min/Max then element: \n");
//////	scanf("%d", &userinput);
//////
//////
//////	switch (userinput)
//////	{
//////	case 1:
//////		printf("Skriv Element: ");
//////		scanf("%d", &userinput0);
//////		append(&arr1, userinput0);//lägger ett värde i slutet i array
//////		display(arr1);
//////		break;
//////
//////	case 2:
//////		printf("Skriv index: ");
//////		scanf("%d", &userinput1);
//////		printf("Skriv value: ");
//////		scanf("%d", &userinput2);
//////		insert(&arr1, userinput1, userinput2); //ersätter ett värde i vår array med önskat värde
//////		display(arr1);
//////		break;
//////
//////	case 3:
//////		printf("Skriv index: ");
//////		scanf("%d", &userinput1);
//////		Delete(&arr1, userinput1); //tar bort efterfrågat index;
//////		display(arr1);
//////		break;
//////
//////	case 4:
//////		printf("Skriv value: ");
//////		scanf("%d", &userinput1);
//////		printf("Element finns i index: %d\n", LenearSearch(&arr1, userinput1)); //söker från start till slut
//////		display(arr1);
//////		break;
//////
//////	case 5:
//////		printf("Skriv Min Value(min 0): ");
//////		scanf("%d", &userinput1);
//////		printf("Skriv Max Value(Max 30): ");
//////		scanf("%d", &userinput2);
//////		printf("Skriv Value: ");
//////		scanf("%d", &userinput3);
//////
//////		if (false)
//////		{
//////			printf("Element finns i index: %d\n", RBinSearch(arr1.A, userinput1, userinput2, userinput3)); //samma som ovan fast med recursive functions
//////			break;
//////		}
//////		else
//////		{
//////			printf(" Element not found");
//////		}
//////
//////	default:
//////		break;
//////	}
//////	return 0;
//////}
