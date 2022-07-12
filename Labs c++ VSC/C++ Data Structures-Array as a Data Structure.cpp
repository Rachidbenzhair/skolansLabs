#include <iostream>
using namespace std;

class Array
{
private:

	int size; // antal index vi kan l�ta den dynamik om vi ska ha den dynamik s� beh�ver vi pointer som pikar p� array som ligger i Heap och pointer l�gger i stack
	int length; // antal items som finns i array 
	int* items; // vi beh�ver en pointer f�r att f� access till array i heap
public:
	Array(int arrsize) // cunstractor h�r bygger vi ny tom object och h�r vi beh�ver en input som difenerar size
	{
		size = arrsize;  //size som vi bygger �r lika med den input vi tog emot
		length = 0; // vi b�rjar med 0 eftersom array �r tom just nu
		items = new int[arrsize]; // Pointer n�r vi anv�nder (new) vi reserver plats i heap Dynamik Array med size som vi tog emot
	}
	void Fill() //Metod f�r att fylla p� array med user command
	{
		int no_of_items; // antal item
		cout << "How many items you want to fill ? \n";
		cin >> no_of_items; // input from user
		if (no_of_items > size) // ett vilkor som kollar om antal item som user vill fylla p� st�mmer med size of array
		{
			cout << "You cannot exceed the array size \n";
			return;
		}
		else
		{
			for (int i = 0; i < no_of_items; i++) // loop som loopar f�r user att fylla p� items samt anv�nda has tidigare input f�r att r�kna  ner samt fylla i det som angets tidigare
			{
				cout << "Enter item no " << i << endl;
				cin >> items[i];
				length++; // h�r m�ste vi plussa p� s� att vi vet antal items vi har i array 

			}
		}
	}
	void Display()
	{
		cout << "Display Array content \n";
		for (int i = 0; i < length; i++) // for loop f�r att g� genom array och skriva ut antal items d�rf�r anv�nder vi length och inte size eftersom n�gra size kan vara tomma ex (size 10 men fyllda items (length �r bara 5)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	int getSize() //metod som ger oss stroleken p� array
	{
		return size;
	}
	int getLength()//metod som ger oss antal items i Array
	{
		return length;
	}
	int Search(int key) //metod (linj�r Search) som hj�lper oss att s�ka genom array p� det vi s�ker efter
	{
		int index = -1; //vi intierar med -1 (om vi inte hittar s�kt key skickar vi -1 eftersom array  index b�rjar med 0
		for (int i = 0; i < length; i++)
		{
			if (items[i] == key) // j�mf�ra key med items 
			{
				index = i; // om vi hittar items sparar vi det i index
				break; // om vi hittar items sparar vi det i index
			}

		}
		return index; // skicka v�rdet som vi hittar eller -1
	}
	void Append(int newitem) // Append n�r vi l�gger items i slutet av Array 
	{
		if (length < size) // vi m�ste f�rst veta om array �r full eller finns lediga platser 
		{
			items[length] = newitem; // h�r l�gger vi islutet items of length den nya items
			length++; // samt h�jer vi length efter nya items 
		}
		else // om length = size
			cout << "Array is full \n";
	}
	void Insert(int index, int newitem) // metoden som h�jlper oss att vi sj�lva best�mmer vart i array kan vi l�gga v�r items( val av index)
	{
		if (index >= 0 && index < size) // vi m�ste f�rst g�ra valdation p� users input s� vi inte f� problem s� att index vi f�r inte stiger size och att det finns plats ledigt
		{
			for (int i = length; i > index; i--) // f�rst vi m�ste flytta items till h�ger f�r att f� index platsen ledig d�rf�r anv�ndev loop samt vi r�knar ner �t fr�n length som �r sista postion till den index vi vill fylla i (i--)
			{
				items[i] = items[i - 1]; //varje g�ng vi flyttar oss ner �t (till vinster) s� l�gger vi items ett steg fram till h�ger och vi flyttar length ett steg till vinster med -1
			}
			items[index] = newitem; //n�r length (i) �r st�rre �n index vi f�tt fr�n user stnnar vi och l�gger vi newitems.
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
				items[i] = items[i + 1]; // h�r s�ger vi till att indexet som loopar h�r �r lika med indexet plus ett f�r i delete vi g�r till h�ger tv�rtom insert
			length--; // vi minskar length med en eftersom vi tog bort en index fr�n array
		}
		else
			cout << "Index out of Array Range \n"; // om index utanf�r range
	}
	void Enlarge(int newsize) //eftersom vi inte kan �ndra size p� arayy med denna metod skappar vi en ny array med ny size sedan flyttar vi alla items till den nya och radera den gamla
	{
		if (newsize <= size) // vi shekar av att nya size �r st�rre �n den gamla
		{
			cout << "New size must be larger than current size \n";
			return;
		}
		else
		{
			size = newsize;
			int* old = items; // f�rst vi m�ste skappa en pointer som ska pika p� item den gamla array n�r vi ska kopiera till nya
			items = new int[newsize]; //skappar ny array
			for (int i = 0; i < length; i++) //forloop som kopierer items fr�n gamla till den nya
			{
				items[i] = old[i];
			}
			delete[]old; //vi raderar gamla array n�r vi klara

		}
	}
	void Merge(Array other)//metod f�r att sl� ihop mer �n en array i en array (vi skickar med array som vi ska sl� ihop med
	{
		int newsize = size + other.getSize(); //nya size som skappas av den gamla size samt den size av array vi tog emot som argument
		size = newsize; //den nya size blir nu size
		int* old = items; // vi skapar en pointer som ska pika p� gamla array n�r vi skappar nya items
		items = new int[newsize];  //vi skappar nya array
		int i;
		for (i = 0; i < length; i++) // vi flyttar items med hjlp av pointer till den nya array
		{
			items[i] = old[i];
		}
		delete[]old;
		int j = i;
		for (int i = 0; i < other.getLength(); i++) // h�r m�ste vi flytta items fr�n other array 
		{
			items[j++] = other.items[i]; //h�r ser vi till att vi l�gger nya items d�r vi slutade tidigare d�rf�r har vi lagt ++
			length++;
		}

	}
};
//int main()
//{
//
//	cout << "Hello This is Array ADT demo\n";
//	int arraysize;
//	cout << "Enter the Array Size \n";
//	cin >> arraysize;
//
//	Array myarray(arraysize); // vi bygger en arrayt och skickar size fr�n input p� sorlekn av array
//	myarray.Fill(); // kalla p� metod
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n"; // vi skriver ut antal items(length) samt size p� array
//	myarray.Display(); // kalla p� metod
//
// command for search
//	cout << "Enter the value to search for \n";
//	int key;
//	cin >> key;
//	int index = myarray.Search(key); // index vi skickar och vi tar emot sparas i index s� att vi g�r en vilkor nedan om vi hittar eller inte 
//	if (index == -1)
//		cout << "Item not found \n";
//	else
//		cout << "Item found @ position " << index << endl;
//
//
//	int newitem;
//	int index1;
//	//command f�r att l�gga till ny items (i slutet)
//	cout << "Enter new item to add to the array \n"; //  n�r vi anv�nder Append fr�gar vi user samt skickar vi det till metoden Append(newitem)
//	cin >> newitem;
//	myarray.Append(newitem); // kalla p� metod
//	myarray.Display(); // kalla p� metod
//
//
//
//	// command f�r insert
//	cout << "Enter Index to insert its item \n";
//	cin >> index1;
//	cin >> newitem;
//	myarray.Insert(index1, newitem);
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
//
//
//	//command f�r delete
//	cout << "Enter Index to delete its item \n";
//	cin >> index1;
//	cin >> newitem;
//	myarray.Delete(index1);
//	myarray.Display();
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
//
//
//
//	//en large metod 
//	int newsize;
//	cout << "Enter New Size\n";
//	cin >> newsize;
//	myarray.Enlarge(newsize);
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
//	myarray.Display();
//
//
//	cout << "New array other \n";
//	Array other(3); //vi skappar ny array med size 3
//	other.Fill();// vi fyller array via denna metoden
//	myarray.Merge(other);
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
//	myarray.Display();
//}