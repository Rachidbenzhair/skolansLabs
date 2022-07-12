#include <iostream>
using namespace std;

class Node  //en class för just node man kan använda struct node i nedre class oxå om man vill
{
public:
	int data;
	Node* next;
	Node() //constructur
	{
		data = 0;// intierar data med 0
		next = NULL;
	}
};

class Stack
{
	Node* top;
public:
	Stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		return (top == NULL);
	}
	bool isFull()
	{
		Node* ptr = new Node();
		if (ptr == NULL)
			cout << "The Stack is Full , cannot add more items \n";
	}
	void push(int item) //push metod för att göra insert av items i stack(härr använder vi linked list)
	{
		Node* newnode = new Node(); // create ny node 
		newnode->data = item; //vi lägger ny value (item) i ny node(data delen)

		if (isEmpty()) //vi kontorlerar om stack är töm
		{
			newnode->next = NULL;//är den töm lägger vi next som null då den är sist
			top = newnode;//samt pikar top på ny node
		}
		else
		{
			newnode->next = top; //om inte stack är töm gör att ny node pikar på top edter vi kör nu LIFO
			top = newnode; //top blir = med ny node 
		}
	}
	int pop() //pop är vi tabort första item som är top från listan
	{
		int value;
		Node* delptr = top; //extra pointer som pikar på första node (top)
		value = top->data; 
		top = top->next; //vi ändrar så att top pikar på next node framme 
		delete delptr; //när top pikar på nästa blir första node kvar i minnet däreför hade vi extra pointer som nu vi ta bort

		return value; //denna return kan användas om du vill att användaren vill veta vilket value vi tog bort då hade vi först sparat den i en variabel övan (value)
	}
	int Peek() // metod för att veta vad som finns i top inget annat
	{
		return top->data;
	}
	void display() // printa metoden och vi behöver göra travers som gör att vi går från node till node i listan
	{
		Node* temp = top; // vi skappar en ny temp node så att vi inte förlörar top
		while (temp != NULL) // vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till nästa node
		}
		cout << endl;
	}
	int  count() //metoden som övan använder traversing som går genom alla items från början till slut så att vi räknar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan lägga i en value  0 till o börja med
		Node* temp = top;// vi skappar en ny temp node så att vi inte förlörar top
		while (temp != NULL) // vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			counter++; //höj count med ett varje gång temp går till nästa node
			temp = temp->next;// och flytta till nästa node
		}
		return counter; // här skickar vi resultat när loopen är klar
	}
	bool isfound(int item) // metod för att hitta en key och söka genom hela list vi använder traversing metod som övan
	{
		bool found = false; //bool varjbel vi börjar med false
		Node* temp = top;// vi skappar en ny temp node så att vi inte förlorar top
		while (temp != NULL)// vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			if (temp->data == item)// vilkor om vi hittar key när vi jämför data som temp står vid
				found = true; // om vi hittar det så found blir true
			temp = temp->next;// och flytta till nästa node
		}
		return found;// här skickar vi resultat när loopen är klar

	}

};


//int main()
//{
//	int item;
//	Stack s;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Enter Item to push \n";
//		cin >> item;
//		s.push(item);
//		s.display();
//	}
//
//	cout << s.pop() << " was deleted from stack \n";
//	s.display();
//	
//	cout << "Peek is: " << s.Peek() << endl;
//
//
//	cout << "Enter Item to search for \n";
//	cin >> item;
//
//	if (s.isfound(item))
//		cout << "Item Is Found \n";
//	else
//		cout << "Item Not found \n";
//	cout <<"Antal items: " << s.count() << endl;
//
//}