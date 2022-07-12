#include<iostream>
#include<stack>

using namespace std;

class Node
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

class Queue //en metod som g�r att vi l�gger fr�n back sida rear och tabort items fr�n fram sida front (som en K� system)
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL; // intierar b�da noder med null
	}

	bool isEmpty()
	{
		if (front == NULL)//&& rear == NULL) //vi kan anv�nda b�da eller bara front eftersom det �nd� t�m om den �r null
			return true;
		else
			return false;

	}

	void Enqueue(int item) //metod som g�r att vi l�gger till ny items men h�r islutet d�
	{
		Node* newnode = new Node(); //f�rst beh�ver skaffa ny node
		newnode->data = item; //vi l�gger data vi tog emot (item)

		if (isEmpty())
			front = rear = newnode; //om listan �r t�m g�r vi s� att nya node har b�da front och rear eftersom det enda node vi har
		else
		{
			rear->next = newnode;  //h�r pekar (rear next) d� den var i sista node innan nu ska den peka p� nya node som l�ggs i slutet
			rear = newnode; // ny node blir rear
		}
	}
	void display() // printa metoden och vi beh�ver g�ra travers som g�r att vi g�rt fr�n node till node i listan
	{
		if (isEmpty())
			cout << "Queue is Empty, no items to display \n";
		else
		{
			Node* temp = front; // vi skappar en ny temp node s� att vi inte f�rl�rar top
			while (temp != NULL) // vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
			{
				cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
				temp = temp->next; // och flytta till n�sta node
			}
			cout << endl;
		}
	}

	int  count() //metoden som �van anv�nder traversing som g�r genom alla items fr�n b�rjan till slut s� att vi r�knar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan l�gga i en value  0 till o b�rja med
		Node* temp = front;// vi skappar en ny temp node s� att vi inte f�rlorar front
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
		Node* temp = front;// vi skappar en ny temp node s� att vi inte f�rl�rar front
		while (temp != NULL)// vilkor med wihle loop som stannar n�r temp �r lika med null(h�r skriver vi medan temp �r not null s� k�r loopen)
		{
			if (temp->data == item)// vilkor om vi hittar key n�r vi j�mf�r data som temp st�r vid
				found = true; // om vi hittar det s� found blir true
			temp = temp->next;// och flytta till n�sta node
		}
		return found;// h�r skickar vi resultat n�r loopen �r klar

	}

	int Dequeue() //metod f�r att ta bort node fr�n listan och vi ta bort front h�r har vi 3 alternative
	{
		int delvalue = -1;
		if (isEmpty()) //om den �r t�m
			cout << "The queue is empty \n";

		else if (front == rear) //om den har bara en node
		{
			delete front;
			front = rear = NULL;
		}
		else // om finns flera item i listan
		{
			Node* delptr = front; //vi skappar en node som �r lika med front
			front = front->next; // vi g�r s� att front pikar p� n�sta node
			delvalue = delptr->data; //denna momunt �r optional om du vill spara data som ska bort f�r logg eller print
			delete delptr; //vi ta bort den tewmp pointer som vfi skappade
		}

		return delvalue;
	}

	int getFront() //metod vi f� kolla vilken data finns i front
	{
		return front->data;
	}

	int getRear() // som �van
	{
		return rear->data;
	}

	void  Clear()  //radera alla noder 
	{
		while (!isEmpty())
		{
			Dequeue();
		}
	}
};

//
//int main()
//{
//	Queue q;
//	for (int i = 1; i <= 3; i++)
//	{
//		int item;
//		cout << "Enter Item to Enqueue \n";
//		cin >> item;
//		q.Enqueue(item);
//	}
//	q.display();
//
//	int item;
//	cout << "Enter Item to search for \n";
//	cin >> item;
//
//	if (q.isfound(item))
//		cout << "Is Found \n";
//	else
//		cout << "Not found \n";
//	cout << q.count() << endl;
//
//	q.Dequeue();
//	cout << "After deque \n";
//	q.display();
//
//
//	cout << "Clear All items \n";
//	q.Clear();
//	cout << "Display after clear \n";
//	q.display();
//
//
//
//}
