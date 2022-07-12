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

	void InsertFirst(int newvalue)// metoden f�r att l�gga till en node i b�rjan
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
		while (temp != NULL)// vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till n�sta node
		}
		cout << endl;
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

	bool isfound(int key) // metod f�r att hitta en key och s�ka genom hela list vi anv�nder traversing metod som �van
	{
		bool found = false; //bool varjbel vi b�rjar med false
		Node* temp = head;// vi skappar en ny temp node s� att vi inte f�rl�rar head
		while (temp != NULL)// vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			if (temp->data == key)// vilkor om vi hittar key n�r vi j�mf�r data som temp st�r vid
				found = true; // om vi hittar det s� found blir true
			temp = temp->next;// och flytta till n�sta node
		}
		return found;// h�r skickar vi resultat n�r loopen �r klar

	}
	void insertbefore(int item, int newvalue) // metod f�r att g�ra insert innan en specifik items (plats) d�rf�r skickar vi med tv� value.
	{
		if (isempty())
			InsertFirst(newvalue); //om listan �r t�m g�r ensert first

		if (isfound(item)) //vi kollar om item finns 
		{
			Node* newnode = new Node(); //vi skappar en ny node
			newnode->data = newvalue; //nya noden m�ste vi s�ga till spara data i 
			Node* temp = head;//n�sta steg vi skapar en temp�rir head som ska anv�ndas f�r att g�ra traversing
			while (temp != NULL && temp->next->data != item)// vilkor n�r loopet ska stanna (att temp ska inte vara lika null samt att det ska inte vara lika det value vi s�ker efter s� att vi stannar innan det
			{
				temp = temp->next;
			}
			newnode->next = temp->next;//den nya node ska peka p� det temp pikar p� (next)
			temp->next = newnode;// och temp next ska peka p� nya node
		}
		else
		{
			cout << "Sorry , Item Not Found \n";
		}
	}
	void append(int newvalue) //metod f�r att l�gga till ny node i slutet
	{
		if (isempty())
			InsertFirst(newvalue); //om listan �r t�m g�r ensert first
		else
		{
		}
		Node* temp = head;//n�sta steg vi skapar en temp�rir head som ska anv�ndas f�r att g�ra traversing
		while (temp->next != NULL) // denna vilkor �r anurlunda �n traversiring d� m�ste denna temp stanna exact �ver node som next =null
		{
			temp = temp->next;
		}
		Node* newnode = new Node();//vi skappar en ny node
		newnode->data = newvalue;//nya noden m�ste vi s�ga till spara data i 
		temp->next = newnode; //vi s�ger till att node som temp st�r p� pikar p� nya node
		newnode->next = NULL;//och nya node blir null
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

};


//int main()
//{
//	Linkedlist lst;
//
//	if (lst.isempty())
//		cout << "The List is Empty \n";
//	else
//		cout << "The List contains " << lst.count() << endl;
//
//
//	int item;
//	int newvalue;
//
//	cout << "Enter Item to insert in the list \n";
//	cin >> item;
//	lst.InsertFirst(item);
//	lst.display();
//	cout << "Enter Item to insert in the list \n";
//	cin >> item;
//	lst.InsertFirst(item);
//	lst.display();
//	cout << "Enter Item to insert in the list \n";
//	cin >> item;
//	lst.InsertFirst(item);
//	lst.display();
//
//	cout << "The List contains " << lst.count() << endl;
//
//	cout << "Enter Item to search for \n";
//	cin >> item;
//	if (lst.isfound(item))
//		cout << "Item Found \n";
//	else
//		cout << "Item not Found \n";
//
//
//	cout << "Enter  item to insert before \n";
//	cin >> item;
//	cin >> newvalue;
//
//	lst.insertbefore(item, newvalue);
//	lst.append(newvalue);
//	lst.Delete(item);
//	lst.display();
//}