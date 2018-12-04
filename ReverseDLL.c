#include <stdio.h>
#include <malloc.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void ReverseDLL(struct Node **q)
{
	struct Node *temp,*r;
	r = *q;
	while(r != NULL)
	{
		temp = r->next;
		r->next = r->prev;
		r->prev = temp;
		if(r->prev == NULL)
		{
			*q = r;
		}
		r = r->prev;
	}
}

void Display(struct Node *start)
{
	if(start == NULL)
		return;
	while(start != NULL)
	{
		printf("%d ",start->data);
		start = start->next;
	}
}

void CreateNode(struct Node **start,int num)
{
	struct Node *temp,*r;
	struct Node *curr = *start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->prev = NULL;
	temp->data = num;
	temp->next = NULL;
	if(*start == NULL)
	{
		*start = temp;
	}
	else
	{
		while(curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
		temp->next = NULL;
	}
}

void main()
{
	struct Node *start = NULL;
	CreateNode(&start,1);
	CreateNode(&start,2);
	CreateNode(&start,3);
	CreateNode(&start,4);
	CreateNode(&start,5);
	Display(start);
	ReverseDLL(&start);
	printf("\n");
	Display(start);
	printf("\n");
}
