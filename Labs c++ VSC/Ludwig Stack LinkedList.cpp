//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Stack
//{
//	int data;
//	struct Node* next;
//}*top = NULL;
//
//void push( int x)
//{
//	struct Node* t;
//	t = (struct Node*)malloc(sizeof(struct Node*));
//	if (t == NULL)
//		printf("stack is full");
//	else
//	{
//		t->data = x;
//		t->next = top;
//		top = t;
//	}
//}
//
//int pop()
//{
//	struct Node* t
//		int x = -1;
//	if (top==NULL)
//		printf("stack is Empty");
//	else
//	{
//		t = top;
//		top = top->next;
//		x = t->data;
//		free(t);
//	}
//	return x;
//
//}
//
//void print()
//{
//	struct Node* p;
//	p = top;
//
//	while (p!=NULL)
//	{
//		printf("%d", p->data);
//		p = p->next;
//	}
//	printf("\n");
//
//}

//int main()
//{
//	struct Stack st;
//	push(10);
//	push(20);
//	push(30);
//
//	print();
//	printf("%d", pop());
//
//	return 0;
//
//}
//
//
//
//
