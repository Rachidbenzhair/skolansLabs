#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
	int size;
	int top;
	int* S;

};

void create(struct Stack* st)
{
	printf("Enter Size: ");
	scanf("%d", &st->size);
	st->top = -1;
	st->S = (int*)malloc(st->size * sizeof(int));
}

void push(struct Stack* st, int x)
{
	if (st->top == st->size - 1)
		printf("stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top] = x;

	}
}
int pop(struct Stack* st)
{
	int x = -1;
	if (st->top == -1)
		printf("stack Underflow\n");
	else
	{
		x = st->S[st->top--];

	}
	return x;
}

void print(struct Stack st)
{

	int i;
	printf("[");
	for (i = st.top; i >= 0; i--)
	{
		printf("%d ", st.S[i]);

	}
	printf("]");
	printf("\n");

}

//int main()
//{
//	struct Stack st;
//	create(&st);
//	push(&st, 10);
//	push(&st, 20);
//	push(&st, 30);
//	push(&st, 40);
//	push(&st, 50);
//	print(st);
//	pop(&st);
//	print(st);
//
//
//
//}
//
