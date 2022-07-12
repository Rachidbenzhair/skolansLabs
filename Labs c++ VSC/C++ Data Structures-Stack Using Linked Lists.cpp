#include <iostream>
using namespace std;

class Node  //en class f�r just node man kan anv�nda struct node i nedre class ox� om man vill
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
	void push(int item) //push metod f�r att g�ra insert av items i stack(h�rr anv�nder vi linked list)
	{
		Node* newnode = new Node(); // create ny node 
		newnode->data = item; //vi l�gger ny value (item) i ny node(data delen)

		if (isEmpty()) //vi kontorlerar om stack �r t�m
		{
			newnode->next = NULL;//�r den t�m l�gger vi next som null d� den �r sist
			top = newnode;//samt pikar top p� ny node
		}
		else
		{
			newnode->next = top; //om inte stack �r t�m g�r att ny node pikar p� top edter vi k�r nu LIFO
			top = newnode; //top blir = med ny node 
		}
	}
	int pop() //pop �r vi tabort f�rsta item som �r top fr�n listan
	{
		int value;
		Node* delptr = top; //extra pointer som pikar p� f�rsta node (top)
		value = top->data; 
		top = top->next; //vi �ndrar s� att top pikar p� next node framme 
		delete delptr; //n�r top pikar p� n�sta blir f�rsta node kvar i minnet d�ref�r hade vi extra pointer som nu vi ta bort

		return value; //denna return kan anv�ndas om du vill att anv�ndaren vill veta vilket value vi tog bort d� hade vi f�rst sparat den i en variabel �van (value)
	}
	int Peek() // metod f�r att veta vad som finns i top inget annat
	{
		return top->data;
	}
	void display() // printa metoden och vi beh�ver g�ra travers som g�r att vi g�r fr�n node till node i listan
	{
		Node* temp = top; // vi skappar en ny temp node s� att vi inte f�rl�rar top
		while (temp != NULL) // vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
			temp = temp->next; // och flytta till n�sta node
		}
		cout << endl;
	}
	int  count() //metoden som �van anv�nder traversing som g�r genom alla items fr�n b�rjan till slut s� att vi r�knar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan l�gga i en value  0 till o b�rja med
		Node* temp = top;// vi skappar en ny temp node s� att vi inte f�rl�rar top
		while (temp != NULL) // vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			counter++; //h�j count med ett varje g�ng temp g�r till n�sta node
			temp = temp->next;// och flytta till n�sta node
		}
		return counter; // h�r skickar vi resultat n�r loopen �r klar
	}
	bool isfound(int item) // metod f�r att hitta en key och s�ka genom hela list vi anv�nder traversing metod som �van
	{
		bool found = false; //bool varjbel vi b�rjar med false
		Node* temp = top;// vi skappar en ny temp node s� att vi inte f�rlorar top
		while (temp != NULL)// vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			if (temp->data == item)// vilkor om vi hittar key n�r vi j�mf�r data som temp st�r vid
				found = true; // om vi hittar det s� found blir true
			temp = temp->next;// och flytta till n�sta node
		}
		return found;// h�r skickar vi resultat n�r loopen �r klar

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