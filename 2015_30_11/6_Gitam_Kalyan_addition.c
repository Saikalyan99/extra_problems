#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int num;
	struct node *next;
};

struct node *create(struct node *start);
struct node *insert(struct node *start, int num);
struct node *addition(struct node *list1, struct node *list2);
struct node *newNode(int data);
struct node *reverse(struct node *pointer, struct node **start);
void print(struct node *start);

int main()
{
	struct node *list1 = NULL, *list2 = NULL, *list3 = NULL;
	list1 = create(list1);
	list2 = create(list2);

	list3 = addition(list1, list2);
	
	print(list3);
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

struct node *insert(struct node *start, int num)							//to insert a node into a string
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;

	if (start == NULL || num<start->num)
	{
		temp->next = start;
		start = temp;
		return start;
	}
	else
	{
		list = start;
		while (list->next != NULL && list->next->num < num)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return start;
}

struct node *addition(struct node *list1, struct node *list2)				//for adding two lists
{
	struct node *result = NULL, *temp = NULL, *prev = NULL;
	int sum, flag = 0;
	while (list1 != NULL || list2 != NULL)
	{
		if (list1 == NULL)
			sum = list2->num;
		else if (list2 == NULL)
			sum = list1->num;
		else
			sum = list1->num + list2->num;

		if (list1 != NULL)
			list1 = list1->next;
		if (list2 != NULL)
			list2 = list2->next;
		temp = newNode(sum);

		if (result == NULL)													//here address of temp is pointed to result which is later pointed to prev
			result = temp;
		else
			prev->next = temp;												//new node is connected to prev
		prev = temp;
	}
	if (sum>10)
		reverse(result, &result);
	return result;
}

struct node *newNode(int num)												//it is for creating a new node
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = num;
	new_node->next = NULL;
	return new_node;
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

void print(struct node *start)												//to print the linked list
{
	while (start != NULL)
	{
		printf("%d ", start->num);
		start = start->next;
	}
	printf("\n");
}