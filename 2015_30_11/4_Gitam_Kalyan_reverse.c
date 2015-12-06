#include<stdio.h>

struct node
{
	int num;
	struct node *next;
};

void insert(struct node **head, int Data);
void print(struct node *head);
struct node *reverse(struct node *new_node, struct node **head);

int main()
{
	struct node *head = NULL;

	int index = 10, arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	while (index != 0)
		insert(&head, arr[(index--) - 1]);

	printf("linked list = ");
	print(head);
	if (head == NULL)
	{
		printf("\n\nlinked list is empty");
	}
	else
	{
		printf("\n\nlinked list after reversing = ");
		reverse(head, &head);
		print(head);
	}
	getch();
}
void insert(struct node **head, int Data)									//inserting a node to string
{
	struct node *new_Node = (struct node*)malloc(sizeof(struct node));
	new_Node->num = Data;
	new_Node->next = *head;
	*head = new_Node;
}

void print(struct node *start)												//to print the node
{
	while (start != NULL)
	{
		printf("%d ", start->num);
		start = start->next;
	}
	printf("\n");
}

struct node *reverse(struct node *pointer, struct node **start)				//to reverse a string
{
	if (pointer->next == 0)
	{
		*start = pointer;
		return pointer;
	}
	else
	{
		struct node *previous_node = reverse(pointer->next, start);
		previous_node->next = pointer;
		pointer->next = 0;
		return pointer;
	}
}