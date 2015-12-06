#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct node *create(struct node *head);
struct node *insert(struct node *head, int data);
struct node *merge(struct node *list1, struct node *list2);

void print(struct node *start);
void position(struct node *start);

main()
{
	struct node *list1 = NULL, *list2 = NULL, *list3 = NULL;
	list1 = create(list1);
	list2 = create(list2);
	printf("\nList1 = ");
	print(list1);
	printf("\nList2 = ");
	print(list2);

	list3 = merge(list1, list2);
	printf("\nMerged list is = ");
	print(list3);
	position(list3);
	getch();
}

struct node *create(struct node *head)
{
	int index, num, data;
	printf("Enter the number of nodes = ");
	scanf("%d", &num);
	head = NULL;
	printf("Enter the element to be inserted = ");
	scanf("%d", &data);
	int n;
	for (n = 1, index = 1; index <= num; index++, n++)
	{
		head = insert(head, n*data);
	}
	return head;
}

struct node *insert(struct node *start, int data)
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = data;

	if (start == NULL)
	{
		temp->next = start;
		start = temp;
		return start;
	}
	else
	{
		list = start;
		while (list->next != NULL)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return start;
}

struct node *merge(struct node *list1, struct node *list2)
{
	struct node *list3;
	list3 = NULL;
	
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->num < list2->num)
		{
			list3 = insert(list3, list1->num);
			list1 = list1->next;
		}
		else if (list2->num < list1->num)
		{
			list3 = insert(list3, list2->num);
			list2 = list2->next;
		}
		else															//here the condition is "if(list1->num == list2->num)"
			list2 = list2->next;
	}
	while (list1 != NULL)
	{
		list3 = insert(list3, list1->num);
		list1 = list1->next;
	}
	while (list2 != NULL)
	{
		list3 = insert(list3, list2->num);
		list2 = list2->next;
	}
		return list3;
}

void position(struct node *start)
{
	int  key, index = 1, length = 0;
	struct node *ptr = start;
	printf("\n\nEnter the position = ");
	scanf("%d", &key);
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	if (key>length || key <= 0)
	{
		printf("Error the position is not there in the linked list");
		return;
	}
	while (start->next != NULL)
	{
		start = start->next;
		index++;
		if (index == key)
			break;
	}
	printf("The number at position %d is = %d", key, start->num);
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