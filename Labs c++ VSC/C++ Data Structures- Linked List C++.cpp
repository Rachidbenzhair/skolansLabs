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
	Node* head; // head pointer är den viktigaste delen då den pikar på första Node

	Linkedlist()
	{
		head = NULL; // här säger vi att head är null då är list är tömm just nu 
	}
	bool isempty() //här kontrollerar om list är tömm genom att return falsk eller sant 
	{
		return (head == NULL);
	}
	void Insert(int newvalue)// metoden för att lägga till en node i början
	{
		Node* newnode = new Node(); //vi skappar ny node
		newnode->data = newvalue;// vi lägger data i ny node

		if (isempty()) //vi kontrollerar om listan är tömm gör vi så 
		{
			newnode->next = NULL; //den nya node får vara NULL
			head = newnode;  //head få peka på nya node
		}
		else //annars
		{
			newnode->next = head; //pointer i nya node next blir head
			head = newnode;  //head få peka på nya node

		}

	}
	void display() // printa metoden och vi behöver göra travers som gör att vi gårt från node till node i listan
	{
		Node* temp = head;// vi skappar en ny temp node så att vi inte förlörar head
		cout << "{ ";
		while (temp != NULL)// vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till nästa node
		}
		cout << " }" << endl;;
		cout << endl;
	}
	void Delete(int item) //kommand för att ta bort items med dess node
	{

		if (isempty())
			cout << "List is empty , no items to delete \n";
		Node* delptr = head;
		if (head->data == item)  //om den item vi ska ta bort lägger först som head då vi måste utföra detta kommnad
		{

			head = head->next;
			delete delptr;
		}
		else
		{
			Node* prev = NULL; //skappar vi en andra node som ska varea lika med null 
			delptr = head; //första node ska vara lika med head
			while (delptr->data != item) //vilkor om temp node vi skappade ska intew vara lika med det item vi ska ta bort annars stannar loopen
			{
				prev = delptr; //andra node ska vara lika med första node så att den tar pltsen och följer efter den
				delptr = delptr->next; // första node kommer göra traversing tills villkoret möts
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}
	int count() //metoden som övan använder traversing som går genom alla items från början till slut så att vi räknar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan lägga i en value  0 till o börja med
		Node* temp = head;// vi skappar en ny temp node så att vi inte förlörar head
		while (temp != NULL) // vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			counter++; //höj count med ett varje gång temp går till nästa node
			temp = temp->next;// och flytta till nästa node
		}
		return counter; // här skickar vi resultat när loopen är klar
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