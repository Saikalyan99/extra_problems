#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *create(struct node *start);
struct node *traverse(struct node **start);
struct node *insert(struct node *start, int data);
void print(struct node *start);

int main()
{
	struct node *list1 = NULL;
	list1 = create(list1);
	list1 = traverse(&list1);
	printf("The Sorted list = ");
	print(list1);
	getch();
}

struct node *create(struct node *start)										//to create a linked list
{
	int index, length, data;
	printf("Enter the number of nodes : ");
	scanf("%d", &length);
	start = NULL;
	printf("Enter the elements to be inserted : ");
	for (index = 1; index <= length; index++)
	{
		scanf("%d", &data);
		start = insert(start, data);
	}
	return start;
}

struct node *insert(struct node *start, int data)							//for inserting node on to a linked list
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	if (start == NULL || data<start->data)
	{
		temp->next = start;
		start = temp;
		return start;
	}
	else
	{
		list = start;
		while (list->next != NULL && list->next->data < data)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return start;
}

struct node *traverse(struct node **start)									//to traverse the linked list
{
	struct node *ptr = *(start), *ptr1 = ptr->next;

	while (ptr1 != NULL)
	{
		if (ptr->data >ptr1->data)
		{
			struct node *temp = ptr->data;
			ptr->data = ptr1->data;
			ptr1->data = temp;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
	}
	ptr = *start;
	return ptr;
}

void print(struct node *start)												//to print the linked list
{
	while (start != NULL)
	{
		printf("%d ", start->data);
		start = start->next;
	}
	printf("\n");
}