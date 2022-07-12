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

	void InsertFirst(int newvalue)// metoden för att lägga till en node i början
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
		while (temp != NULL)// vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till nästa node
		}
		cout << endl;
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

	bool isfound(int key) // metod för att hitta en key och söka genom hela list vi använder traversing metod som övan
	{
		bool found = false; //bool varjbel vi börjar med false
		Node* temp = head;// vi skappar en ny temp node så att vi inte förlörar head
		while (temp != NULL)// vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			if (temp->data == key)// vilkor om vi hittar key när vi jämför data som temp står vid
				found = true; // om vi hittar det så found blir true
			temp = temp->next;// och flytta till nästa node
		}
		return found;// här skickar vi resultat när loopen är klar

	}
	void insertbefore(int item, int newvalue) // metod för att göra insert innan en specifik items (plats) därför skickar vi med två value.
	{
		if (isempty())
			InsertFirst(newvalue); //om listan är töm gör ensert first

		if (isfound(item)) //vi kollar om item finns 
		{
			Node* newnode = new Node(); //vi skappar en ny node
			newnode->data = newvalue; //nya noden måste vi säga till spara data i 
			Node* temp = head;//nästa steg vi skapar en tempörir head som ska användas för att göra traversing
			while (temp != NULL && temp->next->data != item)// vilkor när loopet ska stanna (att temp ska inte vara lika null samt att det ska inte vara lika det value vi söker efter så att vi stannar innan det
			{
				temp = temp->next;
			}
			newnode->next = temp->next;//den nya node ska peka på det temp pikar på (next)
			temp->next = newnode;// och temp next ska peka på nya node
		}
		else
		{
			cout << "Sorry , Item Not Found \n";
		}
	}
	void append(int newvalue) //metod för att lägga till ny node i slutet
	{
		if (isempty())
			InsertFirst(newvalue); //om listan är töm gör ensert first
		else
		{
		}
		Node* temp = head;//nästa steg vi skapar en tempörir head som ska användas för att göra traversing
		while (temp->next != NULL) // denna vilkor är anurlunda än traversiring då måste denna temp stanna exact över node som next =null
		{
			temp = temp->next;
		}
		Node* newnode = new Node();//vi skappar en ny node
		newnode->data = newvalue;//nya noden måste vi säga till spara data i 
		temp->next = newnode; //vi säger till att node som temp står på pikar på nya node
		newnode->next = NULL;//och nya node blir null
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