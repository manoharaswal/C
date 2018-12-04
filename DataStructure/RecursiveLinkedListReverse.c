#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NodePtr;

NodePtr *head,*tail,*temp;

void addNode(int data);
NodePtr *RecursiveReverse(NodePtr *root);
void printList();

int main()
{
	head = (NodePtr *)0;
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);

	printList();

	if(head != (NodePtr *)0)
	{
		temp = RecursiveReverse(head);
		temp->next = (NodePtr *)0;
	}

	printList();
	return 0;
}

NodePtr *RecursiveReverse(NodePtr *root)
{
	if(root->next != (NodePtr *)0)
	{
		RecursiveReverse(root->next);
		root->next->next = root;
		return root;
	}
	else
		head = root;
}

void addNode(int data)
{
	temp = (NodePtr *)malloc(sizeof(NodePtr));
	temp->next = (NodePtr *)0;
	temp->data = data;

	if(head == (NodePtr *)0)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void printList()
{
	printf("\n\n");
	for(temp = head; temp != (NodePtr *)0; temp = temp->next)
	{
		printf("[%d]->",temp->data);
	}
	printf("[NULL]\n\n");
}
