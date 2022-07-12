#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//statisc array d�r vi best�mt och anget hur stor den ska vara b�da storlek och element
//Dynamisk �r n�r vi inte best�mmer strolek i f�rv�g 
//void StDyarray()
//{
//	int A[5] = { 2,4,6,8,10 }; //Statisk array
//	int* p;
//	int i;
//
//	// s�ttet att skaffa ny array  med C i Heap d� s�ger vi reservera s� h�r mkt i minnet av varjbler integer
//	p = (int*)malloc(5 * sizeof(int)); //Dynamisk array
//	p[0] = 3;
//	p[1] = 5;
//	p[2] = 7;
//	p[3] = 9;
//	p[4] = 11;
//	for (i = 0; i < 5; i++)
//		printf("%d ", A[i]);
//	printf("\n");
//	for (i = 0; i < 5; i++)
//		printf("%d ", p[i]);
//
//}

// s�ttet att skappa en fler fler dimensions array
//void array2D()
//{
//	int A[3][4] = { {1,2,3,4},{2,4,6,8},{1,3,5,7} };
//	int* B[3];
//	int** C;
//	int i, j;
//	B[0] = (int*)malloc(4 * sizeof(int));
//	B[1] = (int*)malloc(4 * sizeof(int));
//	B[2] = (int*)malloc(4 * sizeof(int));
//	//deklarerar vardera index som en array
//	C = (int**)malloc(3 * sizeof(int*));
//	C[0] = (int*)malloc(4 * sizeof(int));
//	C[1] = (int*)malloc(4 * sizeof(int));
//	C[2] = (int*)malloc(4 * sizeof(int));
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//			printf("%d ", C[i][j]);
//		printf("\n");
//	}
//
//}
//Array Abstract DataType;
//ADT
//class Array
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
//	void create() // V�r user input
//	{
//		cout << "Enter number of elements: " << flush;
//		cin >> length;
//		cout << "Enter the array elements: " << endl;
//		for (int i = 0; i < length; i++)
//		{
//			cout << "Array element: " << i + 1 << " = " << flush;
//			cin >> A[i];
//		}
//	}
//	void display() //v�r redovisning
//	{
//		for (int i = 0; i < length; i++)
//		{
//			cout << A[i] << " ";
//		}
//		cout << endl;
//
//	}
//	~Array()  //destructor d� det e class
//	{
//		delete[] A;
//		cout << "Array destroyed" << endl;
//	}
//};

