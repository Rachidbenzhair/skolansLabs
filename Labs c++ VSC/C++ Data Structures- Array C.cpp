#include <stdio.h>
#include<stdlib.h>

struct Array
{
	int* A;
	int size;
	int length = 0;

};

void Fill(struct Array* arr) //Metod för att fylla på array med user command
{
	int no_of_items; // antal item

	printf("How many items you want to fill(length)? \n");//info till user att fylla i
	scanf("%d", &no_of_items); // input from user

	if (no_of_items > arr->size) // ett vilkor som kollar om antal item som user vill fylla på stämmer med size of array
	{
		printf("You cannot exceed the array size \n");
	}
	else
	{
		for (int i = 0; i < no_of_items; i++) // loop som loopar för user att fylla på items samt använda has tidigare input för att räkna  ner samt fylla i det som angets tidigare
		{
			printf("Enter item no %d: ", i + 1);
			scanf("%d", &arr->A[i]);
			arr->length++;			// här måste vi plussa på så att vi vet antal items vi har i array 
		}
	}


}
void display(struct Array arr)
{

	printf("Element are: ");
	printf("{ ");
	for (int i = 0; i < arr.length; i++)
	{

		printf("%d ", arr.A[i]);

	}
	printf("}\n");
	printf("\n");

}
void append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}
void insert(struct Array* arr, int index, int x)
{
	if (index >= 0 && index <= arr->length)
	{

		for (int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->length++;
	}
	else
	{
		printf("Error - Index out of Range \n"); //fel index från user
	}

}
int Delete(struct Array* arr, int index)
{

	if (index >= 0 && index < arr->size)

	{
		for (int i = index; i < arr->length - 1; i++)
		{

			arr->A[i] = arr->A[i + 1];

		}
		arr->length--;
	}
	return index;
}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int LenearSearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[i]);
			return i;
		}
	}
	return -1;
}
int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;
	while (1 <= h)
	{
		mid = (1 + h) / 2;
		if (key == arr.A[mid])
		{
			return mid;
		}
		else if (key < arr.A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}
int RBinSearch(int a[], int l, int h, int key)
{

	int mid;

	if (l <= h)
	{
		mid = (1 + h) / 2;
		if (key == a[mid])
		{
			return mid;

		}
		else if (key < a[mid])
		{
			return RBinSearch(a, l, mid - 1, key);

		}
		else
		{
			return RBinSearch(a, mid + 1, h, key);

		}

	}

	return -1;
}
int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
}
int Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		return arr->A[index] = x;
	}

}
int Max(struct Array arr)
{
	int max = arr.A[0];
	for (int i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}
int Min(struct Array arr)
{
	int min = arr.A[0];
	for (int i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}
int Sum(struct Array arr)
{
	int s = 0;
	for (int i = 0; i < arr.length; i++)
	{
		s += arr.A[i];
	}
	return s;
}
float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}
void Reverse1(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		swap(&arr->A[i], &arr->A[j]);
}
void Reverse2(struct Array* arr)
{
	int* B;
	int i, j;
	B = (int*)malloc(arr->length * sizeof(int));

	for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}
	for (i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}
void InsertSort(struct Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;
	while (i >= 0 && arr->A[i] > x) {
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}
void ReArrange(struct Array* arr)
{
	//int temp;
	for (int j = 0; j < arr->length; j++)
	{
		for (int i = 0; i < arr->length - 1; i++)
		{
			if (arr->A[i] > arr->A[i + 1])
			{
				/*temp = arr->A[i];
				arr->A[i] = arr->A[i + 1];
				arr->A[i + 1] = temp;*/
				swap(&arr->A[i], &arr->A[j]);
			}
		}
	}
}
void Merge(struct Array arr1, struct Array arr2)
{
	int i = 0, j = 0, k = 0;
	struct Array arr3;
	arr3.size = arr1.size + arr2.size;
	arr3.A = (int*)malloc(arr3.size * sizeof(int));

	while (i < arr1.length && j < arr2.length)
	{
		if (arr1.A[i] < arr2.A[j])
		{
			arr3.A[k++] = arr1.A[i++];
		}
		else
			arr3.A[k++] = arr2.A[j++];
	}
	for (; i < arr1.length; i++)
	{
		arr3.A[k++] = arr1.A[i];
	}

	for (; j < arr2.length; j++)
	{
		arr3.A[k++] = arr2.A[j];
	}
	arr3.length = k;
	printf("Merged Array: ");
	display(arr3);
}
void Difference(struct Array arr1, struct Array arr2)
{
	int i = 0, j = 0, k = 0;
	struct Array arr3;
	arr3.size = arr1.size + arr2.size;
	arr3.A = (int*)malloc(arr3.size * sizeof(int));

	while (i < arr1.length && j < arr2.length)
	{
		if (arr1.A[i] != arr2.A[j])
			arr3.A[k++] = arr1.A[i++];
		else if (arr2.A[j] < arr1.A[i])
			j++;
		else
		{
			i++;
			j++;
		}

	}
	for (; i < arr1.length; i++)
	{
		arr3.A[k++] = arr1.A[i];
	}
	arr3.length = k;
	printf("Difference on 2 arrays ");
	display(arr3);
}
void Intersection(struct Array arr1, struct Array arr2)
{
	int i = 0, j = 0, k = 0;
	struct Array arr3;
	arr3.size = arr1.size + arr2.size;
	arr3.A = (int*)malloc(arr3.size * sizeof(int));
	while (i < arr1.length && j < arr2.length)
	{
		if (arr1.A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < arr1.A[i])
			j++;
		else if (arr1.A[i] == arr2.A[j])
		{
			arr3.A[k++] = arr1.A[i++];
			j++;
		}

	}
	arr3.length = k;
	printf("Intersectionon on 2 arrays ");
	display(arr3);
}

int Menu(struct Array arr1)
{
	struct Array arr2;
	int userinput1 = 0;
	int userinput2 = 0;
	int userinput3 = 0;
	printf("\nMenu\n");
	printf("1: Append: \n");
	printf("2: Insert: \n");
	printf("3: Delete: \n");
	printf("4: Get: \n");
	printf("5: Set: \n");
	printf("6: Max: \n");
	printf("7: Min: \n");
	printf("8: Sum: \n");
	printf("9: Avg: \n");
	printf("10: Reverse1: \n");
	printf("11: Reverse2: \n");
	printf("12: InsertSort: \n");
	printf("13: ReArrange: \n");
	printf("14: Merge: \n");
	printf("15: Diff: \n");
	printf("16: Inter: \n");
	printf("17: LinearSearch: \n");
	printf("18: BinarySearch: \n");
	
	printf("***********************\n");
	printf("Choose an option above: ");
	scanf("%d", &userinput1);
	printf("***********************\n");

	switch (userinput1)
	{
	case 1://Adderar ett element till sluten av vår array
		printf("Skriv Element: ");
		scanf("%d", &userinput1);
		append(&arr1, userinput1);
		display(arr1);
		Menu(arr1);
		break;
	case 2://Placerar in önskat element på efterfrågat index
		printf("Skriv index: ");
		scanf("%d", &userinput1);
		printf("Skriv Element: ");
		scanf("%d", &userinput2);
		insert(&arr1, userinput1, userinput2);
		display(arr1);
		Menu(arr1);
		break;
	case 3://Raderar efterfrågat index
		printf("Skriv index: ");
		scanf("%d", &userinput1);
		Delete(&arr1, userinput1);
		display(arr1);
		Menu(arr1);
		break;
	case 4://Hämta element av visst index
		printf("Skriv index: ");
		scanf("%d", &userinput1);
		printf("Element finns i index: %d\n", Get(arr1, userinput1));
		Menu(arr1);
		break;
	case 5://Sätt visst index till önskat element
		printf("Skriv index: ");
		scanf("%d", &userinput1);
		printf("Skriv Element: ");
		scanf("%d", &userinput2);
		Set(&arr1, userinput1, userinput2);
		display(arr1);
		Menu(arr1);
		break;
	case 6://Hämta största talet
		printf("Big number are: %d\n", Max(arr1));
		display(arr1);
		Menu(arr1);
		break;
	case 7://Hämta Minsta talet
		printf("Min number are: %d\n", Min(arr1));
		display(arr1);
		Menu(arr1);
		break;
	case 8://Hämta summa av  talen i array
		printf("Sum are: %d\n", Sum(arr1));
		display(arr1);
		Menu(arr1);
		break;
	case 9://Hämta avg av  talen i array
		printf("Avarage are: %f\n", Avg(arr1));
		display(arr1);
		Menu(arr1);
		break;
	case 10://Vänder på innehållet av vår array
		Reverse1(&arr1);
		display(arr1);
		Menu(arr1);
		break;
	case 11://Vänder på innehållet av vår array
		Reverse2(&arr1);
		display(arr1);
		Menu(arr1);
		break;
	case 12://Placerar in önskat element men behåller formatet sorted
		printf("Skriv Element: ");
		scanf("%d", &userinput1);
		InsertSort(&arr1, userinput1);
		display(arr1);
		Menu(arr1);
		break;
	case 13://Sortera arrayen om den inte redan är sorterad
		printf("Din Array sorterades: ");
		ReArrange(&arr1);
		display(arr1);
		Menu(arr1);
		break;
	case 14://Sätter ihop två arrays
		printf("size of Second Array: %d\n", arr2.size = 10);
		arr2.A = (int*)malloc(arr2.size * sizeof(int));// sättet att skaffa ny array  med C i Heap då säger vi reservera så här mkt i minnet av varjbler integer
		Fill(&arr2);
		printf("First Array: ");
		display(arr1);
		printf("Second Array: ");
		display(arr2);
		Merge(arr1, arr2);
		Menu(arr1);
		break;
	case 15://Finner talen som diffar mellan två arrays
		printf("size of Second Array: %d\n", arr2.size = 10);
		arr2.A = (int*)malloc(arr2.size * sizeof(int));// sättet att skaffa ny array  med C i Heap då säger vi reservera så här mkt i minnet av varjbler integer
		Fill(&arr2);
		printf("First Array: ");
		display(arr1);
		printf("Second Array: ");
		display(arr2);
		Difference(arr1, arr2);
		Menu(arr1);
		break;
	case 16://Finner talen som matchar emellan två arrays
		printf("size of Second Array: %d\n", arr2.size = 10);
		arr2.A = (int*)malloc(arr2.size * sizeof(int));// sättet att skaffa ny array  med C i Heap då säger vi reservera så här mkt i minnet av varjbler integer
		Fill(&arr2);
		printf("First Array: ");
		display(arr1);
		printf("Second Array: ");
		display(arr2);
		Intersection(arr1, arr2);
		Menu(arr1);
		break;

	case 17://LinearSearch - Sökfunktion att finna efterfrågat tal i arrayen
		printf("Skriv value: ");
		scanf("%d", &userinput1);
		printf("Element finns i index: %d\n", LenearSearch(&arr1, userinput1));
		display(arr1);
		Menu(arr1);
		break;
	case 18://Sökfunktion att finna efterfrågat tal i arrayen
		printf("Skriv value: ");
		scanf("%d", &userinput1);
		printf("Element finns i index: %d\n", RBinSearch(arr1.A, 0, arr1.length, userinput1));
		display(arr1);
		Menu(arr1);
		break;


	}


	return 0;
}


//int main()
//{
//	struct Array arr1;
//	printf("size of Array: %d\n", arr1.size = 10);
//	arr1.A = (int*)malloc(arr1.size * sizeof(int));// sättet att skaffa ny array  med C i Heap då säger vi reservera så här mkt i minnet av varjbler integer
//	Fill(&arr1);
//	display(arr1);
//	Menu(arr1);
//
//}
