#include <iostream>

using namespace std;

class Array
{
private:
	int* A;
	int size;
	int length;
public:
	Array(int arrSize)
	{
		size = arrSize;
		length = 0;
		A = new int[arrSize];
	}
	~Array()
	{
		delete[]A;
	}
	void Fill() //Metod f�r att fylla p� array med user command
	{
		int no_of_items; // antal item

		cout << "How many items you want to fill(length)?" << endl; //info till user att fylla i
		cin >> no_of_items; // input from user

		if (no_of_items > size) // ett vilkor som kollar om antal item som user vill fylla p� st�mmer med size of array
		{
			cout << "You cannot exceed the array size" << endl;
		}
		else
		{
			for (int i = 0; i < no_of_items; i++) // loop som loopar f�r user att fylla p� items samt anv�nda has tidigare input f�r att r�kna  ner samt fylla i det som angets tidigare
			{
				cout << "Enter item no: " << i + 1 << " : ";
				cin >> A[i];
				length++;			// h�r m�ste vi plussa p� s� att vi vet antal items vi har i array 
			}
		}


	}
	void display()
	{

		cout << "Elements are: ";
		cout << "{ ";
		for (int i = 0; i < length; i++)
		{

			cout << A[i] << " ";

		}
		cout << " }" << endl;;
		cout << endl;

	}
	void append(int newitem) // Append n�r vi l�gger items i slutet av Array 
	{
		if (length < size) // vi m�ste f�rst veta om array �r full eller finns lediga platser 
		{
			A[length] = newitem; // h�r l�gger vi islutet items of length den nya items
			length++; // samt h�jer vi length efter nya items 
		}
		else // om length = size
			cout << "Array is full \n";
	}
	void insert(int index, int newitem) // metoden som h�jlper oss att vi sj�lva best�mmer vart i array kan vi l�gga v�r items( val av index)
	{
		if (index >= 0 && index < size) // vi m�ste f�rst g�ra valdation p� users input s� vi inte f� problem s� att index vi f�r inte stiger size och att det finns plats ledigt
		{
			for (int i = length; i > index; i--) // f�rst vi m�ste flytta items till h�ger f�r att f� index platsen ledig d�rf�r anv�ndev loop samt vi r�knar ner �t fr�n length som �r sista postion till den index vi vill fylla i (i--)
			{
				A[i] = A[i - 1]; //varje g�ng vi flyttar oss ner �t (till vinster) s� l�gger vi items ett steg fram till h�ger och vi flyttar length ett steg till vinster med -1
			}
			A[index] = newitem; //n�r length (i) �r st�rre �n index vi f�tt fr�n user stnnar vi och l�gger vi newitems.
			length++;// samt h�jer vi length med ett d� nytt item har lagts till.
		}
		else
		{
			cout << " Error - Index out of Range \n"; //fel index fr�n user
		}
	}
	void Delete(int index)
	{
		if (index >= 0 && index < size) //f�rst vi chickar av indexet vi tar emot om den inom array range 
		{
			for (int i = index; i < length - 1; i++) // i �r lika med index vi tog emot och indexet ska vara mindre �n length d� den ska stnna innan length
				A[i] = A[i + 1]; // h�r s�ger vi till att indexet som loopar h�r �r lika med indexet plus ett f�r i delete vi g�r till h�ger tv�rtom insert
			length--; // vi minskar length med en eftersom vi tog bort en index fr�n array
		}
		else
			cout << "Index out of Array Range \n"; // om index utanf�r range
	}
	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	int LenearSearch(int key)
	{
		int i;
		for (i = 0; i < length; i++)
		{
			if (key == A[i])
			{
				swap(&A[i], &A[i]);
				return i;
			}
		}
		return -1;
	}
	int binarySearch(Array* arr, int l, int r, int x)
	{
		if (r >= l) {
			int mid = l + (r - l) / 2;
			if (A[mid] == x)
				return mid;
			if (A[mid] > x)
				return binarySearch(arr, l, mid - 1, x);
			return binarySearch(arr, mid + 1, r, x);
		}
		return -1;
	}
	int getSize() //metod som ger oss stroleken p� array
	{
		return size;
	}
	int getLength()//metod som ger oss antal items i Array
	{
		return length;
	}
	int Get(int index)
	{
		if (index >= 0 && index < length)
		{
			return A[index];
		}
	}
	int Set(int index, int x)
	{
		if (index >= 0 && index < length)
		{
			return A[index] = x;
		}

	}
	int Max()
	{
		int max = A[0];
		for (int i = 1; i < length; i++)
		{
			if (A[i] > max)
			{
				max = A[i];
			}
		}
		return max;
	}
	int Min()
	{
		int min = A[0];
		for (int i = 1; i < length; i++)
		{
			if (A[i] < min)
			{
				min = A[i];
			}
		}
		return min;
	}
	int Sum()
	{
		int s = 0;
		for (int i = 0; i < length; i++)
		{
			s += A[i];
		}
		return s;
	}
	float Avg()
	{
		return (float)Sum() / length;
	}
	void Reverse1()
	{
		int i, j;
		for (i = 0, j = length - 1; i < j; i++, j--)
			swap(&A[i], &A[j]);
	}
	void Reverse2()
	{
		int* B;
		int i, j;
		B = new int[size];

		for (int i = length - 1, j = 0; i >= 0; i--, j++)
		{
			B[j] = A[i];
		}
		for (i = 0; i < length; i++)
		{
			A[i] = B[i];
		}
	}
	void InsertSort(int x)
	{
		int i = length - 1;
		if (length == size)
			return;
		while (i >= 0 && A[i] > x)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = x;
		length++;
	}
	void ReArrange()
	{
		//int temp;
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i < length - 1; i++)
			{
				if (A[i] > A[i + 1])
				{
					/*temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;*/
					swap(&A[i], &A[j]);
				}
			}
		}
	}
	void Merge(Array arr2)//metod f�r att sl� ihop mer �n en array i en array (vi skickar med array som vi ska sl� ihop med
	{
		int newsize = arr2.size + size; //nya size som skappas av den ga�mla size samt den size av array vi tog emot som argument
		size = newsize; //den nya size blir nu size
		int* old = A; // vi skapar en pointer som ska pika p� gamla array n�r vi skappar nya items
		A = new int[newsize];  //vi skappar nya array
		int i;
		for (i = 0; i < length; i++) // vi flyttar items med hjlp av pointer till den nya array
		{
			A[i] = old[i];
		}
		delete[]old;
		int j = i;
		for (int i = 0; i < arr2.length; i++) // h�r m�ste vi flytta items fr�n other array 
		{
			A[j++] = arr2.A[i]; //h�r ser vi till att vi l�gger nya items d�r vi slutade tidigare d�rf�r har vi lagt ++
			length++;
		}

	}
	void Difference(Array arr2)
	{
		int i = 0, j = 0, k = 0;
		class Array arr3(size);
		arr3.A = new int[size];

		while (i < length && j < arr2.length)
		{
			if (A[i] != arr2.A[j])
				arr3.A[k++] = A[i++];
			else if (arr2.A[j] < A[i])
				j++;
			else
			{
				i++;
				j++;
			}

		}
		for (; i < length; i++)
		{
			arr3.A[k++] = A[i];
		}
		arr3.length = k;
		cout << "Difference on 2 arrays ";
		arr3.display();
	}
	void Intersection(Array arr2)
	{
		int i = 0, j = 0, k = 0;
		class Array arr3(size);
		arr3.size = size + arr2.size;
		arr3.A = new int[size];

		while (i < length && j < arr2.length)
		{
			if (A[i] < arr2.A[j])
				i++;
			else if (arr2.A[j] < A[i])
				j++;
			else if (A[i] == arr2.A[j])
			{
				arr3.A[k++] = A[i++];
				j++;
			}

		}
		arr3.length = k;
		cout << "Intersectionon on 2 arrays ";
		arr3.display();
	}
};

