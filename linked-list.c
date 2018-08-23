#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *create(int data)
{
	node *tmp;
	tmp=(node *)malloc( sizeof(node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}

node *add(node *head,int data)
{
	node *tmp;
	if (!head)
	{
	head=create(data);
	}
	else
	{
		tmp=head;
		while (tmp->next)
		tmp=tmp->next;
	    tmp->next=create(data);
	}
	return head;
}

int count(node *head)
{
	int c=0;
	while (head)
	{
		head=head->next;
		c++;
	}
	return c;
}

void sort(node *head,int length)
{
	node *tmp;
	int aux;
	while (length)
	{
	tmp=head;
	while (tmp->next)
	{
	    if (tmp->data>tmp->next->data)
	   {
		aux=tmp->data;
		tmp->data=tmp->next->data;
		tmp->next->data=aux;
		}
	  tmp=tmp->next;
	}
	length--;
	}
}

void display(node *head)
{
	while (head)
	{
	printf("%d -> ",head->data);
    head=head->next;
    }
    printf("NULL\n");
}

int main()
{
	int data;
	node *head=NULL;
	printf("Enter number (-1 to terminate)?\n");
	scanf("%d",&data);
	while (data!=-1)
	{
	head=add(head,data);
	printf("Enter number (-1 to terminate)?\n");
	scanf("%d",&data);
	}
	printf("Display sorted data:\n");
	sort(head,count(head));
	display(head);
	return 0;
}