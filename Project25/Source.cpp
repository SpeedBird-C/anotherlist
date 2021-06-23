#include "stdio.h"
#include "stdlib.h"
#include <conio.h>
struct list
{
	int field; // ���� ������
	struct list *next; // ��������� �� ��������� �������
	struct list *prev; // ��������� �� ���������� �������
};

struct list * init(int a)  // �- �������� ������� ����
{
	struct list *lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	return(lst);
}
struct list * addelem(list *lst, int number)
{
	struct list *temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // ���������� ��������� �� ��������� ����
	lst->next = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� ����
	temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
void listprint(list *lst)
{
	struct list *p;
	p = lst;
	do {
		printf("%d ", p->field); // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != NULL); // ������� ��������� ������
}
void listprintr(list *lst)
{
	struct list *p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // ������� � ����� ������
	do {
		printf("%d ", p->field); // ����� �������� �������� p
		p = p->prev; // ������� � ����������� ����
	} while (p != NULL); // ������� ��������� ������
}
list* find(list* cur, int value)
{
	while (cur)
	{
		if (cur->field == value)
			return cur;
		else cur = cur->next;
	}
}
	struct list * deletelem(list *lst)
	{
		struct list *prev, *next;
		prev = lst->prev; // ����, �������������� lst
		next = lst->next; // ����, ��������� �� lst
		if (prev != NULL)
			prev->next = lst->next; // ������������ ���������
		if (next != NULL)
			next->prev = lst->prev; // ������������ ���������
		free(lst); // ����������� ������ ���������� ��������
		return(prev);
	}
	struct list * deletehead(list *root)
	{
		struct list *temp;
		temp = root->next;
		temp->prev = NULL;
		free(root);   // ������������ ������ �������� �����
		return(temp); // ����� ������ ������
	}
	list* addelem2(list* lst)
	{
		list* t;
		t = (list*)malloc(sizeof(list));
		t->field = 666;
		t->next = lst;
		t->prev = NULL;
		return t;
	   }
	list* addelem3(list* lst,list* head)
	{
		list* t,*p;
		t = (list*)malloc(sizeof(list));
		t->field = 333;
		p = lst->prev;
		lst->prev = t;
		if (p != NULL)
			p->next= t;
		t->next = lst;
		t->prev = p;
		return head;
	}
int main()
{
	list* head, *cur;
	head=init(777);
	cur = head;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		head = addelem(head, i);
	}
	
	listprint(cur);//� ������
	putchar('\n');
	listprintr(cur);// � �������� �����
	list* f = find(cur,2);
	f = addelem(f, 888);
	putchar('\n');
	listprint(cur);//� ������
	list *w= deletelem(f);
	putchar('\n');
	listprint(cur);
	w = deletehead(cur);
	putchar('\n');
	listprint(w);
	cur = addelem2(w);
	putchar('\n');
	listprint(cur);//� ������
	f = find(cur, 2);
	list* k=addelem3(f,cur);
	putchar('\n');
	listprint(k);//� ������
	_getch();
	return 0;
}