//struct Arrays
//{
//	int A[10];
//	int size;
//	int length;
//};
//void tDisplay(struct Arrays arr)
//{
//	int i;
//	printf("\nElements are\n");
//	for (i = 0; i < arr.length; i++)
//	{
//		printf("%d ", arr.A[i]);
//
//	}
//	printf("\n");
//
//}
//void Append(struct Arrays* arr, int x)// Append n�r vi l�gger items i slutet av Array 
//{
//	if (arr->length < arr->size)// vi m�ste f�rst veta om array �r full eller finns lediga platser 
//	{
//		arr->A[arr->length] = x;// h�r l�gger vi islutet items of length den nya items
//		arr->length++;// samt h�jer vi length efter nya items 
//	}
//
//}
//void Insert(struct Arrays* arr, int index, int x)// metoden som h�jlper oss att vi sj�lva best�mmer vart i array kan vi l�gga v�r items( val av index)
//{
//	if (index >= 0 && index <= arr->length)// vi m�ste f�rst g�ra valdation p� users input s� vi inte f� problem s� att index vi f�r inte stiger size och att det finns plats ledigt
//	{
//		for (int i = arr->length; i > index; i--)	// f�rst vi m�ste flytta items till h�ger f�r att f� index platsen ledig d�rf�r anv�ndev loop samt 
//													//vi r�knar ner �t fr�n length som �r sista postion till den index vi vill fylla i (i--)
//		{
//			arr->A[i] = arr->A[i - 1];////varje g�ng vi flyttar oss ner �t (till vinster) s� l�gger vi items ett steg fram till h�ger och vi flyttar length ett steg till vinster med -1
//
//		}
//		arr->A[index] = x;//n�r length (i) �r st�rre �n index vi f�tt fr�n user stnnar vi och l�gger vi X
//		arr->length++;// samt h�jer vi length med ett d� nytt item har lagts till.
//
//	}
//}
//void Ersatt(struct Arrays* arr, int index, int x)// metoden som h�jlper oss att vi sj�lva best�mmer vilken plats i array( val av index) kan vi ers�tta den gamla
//{
//
//	if (index >= 0 && index <= arr->length)//vi m�ste f�rst g�ra valdation p� users input s� vi inte f� problem s� att index vi f�r inte stiger size och att det finns plats ledigt
//	{
//		for (int i = arr->length; i > index; i--)	// f�rst vi m�ste flytta items till h�ger f�r att f� index platsen ledig d�rf�r anv�ndev loop samt 
//													//vi r�knar ner �t fr�n length som �r sista postion till den index vi vill fylla i (i--)
//		{
//			arr->A[index] = x;
//		}
//	}
//}
//void Delete(struct Arrays* arr, int index)
//{
//	if (index >= 0 && index < arr->length)//f�rst vi chickar av indexet vi tar emot om den inom array range 
//	{
//
//		for (int i = index; i < arr->length - 1; i++) // i �r lika med index vi tog emot och indexet ska vara mindre �n length d� den ska stnna innan length
//		{
//			arr->A[i] = arr->A[i + 1];// h�r s�ger vi till att indexet som loopar h�r �r lika med indexet plus ett f�r i delete vi g�r till h�ger tv�rtom insert
//
//		}
//		arr->length--;// vi minskar length med en eftersom vi tog bort en index fr�n array
//	}
//}
//int Linearsearch(struct Arrays* arr, int key)//metod (linj�r Search) som hj�lper oss att s�ka genom array p� det vi s�ker
//{
//	int index = -1;//vi intierar med -1 (om vi inte hittar s�kt key skickar vi -1 eftersom array  index b�rjar med 0
//
//	for (int i = 0; i < arr->length; i++)
//	{
//		if (key == arr->A[i])// j�mf�ra key med items 
//		{
//			index = i;// om vi hittar items sparar vi det i index
//			break;	// om vi hittar items sparar vi det i index
//		}
//	}
//	return index;
//}
//void swap(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int LinearsearchSwap(struct Arrays* arr, int key)//metod (linj�r Search) som hj�lper oss att s�ka genom array p� det vi s�ker efter med hj�lp av swap
//{
//
//	for (int i = 0; i < arr->length; i++)
//	{
//		if (key == arr->A[i])// j�mf�ra key med items 
//		{
//			swap(&arr->A[i], &arr->A[0]); //vi skickar till swap funktionen 
//			return i;
//		}
//		
//			
//	}
//	return -1;
//}
//int BinarySearch(struct Arrays arr,int l,int h, int key)
//{
//	
//	while (l <=h)
//	{
//		int mid = l+(h - l) / 2;
//
//		if (key == arr.A[mid])
//		{
//			return mid;
//		}
//		if (key < arr.A[mid])
//		{
//			h = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//		
//		
//	}
//	return -1;
//
//}
//int RBinSearch(struct Arrays* arr, int l, int h, int key)
//{
//	int mid = 0;;
//	if (l <= h)
//	{
//		 mid = (h + l) / 2;
//		if (key == arr->A[mid])
//		{
//			return mid;
//		}
//		else if (key < arr->A[mid])
//		{
//			return RBinSearch(arr, l, mid - 1, key);
//		}
//		else
//		{
//			return RBinSearch(arr, mid + 1,h, key);
//		}
//	}
//	return -1;
//}
//int Get(struct Arrays arr, int index)
//{
//	if (index >= 0 && index < arr.length)
//	{
//		return arr.A[index];
//	}
//}
//void Set(struct Arrays* arr, int index, int x)
//{
//	if (index >= 0 && index < arr->length)
//	{
//		arr->A[index] = x;
//	}
//}
//int Max(struct Arrays arr)
//{
//	int max = arr.A[0];// vi s�tter max till f�rsta v�rdet i array
//	for (int i = 1; i < arr.length; i++) //sedan ireterar vi array
//	{
//		if (arr.A[i] > max)// om v�rdet i array st�re �n max g�r vi s� nedan
//		{
//			max = arr.A[i]; // om v�rdet �r st�rre sprar vi det i max s� loppar den s� tills den hittar den st�rsta v�rdet
//		}
//
//	}
//	return max;
//
//}
//int Min(struct Arrays arr)
//{
//	int min = arr.A[0];// vi s�tter min till f�rsta v�rdet i array
//	for (int i = 0; i < arr.length; i++) //sedan ireterar vi array
//	{
//		if (arr.A[i] < min)// om v�rdet i array mindre �n min g�r vi s� nedan
//		{
//			min = arr.A[i]; // om v�rdet �r mindre sprar vi det i min s� loppar den s� tills den hittar den minsta v�rdet
//		}
//	}
//	return min;
//
//}
//int Sum(struct Arrays arr)
//{
//	int sum = 0;
//	for (int i = 0; i < arr.length; i++)
//	{
//		sum += arr.A[i];
//	}
//	return sum;
//}
//float avarage(struct Arrays arr)
//{
//	float avg = 0;
//	for (int i = 0; i < arr.length; i++)
//	{
//		avg += arr.A[i];
//
//	}
//	return avg / arr.length;
//
//	//return (float)sum(arr)/arr.length;
//}
//void Reverse1(struct  Arrays* arr) // denna metoden g�r vi reverse med h�hlp av swap och pointer  i heap
//{
//
//	for (int i = 0; i < arr->length; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			swap(&arr->A[i], &arr->A[j]);
//		}
//	}
//}
//void Reverse2(struct Arrays* arr)
//{
//	int* rev;
//	rev = (int*)malloc(arr->length * sizeof(int));//s� h�r resverar vi en m�ngd plts i minnet genom att skriva malloc och vilken typ av variable och antal.
//	for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
//	{
//		rev[j] = arr->A[i];
//	}
//	for (int i = 0; i < arr->length; i++)
//	{
//		arr->A[i] = rev[i];
//	}
//}
//int isSorted(struct Arrays arr)
//{
//	for (int i = 0; i < arr.length - 1; i++)
//	{
//		if (arr.A[i] > arr.A[i + 1])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//void insertionSort(int arr[], int n)
//{
//	int i, key, j;
//	for (i = 1; i < n; i++) {
//		key = arr[i];
//		j = i - 1;
//
//		/* Move elements of arr[0..i-1], that are
//		  greater than key, to one position ahead
//		  of their current position */
//		while (j >= 0 && arr[j] > key) {
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = key;
//	}
//}
//int main()
//{
//	//StDyarray();
//	//array2D();
//
//	/*Array arr(10);
//	arr.create();
//	arr.display();*/
//
//	struct Arrays arr1 = {{12,6,3,60,7},10,5 }; //
//	//Append(&arr1, 12);
//	//Ersatt(&arr1, 0, 10);
//	//tDisplay(arr1);
//	//Delete(&arr1, 0);
//	//tDisplay(arr1);
//
//	//int index = Linearsearch(&arr1, 3);// index vi skickar och vi tar emot sparas i index s� att vi g�r en vilkor nedan om vi hittar eller inte 
//	//if (index == -1)
//	//	printf("Element not found\n");
//	//else
//	//	printf("Element you search for are in index: %d\n", index);
//
//	//int key = LinearsearchSwap(&arr1, 3);
//	//if (key == -1)
//	//	printf("Element not found\n");
//	//else
//	//	printf("Element you search for are in index: %d\n", key); //search med swap
//
//
//	/*int Bkey = BinarySearch(arr1,0,arr1.length-1, 12);
//	if (Bkey == -1)
//		printf("Element not found\n");
//	else
//		printf("Element you search for are in index: %d\n", Bkey);*/
//
//	
//	//int Rkey = RBinSearch(arr1.A, 0, arr1.length, 12);
//	//if (Rkey == -1)
//	//	printf("Element not found\n");
//	//else
//		printf("Element you search for are in index: %d\n", RBinSearch(&arr1, 0,arr1.length, 12));
//		tDisplay(arr1);
//
//	printf("sum: %d\n", Sum(arr1));
//	printf("Max: %d\n", Max(arr1));
//	printf("Min: %d\n", Min(arr1));
//	printf("avg: %2f\n", avarage(arr1));
//	Reverse1(&arr1);
//	tDisplay(arr1);
//	Reverse2(&arr1);
//	tDisplay(arr1);
//
//	int sort = isSorted(arr1);
//	if (sort == 1)
//		printf("Elements is sorted\n");
//	else
//		printf("Elements is not sorted\n");
//
//
//	insertionSort(arr1.A, arr1.length);
//	tDisplay(arr1);
//	
//	
//
//
//}


