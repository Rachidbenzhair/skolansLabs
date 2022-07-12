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

class Queue //en metod som gör att vi lägger från back sida rear och tabort items från fram sida front (som en Kö system)
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL; // intierar båda noder med null
	}

	bool isEmpty()
	{
		if (front == NULL)//&& rear == NULL) //vi kan använda båda eller bara front eftersom det ändå töm om den är null
			return true;
		else
			return false;

	}

	void Enqueue(int item) //metod som gör att vi lägger till ny items men här islutet då
	{
		Node* newnode = new Node(); //först behöver skaffa ny node
		newnode->data = item; //vi lägger data vi tog emot (item)

		if (isEmpty())
			front = rear = newnode; //om listan är töm gör vi så att nya node har båda front och rear eftersom det enda node vi har
		else
		{
			rear->next = newnode;  //här pekar (rear next) då den var i sista node innan nu ska den peka på nya node som läggs i slutet
			rear = newnode; // ny node blir rear
		}
	}
	void display() // printa metoden och vi behöver göra travers som gör att vi gårt från node till node i listan
	{
		if (isEmpty())
			cout << "Queue is Empty, no items to display \n";
		else
		{
			Node* temp = front; // vi skappar en ny temp node så att vi inte förlörar top
			while (temp != NULL) // vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
			{
				cout << temp->data << " "; //skriv detta vid varje node temp stannar vid
				temp = temp->next; // och flytta till nästa node
			}
			cout << endl;
		}
	}

	int  count() //metoden som övan använder traversing som går genom alla items från början till slut så att vi räknar antal node
	{
		int counter = 0; //vi deklarerar i variabel som vi kan lägga i en value  0 till o börja med
		Node* temp = front;// vi skappar en ny temp node så att vi inte förlorar front
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
		Node* temp = front;// vi skappar en ny temp node så att vi inte förlörar front
		while (temp != NULL)// vilkor med wihle loop som stannar när temp är lika med null(här skriver vi medan temp är not null så kör loopen)
		{
			if (temp->data == item)// vilkor om vi hittar key när vi jämför data som temp står vid
				found = true; // om vi hittar det så found blir true
			temp = temp->next;// och flytta till nästa node
		}
		return found;// här skickar vi resultat när loopen är klar

	}

	int Dequeue() //metod för att ta bort node från listan och vi ta bort front här har vi 3 alternative
	{
		int delvalue = -1;
		if (isEmpty()) //om den är töm
			cout << "The queue is empty \n";

		else if (front == rear) //om den har bara en node
		{
			delete front;
			front = rear = NULL;
		}
		else // om finns flera item i listan
		{
			Node* delptr = front; //vi skappar en node som är lika med front
			front = front->next; // vi gör så att front pikar på nästa node
			delvalue = delptr->data; //denna momunt är optional om du vill spara data som ska bort för logg eller print
			delete delptr; //vi ta bort den tewmp pointer som vfi skappade
		}

		return delvalue;
	}

	int getFront() //metod vi få kolla vilken data finns i front
	{
		return front->data;
	}

	int getRear() // som övan
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
