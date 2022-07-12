////DEL 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void RDisplay(struct Node* p)
//{
//	if (p != NULL)
//	{
//		RDisplay(p->next);
//		printf("%d ", p->data);
//	}
//}
//int main()
//{
//	struct Node* temp;
//	int A[] = { 3,5,7,10,25,8,32,2 };
//	create(A, 8);
//	Display(first);
//	return 0;
//}
////DEL 2;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//int count(struct Node* p)
//{
//	int l = 0;
//	while (p)
//	{
//		l++;
//		p = p->next;
//	}
//	return l;
//}
//int Rcount(struct Node* p)
//{
//	if (p != NULL)
//		return Rcount(p->next) + 1;
//	else
//		return 0;
//}
//int sum(struct Node* p)
//{
//	int s = 0;
//	while (p != NULL)
//	{
//		s += p->data;
//		p = p->next;
//	}
//	return s;
//}
//int Rsum(struct Node* p)
//{
//	if (p == NULL)
//		return 0;
//	else
//		return Rsum(p->next) + p->data;
//}
//int main()
//{
//	int A[] = { 3,5,7,10,25,8,32,2 };
//	create(A, 8);
//	printf("Count %d\n", count(first));
//	printf("Sum %d\n", sum(first));
//	return 0;
//}
////DEL 3;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//int Max(struct Node* p)
//{
//	int max = INT32_MIN;
//	while (p)
//	{
//		if (p->data > max)
//			max = p->data;
//		p = p->next;
//	}
//	return max;
//}
//int RMax(struct Node* p)
//{
//	int x = 0;
//	if (p == 0)
//		return INT32_MIN;
//	x = RMax(p->next);
//	if (x > p->data)
//		return x;
//	else
//		return p->data;
//}
//int main()
//{
//	int A[] = { 3,5,7,10,25,8,32,2 };
//	create(A, 8);
//	printf("Max %d\n", Max(first));
//}
////DEL 4;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//struct Node* LSearch(struct Node* p, int key)
//{
//	struct Node* q;
//	while (p != NULL)
//	{
//		if (key == p->data)
//		{
//			q->next = p->next;
//			p->next = first;
//			first = p;
//			return p;
//		}
//		q = p;
//		p = p->next;
//	}
//	return NULL;
//}
//struct Node* RSearch(struct Node* p, int key)
//{
//	if (p == NULL)
//		return NULL;
//	if (key == p->data)
//		return p;
//	return RSearch(p->next, key);
//}
//int main()
//{
//	struct Node* temp;
//	int A[] = { 3,5,7,10,25,8,32,2 };
//	create(A, 8);
//	temp = RSearch(first, 8);
//	printf("%d", temp->data);
//	return 0;
//}
////DEL 5;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//int count(struct Node* p)
//{
//	int l = 0;
//	while (p)
//	{
//		l++;
//		p = p->next;
//	}
//	return l;
//}
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void Insert(struct Node* p, int index, int x)
//{
//	struct Node* t;
//	int i;
//	if (index < 0 || index > count(p))
//		return;
//	t = (struct Node*)malloc(sizeof(struct Node));
//	t->data = x;
//	if (index == 0)
//	{
//		t->next = first;
//		first = t;
//	}
//	else
//	{
//		for (i = 0; i < index - 1; i++)
//			p = p->next;
//		t->next = p->next;
//		p->next = t;
//	}
//}
//int main()
//{
//	int A[] = { 10,20,30,40,50 };
//	create(A, 5);
//	Insert(first, 0, 5);
//	Display(first);
//	return 0;
//}
////DEL 6;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void RDisplay(struct Node* p)
//{
//	if (p != NULL)
//	{
//		RDisplay(p->next);
//		printf("%d ", p->data);
//	}
//}
//int count(struct Node* p)
//{
//	int l = 0;
//	while (p)
//	{
//		l++;
//		p = p->next;
//	}
//	return l;
//}
//int Delete(struct Node* p, int index)
//{
//	struct Node* q = NULL;
//	int x = -1, i;
//	if (index < 1 || index > count(p))
//		return -1;
//	if (index == 1)
//	{
//		q = first;
//		x = first->data;
//		first = first->next;
//		free(q);
//		return x;
//	}
//	else
//	{
//		for (i = 0; i < index - 1; i++)
//		{
//			q = p;
//			p = p->next;
//		}
//		q->next = p->next;
//		x = p->data;
//		free(p);
//		return x;
//	}
//}
//int main()
//{
//	int A[] = { 10,20,30,40,50 };
//	create(A, 5);
//	printf("%d\n", Delete((first), 2));
//	Display(first);
//	return 0;
//}
////DEL 7;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL, * second = NULL, * third = NULL;
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//int isSorted(struct Node* p)
//{
//	int x = -65536;
//	while (p != NULL)
//	{
//		if (p->data < x)
//			return 0;
//		x = p->data;
//		p = p->next;
//	}
//	return 1;
//}
//int main()
//{
//	int A[] = { 10,20,30,40,50 };
//	create(A, 5);
//	printf("%d\n", isSorted(first));
//	return 0;
//}
////DEL 8;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL, * second = NULL, * third = NULL;
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void create2(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	second = (struct Node*)malloc(sizeof(struct Node));
//	second->data = A[0];
//	second->next = NULL;
//	last = second;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Merge(struct Node* p, struct Node* q)
//{
//	struct Node* last;
//	if (p->data < q->data)
//	{
//		third = last = p;
//		p = p->next;
//		third->next = NULL;
//	}
//	else
//	{
//		third = last = q;
//		q = q->next;
//		third->next = NULL;
//	}
//	while (p && q)
//	{
//		if (p->data < q->data)
//		{
//			last->next = p;
//			last = p;
//			p = p->next;
//			last->next = NULL;
//		}
//		else
//		{
//			last->next = q;
//			last = q;
//			q = q->next;
//			last->next = NULL;
//		}
//	}
//	if (p)last->next = p;
//	if (q)last->next = q;
//}
//int main()
//{
//	int A[] = { 10,20,40,50,60 };
//	int B[] = { 15,18,25,30,55 };
//	create(A, 5);
//	create2(B, 5);
//	Merge(first, second);
//	Display(third);
//	return 0;
//}
////DEL 9;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL, * second = NULL, * third = NULL;
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void RemoveDuplicate(struct Node* p)
//{
//	struct Node* q = p->next;
//	while (q != NULL)
//	{
//		if (p->data != q->data)
//		{
//			p = q;
//			q = q->next;
//		}
//		else
//		{
//			p->next = q->next;
//			free(q);
//			q = p->next;
//		}
//	}
//}
//int main()
//{
//	int A[] = { 10,20,20,40,50,50,50,60 };
//	create(A, 8);
//	RemoveDuplicate(first);
//	Display(first);
//	return 0;
//}
////DEL 10;
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL, * second = NULL, * third = NULL;
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Reverse1(struct Node* p)
//{
//	int* A, i = 0;
//	struct Node* q = p;
//	A = (int*)malloc(sizeof(int) * count(p));
//	while (q != NULL)
//	{
//		A[i] = q->data;
//		q = q->next;
//		i++;
//	}
//	q = p;
//	i--;
//	while (q != NULL)
//	{
//		q->data = A[i];
//		q = q->next;
//		i--;
//	}
//}
//void Reverse2(struct Node* p)
//{
//	struct Node* q = NULL, * r = NULL;
//	while (p != NULL)
//	{
//		r = q;
//		q = p;
//		p = p->next;
//		q->next = r;
//	}
//	first = q;
//}
//void Reverse3(struct Node* q, struct Node* p)
//{
//	if (p)
//	{
//		Reverse3(p, p->next);
//		p->next = q;
//	}
//	else
//		first = q;
//}
//int main()
//{
//	int A[] = { 10,20,40,50,60 };
//	create(A, 5);
//	Reverse1(first);
//	Display(first);
//	return 0;
//}
//
////Head Recursion;
//
//void fun(int n)
//{
//	if (n > 0)
//	{
//		fun(n - 1);
//		printf("%d ", n);
//	}
//}
//int main() {
//	int x = 3;
//	fun(x);
//	return 0;
//}
//
////Tail Recursion;
//
//void fun(int n)
//{
//	if (n > 0)
//	{
//		printf("%d ", n);
//		fun(n - 1);
//	}
//}
//int main() {
//	int x = 3;
//	fun(x);
//	return
//		0;
//}
////Static Variables in Recursion;
//
//int fun(int n)
//{
//	static int x = 0;
//	if (n > 0)
//	{
//		x++;
//		return fun(n - 1) + x;
//	}
//	return 0;
//}
//int main() {
//	int r;
//	r = fun(5);
//	printf("%d\n", r);
//	r = fun(5);
//	printf("%d\n", r);
//	return 0;
//}
//
//
////Global Variabels in Recursion
//
//int x = 0;
//int fun(int n)
//{
//	if (n > 0)
//	{
//		x++;
//		return fun(n - 1) + x;
//	}
//	return 0;
//}
//int main() {
//	int r;
//	r = fun(5);
//	printf("%d\n", r);
//	r = fun(5);
//	printf("%d\n", r);
//	return 0;
//}
//
//
////Tree Recursion;
//void fun(int n)
//{
//	if (n > 0)
//	{
//		printf("%d ", n);
//		fun(n - 1);
//		fun(n - 1);
//	}
//}
//int main() {
//	fun(3);
//	return 0;
//}
//
////Indirect Recursion;
//
//void funB(int n);
//void funA(int n)
//{
//	if (n > 0)
//	{
//		printf("%d ", n);
//		funB(n - 1);
//	}
//}
//void funB(int n)
//{
//	if (n > 1)
//	{
//		printf("%d ", n);
//		funA(n / 2);
//	}
//}
//int main()
//{
//	funA(20);
//	return 0;
//}
//
////Nested Recursion;
//int fun(int n)
//{
//	if (n > 100)
//		return n - 10;
//	return fun(fun(n + 11));
//}
//int main()
//{
//	int r;
//	r = fun(95);
//	printf("%d\n", r);
//	return 0;
//}
//
////Sum of n
//int sum(int n)
//{
//	if (n == 0)
//		return 0;
//	return sum(n - 1) + n;
//}
//int Isum(int n)
//{
//	int s = 0, i;
//	for (i = 1; i <= n; i++)
//		s = s + i;
//	return s;
//}
//int main()
//{
//	int r = sum(5);
//	printf("%d ", r);
//	return 0;
//}
//
////Factorials;
//int fact(int n)
//{
//	if (n == 0)
//		return 1;
//	return fact(n - 1) * n;
//}
//int Ifact(int n)
//{
//	int f = 1, i;
//	for (i = 1; i <= n; i++)
//		f = f * i;
//	return f;
//}
//int main()
//{
//	int r = Ifact(5);
//	printf("%d ", r);
//	return 0;
//}
//
//
////Power of;
//int power(int m, int n)
//{
//	if (n == 0)
//		return 1;
//	return power(m, n - 1) * m;
//}
//int power1(int m, int n)
//{
//	if (n == 0)
//		return 1;
//	if (n % 2 == 0)
//		return power1(m * m, n / 2);
//	return m * power1(m * m, (n - 1) / 2);
//}
//int main()
//{
//	int r = power1(9, 3);
//	printf("%d ", r);
//	return 0;
//}
//
////Combination formula;
//int fact(int n)
//{
//	if (n == 0)return 1;
//	return fact(n - 1) * n;
//}
//int nCr(int n, int r)
//{
//	int num, den;
//	num = fact(n);
//	den = fact(r) * fact(n - r);
//	return num / den;
//}
//int NCR(int n, int r)
//{
//	if (n == r || r == 0)
//		return 1;
//	return NCR(n - 1, r - 1) + NCR(n - 1, r);
//}
//int main()
//{
//	printf("%d \n", NCR(5, 3));
//	return 0;
//}
//
//
////Tower of Hanoi
//void TOH(int n, int A, int B, int C)
//{
//	if (n > 0)
//	{
//		TOH(n - 1, A, C, B);
//		printf("(%d,%d)\n", A, C);
//		TOH(n - 1, B, A, C);
//	}
//}
//int main()
//{
//	TOH(4, 1, 2, 3);
//	return 0;
//}