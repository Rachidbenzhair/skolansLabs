#include <iostream>
using namespace std;

class Array
{
private:

	int size; // antal index vi kan låta den dynamik om vi ska ha den dynamik så behöver vi pointer som pikar på array som ligger i Heap och pointer lägger i stack
	int length; // antal items som finns i array 
	int* items; // vi behöver en pointer för att få access till array i heap
public:
	Array(int arrsize) // cunstractor här bygger vi ny tom object och här vi behöver en input som difenerar size
	{
		size = arrsize;  //size som vi bygger är lika med den input vi tog emot
		length = 0; // vi börjar med 0 eftersom array är tom just nu
		items = new int[arrsize]; // Pointer när vi använder (new) vi reserver plats i heap Dynamik Array med size som vi tog emot
	}
	void Fill() //Metod för att fylla på array med user command
	{
		int no_of_items; // antal item
		cout << "How many items you want to fill ? \n";
		cin >> no_of_items; // input from user
		if (no_of_items > size) // ett vilkor som kollar om antal item som user vill fylla på stämmer med size of array
		{
			cout << "You cannot exceed the array size \n";
			return;
		}
		else
		{
			for (int i = 0; i < no_of_items; i++) // loop som loopar för user att fylla på items samt använda has tidigare input för att räkna  ner samt fylla i det som angets tidigare
			{
				cout << "Enter item no " << i << endl;
				cin >> items[i];
				length++; // här måste vi plussa på så att vi vet antal items vi har i array 

			}
		}
	}
	void Display()
	{
		cout << "Display Array content \n";
		for (int i = 0; i < length; i++) // for loop för att gå genom array och skriva ut antal items därför använder vi length och inte size eftersom några size kan vara tomma ex (size 10 men fyllda items (length är bara 5)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	int getSize() //metod som ger oss stroleken på array
	{
		return size;
	}
	int getLength()//metod som ger oss antal items i Array
	{
		return length;
	}
	int Search(int key) //metod (linjär Search) som hjälper oss att söka genom array på det vi söker efter
	{
		int index = -1; //vi intierar med -1 (om vi inte hittar sökt key skickar vi -1 eftersom array  index börjar med 0
		for (int i = 0; i < length; i++)
		{
			if (items[i] == key) // jämföra key med items 
			{
				index = i; // om vi hittar items sparar vi det i index
				break; // om vi hittar items sparar vi det i index
			}

		}
		return index; // skicka värdet som vi hittar eller -1
	}
	void Append(int newitem) // Append när vi lägger items i slutet av Array 
	{
		if (length < size) // vi måste först veta om array är full eller finns lediga platser 
		{
			items[length] = newitem; // här lägger vi islutet items of length den nya items
			length++; // samt höjer vi length efter nya items 
		}
		else // om length = size
			cout << "Array is full \n";
	}
	void Insert(int index, int newitem) // metoden som häjlper oss att vi själva bestämmer vart i array kan vi lägga vår items( val av index)
	{
		if (index >= 0 && index < size) // vi måste först göra valdation på users input så vi inte få problem så att index vi får inte stiger size och att det finns plats ledigt
		{
			for (int i = length; i > index; i--) // först vi måste flytta items till höger för att få index platsen ledig därför användev loop samt vi räknar ner åt från length som är sista postion till den index vi vill fylla i (i--)
			{
				items[i] = items[i - 1]; //varje gång vi flyttar oss ner åt (till vinster) så lägger vi items ett steg fram till höger och vi flyttar length ett steg till vinster med -1
			}
			items[index] = newitem; //när length (i) är större än index vi fått från user stnnar vi och lägger vi newitems.
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
				items[i] = items[i + 1]; // här säger vi till att indexet som loopar här är lika med indexet plus ett för i delete vi går till höger tvärtom insert
			length--; // vi minskar length med en eftersom vi tog bort en index från array
		}
		else
			cout << "Index out of Array Range \n"; // om index utanför range
	}
	void Enlarge(int newsize) //eftersom vi inte kan ändra size på arayy med denna metod skappar vi en ny array med ny size sedan flyttar vi alla items till den nya och radera den gamla
	{
		if (newsize <= size) // vi shekar av att nya size är större än den gamla
		{
			cout << "New size must be larger than current size \n";
			return;
		}
		else
		{
			size = newsize;
			int* old = items; // först vi måste skappa en pointer som ska pika på item den gamla array när vi ska kopiera till nya
			items = new int[newsize]; //skappar ny array
			for (int i = 0; i < length; i++) //forloop som kopierer items från gamla till den nya
			{
				items[i] = old[i];
			}
			delete[]old; //vi raderar gamla array när vi klara

		}
	}
	void Merge(Array other)//metod för att slå ihop mer än en array i en array (vi skickar med array som vi ska slå ihop med
	{
		int newsize = size + other.getSize(); //nya size som skappas av den gamla size samt den size av array vi tog emot som argument
		size = newsize; //den nya size blir nu size
		int* old = items; // vi skapar en pointer som ska pika på gamla array när vi skappar nya items
		items = new int[newsize];  //vi skappar nya array
		int i;
		for (i = 0; i < length; i++) // vi flyttar items med hjlp av pointer till den nya array
		{
			items[i] = old[i];
		}
		delete[]old;
		int j = i;
		for (int i = 0; i < other.getLength(); i++) // här måste vi flytta items från other array 
		{
			items[j++] = other.items[i]; //här ser vi till att vi lägger nya items där vi slutade tidigare därför har vi lagt ++
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
//	Array myarray(arraysize); // vi bygger en arrayt och skickar size från input på sorlekn av array
//	myarray.Fill(); // kalla på metod
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n"; // vi skriver ut antal items(length) samt size på array
//	myarray.Display(); // kalla på metod
//
// command for search
//	cout << "Enter the value to search for \n";
//	int key;
//	cin >> key;
//	int index = myarray.Search(key); // index vi skickar och vi tar emot sparas i index så att vi gör en vilkor nedan om vi hittar eller inte 
//	if (index == -1)
//		cout << "Item not found \n";
//	else
//		cout << "Item found @ position " << index << endl;
//
//
//	int newitem;
//	int index1;
//	//command för att lägga till ny items (i slutet)
//	cout << "Enter new item to add to the array \n"; //  när vi använder Append frågar vi user samt skickar vi det till metoden Append(newitem)
//	cin >> newitem;
//	myarray.Append(newitem); // kalla på metod
//	myarray.Display(); // kalla på metod
//
//
//
//	// command för insert
//	cout << "Enter Index to insert its item \n";
//	cin >> index1;
//	cin >> newitem;
//	myarray.Insert(index1, newitem);
//	cout << "Array size = " << myarray.getSize() << "   while length = " << myarray.getLength() << "\n";
//
//
//	//command för delete
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