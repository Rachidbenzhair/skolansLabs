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
	void Fill() //Metod för att fylla på array med user command
	{
		int no_of_items; // antal item

		cout << "How many items you want to fill(length)?" << endl; //info till user att fylla i
		cin >> no_of_items; // input from user

		if (no_of_items > size) // ett vilkor som kollar om antal item som user vill fylla på stämmer med size of array
		{
			cout << "You cannot exceed the array size" << endl;
		}
		else
		{
			for (int i = 0; i < no_of_items; i++) // loop som loopar för user att fylla på items samt använda has tidigare input för att räkna  ner samt fylla i det som angets tidigare
			{
				cout << "Enter item no: " << i + 1 << " : ";
				cin >> A[i];
				length++;			// här måste vi plussa på så att vi vet antal items vi har i array 
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
	void append(int newitem) // Append när vi lägger items i slutet av Array 
	{
		if (length < size) // vi måste först veta om array är full eller finns lediga platser 
		{
			A[length] = newitem; // här lägger vi islutet items of length den nya items
			length++; // samt höjer vi length efter nya items 
		}
		else // om length = size
			cout << "Array is full \n";
	}
	void insert(int index, int newitem) // metoden som häjlper oss att vi själva bestämmer vart i array kan vi lägga vår items( val av index)
	{
		if (index >= 0 && index < size) // vi måste först göra valdation på users input så vi inte få problem så att index vi får inte stiger size och att det finns plats ledigt
		{
			for (int i = length; i > index; i--) // först vi måste flytta items till höger för att få index platsen ledig därför användev loop samt vi räknar ner åt från length som är sista postion till den index vi vill fylla i (i--)
			{
				A[i] = A[i - 1]; //varje gång vi flyttar oss ner åt (till vinster) så lägger vi items ett steg fram till höger och vi flyttar length ett steg till vinster med -1
			}
			A[index] = newitem; //när length (i) är större än index vi fått från user stnnar vi och lägger vi newitems.
			length++;// samt höjer vi length med ett då nytt item har lagts till.
		}
		else
		{
			cout << " Error - Index out of Range \n"; //fel index från user
		}
	}
	void Delete(int index)
	{
		if (index >= 0 && index < size) //först vi chickar av indexet vi tar emot om den inom array range 
		{
			for (int i = index; i < length - 1; i++) // i är lika med index vi tog emot och indexet ska vara mindre än length då den ska stnna innan length
				A[i] = A[i + 1]; // här säger vi till att indexet som loopar här är lika med indexet plus ett för i delete vi går till höger tvärtom insert
			length--; // vi minskar length med en eftersom vi tog bort en index från array
		}
		else
			cout << "Index out of Array Range \n"; // om index utanför range
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
	int getSize() //metod som ger oss stroleken på array
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
	void Merge(Array arr2)//metod för att slå ihop mer än en array i en array (vi skickar med array som vi ska slå ihop med
	{
		int newsize = arr2.size + size; //nya size som skappas av den ga´mla size samt den size av array vi tog emot som argument
		size = newsize; //den nya size blir nu size
		int* old = A; // vi skapar en pointer som ska pika på gamla array när vi skappar nya items
		A = new int[newsize];  //vi skappar nya array
		int i;
		for (i = 0; i < length; i++) // vi flyttar items med hjlp av pointer till den nya array
		{
			A[i] = old[i];
		}
		delete[]old;
		int j = i;
		for (int i = 0; i < arr2.length; i++) // här måste vi flytta items från other array 
		{
			A[j++] = arr2.A[i]; //här ser vi till att vi lägger nya items där vi slutade tidigare därför har vi lagt ++
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
	case 1://Adderar ett element till sluten av vår array
		cout << "Skriv Element: ";
		cin >> userinput1;
		arr1.append(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 2://Placerar in önskat element på efterfrågat index
		cout << ("Skriv index: ");
		cin >> userinput1;
		cout << ("Skriv Element: ");
		cin >> userinput2;
		arr1.insert(userinput1, userinput2);
		arr1.display();
		Menu(arr1);
		break;
	case 3://Raderar efterfrågat index
		cout << ("Skriv index: ");
		cin >> userinput1;
		arr1.Delete(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 4://Hämta element av visst index
		cout << "Skriv index: ";
		cin >> userinput1;
		cout << "Element finns i index: " << arr1.Get(userinput1) << endl;
		Menu(arr1);
		break;
	case 5://Sätt visst index till önskat element
		cout << "Skriv index: ";
		cin >> userinput1;
		cout << "Skriv Element: ";
		cin >> userinput2;
		arr1.Set(userinput1, userinput2);
		arr1.display();
		Menu(arr1);
		break;
	case 6://Hämta största talet
		cout << "Big number are: " << arr1.Max() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 7://Hämta Minsta talet
		cout << "Min number are: " << arr1.Min() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 8://Hämta summa av  talen i array
		cout << "Sum are: " << arr1.Sum() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 9://Hämta avg av  talen i array
		cout << "Avarage are: " << arr1.Avg() << endl;
		arr1.display();
		Menu(arr1);
		break;
	case 10://Vänder på innehållet av vår array
		arr1.Reverse1();
		arr1.display();
		Menu(arr1);
		break;
	case 11://Vänder på innehållet av vår array
		arr1.Reverse2();
		arr1.display();
		Menu(arr1);
		break;
	case 12://Placerar in önskat element men behåller formatet sorted
		cout << "Skriv Element: ";
		cin >> userinput1;
		arr1.InsertSort(userinput1);
		arr1.display();
		Menu(arr1);
		break;
	case 13://Sortera arrayen om den inte redan är sorterad
		cout << "Din Array sorterades: ";
		arr1.ReArrange();
		arr1.display();
		Menu(arr1);
		break;
	case 14://Sätter ihop två arrays
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
	case 15://Finner talen som diffar mellan två arrays
		cout << "size of Second Array: " << 10 << endl;
		arr2.Fill();
		cout << "First Array: ";
		arr1.display();
		cout << "Second Array: ";
		arr2.display();
		arr1.Difference(arr2);
		Menu(arr1);
		break;
	case 16://Finner talen som matchar emellan två arrays
		cout << "size of Second Array: " << 10 << endl;
		arr2.Fill();
		cout << "First Array: ";
		arr1.display();
		cout << "Second Array: ";
		arr2.display();
		arr1.Intersection(arr2);
		Menu(arr1);
		break;

	case 17://LinearSearch - Sökfunktion att finna efterfrågat tal i arrayen
		cout << "Enter the value to search for \n";
		cin >> key;
		index = arr1.LenearSearch(key); // index vi skickar och vi tar emot sparas i index så att vi gör en vilkor nedan om vi hittar eller inte 
		if (index == -1)
			cout << "Item not found \n";
		else
			cout << "Item found @ position " << index << endl;
		Menu(arr1);
		break;
	case 18://Sökfunktion att finna efterfrågat tal i arrayen
		cout << "Enter the value to search for \n";
		cin >> key;
		int h = arr1.getLength();
		int index = arr1.binarySearch(&arr1, 0, h, key);
		// index vi skickar och vi tar emot sparas i index så att vi gör en vilkor nedan om vi hittar eller inte 
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