int Menu(Array arr1)
{
	class Array arr2(10);
	int userinput1 = 0;
	int userinput2 = 0;
	int userinput3 = 0;
	int index = 0;
	int key = 0;
	cout << "******" << endl;
	cout << "Menu" << endl;
	cout << "******" << endl;
	cout << "1: Append: " << endl;
	cout << "2: Insert: " << endl;
	cout << "3: Delete: " << endl;
	cout << "4: Get: " << endl;
	cout << "5: Set: " << endl;
	cout << "6: Max: " << endl;
	cout << "7: Min: " << endl;
	cout << "8: Sum: " << endl;
	cout << "9: Avg: " << endl;
	cout << "10: Reverse1: " << endl;
	cout << "11: Reverse2: " << endl;
	cout << "12: InsertSort: " << endl;
	cout << "13: ReArrange: " << endl;
	cout << "14: Merge: " << endl;
	cout << "15: Diff: " << endl;
	cout << "16: Inter: " << endl;
	cout << "17: LinearSearch: " << endl;
	cout << "18: BinarySearch: " << endl;
	cout << "***********************" << endl;
	cout << "Choose an option above: ";
	cin >> userinput1;
	cout << "***********************" << endl;

	switch (userinput1)
	{
	case 1://Adderar ett element till sluten av v�r array
		cout << "Skriv Element: ";
		cin >> userinput1;
		arr1.append(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 2://Placerar in �nskat element p� efterfr�gat index
		cout << ("Skriv index: ");
		cin >> userinput1;
		cout << ("Skriv Element: ");
		cin >> userinput2;
		arr1.insert(userinput1, userinput2);
		arr1.display();
		Menu(arr1);
		break;
	case 3://Raderar efterfr�gat index
		cout << ("Skriv index: ");
		cin >> userinput1;
		arr1.Delete(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 4://H�mta element av visst index
		cout << "Skriv index: ";
		cin >> userinput1;
		cout << "Element finns i index: " << arr1.Get(userinput1) << endl;
		Menu(arr1);
		break;
	case 5://S�tt visst index till �nskat element
		cout << "Skriv index: ";
		cin >> userinput1;
		cout << "Skriv Element: ";
		cin >> userinput2;
		arr1.Set(userinput1, userinput2);
		arr1.display();
		Menu(arr1);
		break;
	case 6://H�mta st�rsta talet
		cout << "Big number are: " << arr1.Max() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 7://H�mta Minsta talet
		cout << "Min number are: " << arr1.Min() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 8://H�mta summa av  talen i array
		cout << "Sum are: " << arr1.Sum() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 9://H�mta avg av  talen i array
		cout << "Avarage are: " << arr1.Avg() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 10://V�nder p� inneh�llet av v�r array
		arr1.Reverse1();
		arr1.display();
		Menu(arr1);
		break;
	case 11://V�nder p� inneh�llet av v�r array
		arr1.Reverse2();
		arr1.display();
		Menu(arr1);
		break;
	case 12://Placerar in �nskat element men beh�ller formatet sorted
		cout << "Skriv Element: ";
		cin >> userinput1;
		arr1.InsertSort(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 13://Sortera arrayen om den inte redan �r sorterad
		cout << "Din Array sorterades: ";
		arr1.ReArrange();
		arr1.display();
		Menu(arr1);
		break;
	case 14://S�tter ihop tv� arrays
		cout << "size of Second Array: " << 10 << endl;
		arr2.Fill();
		cout << "First Array: ";
		arr1.display();
		cout << "Second Array: ";
		arr2.display();
		arr1.Merge(arr2);
		arr1.display();
		Menu(arr1);
		break;
	case 15://Finner talen som diffar mellan tv� arrays
		cout << "size of Second Array: " << 10 << endl;
		arr2.Fill();
		cout << "First Array: ";
		arr1.display();
		cout << "Second Array: ";
		arr2.display();
		arr1.Difference(arr2);
		Menu(arr1);
		break;
	case 16://Finner talen som matchar emellan tv� arrays
		cout << "size of Second Array: " << 10 << endl;
		arr2.Fill();
		cout << "First Array: ";
		arr1.display();
		cout << "Second Array: ";
		arr2.display();
		arr1.Intersection(arr2);
		Menu(arr1);
		break;

	case 17://LinearSearch - S�kfunktion att finna efterfr�gat tal i arrayen
		cout << "Enter the value to search for \n";
		cin >> key;
		index = arr1.LenearSearch(key); // index vi skickar och vi tar emot sparas i index s� att vi g�r en vilkor nedan om vi hittar eller inte 
		if (index == -1)
			cout << "Item not found \n";
		else
			cout << "Item found @ position " << index << endl;
		Menu(arr1);
		break;
	case 18://S�kfunktion att finna efterfr�gat tal i arrayen
		cout << "Enter the value to search for \n";
		cin >> key;
		int h = arr1.getLength();
		int index = arr1.binarySearch(&arr1, 0, h, key);
		// index vi skickar och vi tar emot sparas i index s� att vi g�r en vilkor nedan om vi hittar eller inte 
		if (index == -1)
			cout << "Item not found \n";
		else
			cout << "Item found @ position " << index << endl;
		Menu(arr1);
		break;
	
	}


	return 0;
}

//int main()
//{
//	class Array arr1(10);
//	cout << "size of Array: " << 10 << endl;
//	arr1.Fill();
//	arr1.display();
//	Menu(arr1);
//
//}
