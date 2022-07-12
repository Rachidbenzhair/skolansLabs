#include <iostream>
using namespace std;

class Node   //VI SKAPAR EN CLASS node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class Linkedlist
{
public:
	Node* head; // head pointer �r den viktigaste delen d� den pikar p� f�rsta Node

	Linkedlist()
	{
		head = NULL; // h�r s�ger vi att head �r null d� �r list �r t�mm just nu 
	}
	bool isempty() //h�r kontrollerar om list �r t�mm genom att return falsk eller sant 
	{
		return (head == NULL);
	}
	void Insert(int newvalue)// metoden f�r att l�gga till en node i b�rjan
	{
		Node* newnode = new Node(); //vi skappar ny node
		newnode->data = newvalue;// vi l�gger data i ny node

		if (isempty()) //vi kontrollerar om listan �r t�mm g�r vi s� 
		{
			newnode->next = NULL; //den nya node f�r vara NULL
			head = newnode;  //head f� peka p� nya node
		}
		else //annars
		{
			newnode->next = head; //pointer i nya node next blir head
			head = newnode;  //head f� peka p� nya node

		}

	}
	void display() // printa metoden och vi beh�ver g�ra travers som g�r att vi g�rt fr�n node till node i listan
	{
		Node* temp = head;// vi skappar en ny temp node s� att vi inte f�rl�rar head
		cout << "{ ";
		while (temp != NULL)// vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till n�sta node
		}
		cout << " }" << endl;;
		cout << endl;
	}
	void Delete(int item) //kommand f�r att ta bort items med dess node
	{

		if (isempty())
			cout << "List is empty , no items to delete \n";
		Node* delptr = head;
		if (head->data == item)  //om den item vi ska ta bort l�gger f�rst som head d� vi m�ste utf�ra detta kommnad
		{

			head = head->next;
			delete delptr;
		}
		else
		{
			Node* prev = NULL; //skappar vi en andra node som ska varea lika med null 
			delptr = head; //f�rsta node ska vara lika med head
			while (delptr->data != item) //vilkor om temp node vi skappade ska intew vara lika med det item vi ska ta bort annars stannar loopen
			{
				prev = delptr; //andra node ska vara lika med f�rsta node s� att den tar pltsen och f�ljer efter den
				delptr = delptr->next; // f�rsta node kommer g�ra traversing tills villkoret m�ts
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}
	int count() //metoden som �van anv�nder traversing som g�r genom alla items fr�n b�rjan till slut s� att vi r�knar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan l�gga i en value  0 till o b�rja med
		Node* temp = head;// vi skappar en ny temp node s� att vi inte f�rl�rar head
		while (temp != NULL) // vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			counter++; //h�j count med ett varje g�ng temp g�r till n�sta node
			temp = temp->next;// och flytta till n�sta node
		}
		return counter; // h�r skickar vi resultat n�r loopen �r klar
	}

	void Menu()
	{
		int item;
		int userinput;

		cout << "Menu" << endl;
		cout << "******" << endl;
		cout << "1: Insert: " << endl;
		cout << "2: Display: " << endl;
		cout << "3: Delete: " << endl;
		cout << "4: GetLength: " << endl;
		cout << "********************" << endl;
		cout << "Choose an option above: ";
		cin >> userinput;
		cout << "********************" << endl;

		switch (userinput)
		{

		case 1:
			cout << "How many items you want to fill: ";
			cin >> userinput;
			for (int i = 0; i < userinput; i++)
			{
				cout << "Enter Item: " << i + 1 << " : ";
				cin >> item;
				Insert(item);
			}
			display();
			Menu();
			break;
		case 2:
			display();
			Menu();
				;
			break;
		case 3:
			cout << "Enter  item to Delete \n";
			cin >> item;
			Delete(item);
			display();
			Menu();
			break;
		case 4:
			cout << "The List contains " << count() << endl;
			display();
			Menu();
			break;
		}
	}

};


//int main()
//{
//	Linkedlist lst;
//	lst.Menu();
//
//
//}