//#include <stdio.h>
//#include<stdlib.h>
//struct Array
//{
//	int* A;
//	int size;
//	int length;
//};
//void Display(struct Array arr)
//{
//	int i;
//	printf("\nElements are\n");
//	for (i = 0; i < arr.length; i++)
//		printf("%d ", arr.A[i]);
//}
//void Append(struct Array* arr, int x)
//{
//	if (arr->length < arr->size)
//		arr->A[arr->length++] = x;
//}
//void Insert(struct Array* arr, int index, int x)
//{
//	int i;
//	if (index >= 0 && index <= arr->length)
//	{
//		for (i = arr->length; i > index; i--)
//			arr->A[i] = arr->A[i - 1];
//		arr->A[index] = x;
//		arr->length++;
//	}
//}
//int Delete(struct Array* arr, int index)
//{
//	int x = 0;
//	int i;
//	if (index >= 0 && index < arr->length)
//	{
//		x = arr->A[index];
//		for (i = index; i < arr->length - 1; i++)
//			arr->A[i] = arr->A[i + 1];
//		arr->length--;
//		return x;
//	}
//	return 0;
//}
//void swap(int* x, int* y)
//{
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int LinearSearch(struct Array* arr, int key)
//{
//	int i;
//	for (i = 0; i < arr->length; i++)
//	{
//		if (key == arr->A[i])
//		{
//			swap(&arr->A[i], &arr->A[0]);
//			return i;
//		}
//	}
//	return -1;
//}
//int BinarySearch(struct Array arr, int key)
//{
//	int l, mid, h;
//	l = 0;
//	h = arr.length - 1;
//	while (l <= h)
//	{
//		mid = (l + h) / 2;
//		if (key == arr.A[mid])
//			return mid;
//		else if (key < arr.A[mid])
//			h = mid - 1;
//		else
//			l = mid + 1;
//	}
//	return -1;
//}
//int RBinSearch(int a[], int l, int h, int key)
//{
//	int mid;
//	if (l <= h)
//	{
//		mid = (l + h) / 2;
//		if (key == a[mid])
//			return mid;
//		else if (key < a[mid])
//			return RBinSearch(a, l, mid - 1, key);
//		else
//			return RBinSearch(a, mid + 1, h, key);
//	}
//	return -1;
//}
//int main()
//{
//	struct Array arr1;
//	int ch;
//	int x, index;
//	printf("Enter Size of Array");
//	scanf("%d", &arr1.size);
//	arr1.A = (int*)malloc(arr1.size * sizeof(int));
//	arr1.length = 0;
//	do
//	{
//		printf("\n\nMenu\n");
//		printf("1. Insert\n");
//		printf("2. Delete\n");
//		printf("3. Search\n");
//		printf("5. Display\n");
//		printf("6.Exit\n");
//		printf("enter you choice ");
//		scanf("%d", &ch);
//		switch (ch)
//		{
//		case 1: printf("Enter an element and index");
//			scanf("%d%d", &x, &index);
//			Insert(&arr1, index, x);
//			break;
//		case 2: printf("Enter index ");
//			scanf("%d", &index);
//			x = Delete(&arr1, index);
//			printf("Deleted Element is %d\n", x);
//			break;
//		case 3:printf("Enter element to search ");
//			scanf("%d", &x);
//			index = LinearSearch(&arr1, x);
//			printf("Element index %d", index);
//			break;
//		case 5:Display(arr1);
//		}
//	} while (ch < 6);
//	return 0;
//}