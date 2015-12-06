#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct node *create(struct node *start);
struct node *insert(struct node *start, int data);
struct node *sort(struct node *head);

void merge(struct node *p1, struct node *p2);
void num_swap(struct node *ptr, struct node *ptrN);
void print(struct node *start);

int main()
{
	struct node *list1 = NULL, *list2 = NULL;
	list1 = create(list1);
	list2 = create(list2);

	printf("Linked List-1 = ");
	print(list1);
	printf("Linked List-2 = ");
	print(list2);
	merge(list1, list2);
	getch();
}

struct node *create(struct node *start)											//for creating a string
{
	int i, n, data;
	printf("Enter the number of nodes of linked list : ");
	scanf_s("%d", &n);
	if (n != 0)
	{
		start = NULL;
		printf("Enter the data to be inserted : ");
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &data);
			start = insert(start, data);
		}
		return start;
	}
	return start;
}

struct node *insert(struct node *start, int data)								//to insert a node into a string
{
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->num = data;

	if (start == NULL)
	{
		tmp->next = start;
		start = tmp;
		return start;
	}
	else
	{
		p = start;
		while (p->next != NULL)
			p = p->next;
		tmp->next = NULL;
		p->next = tmp;
	}
	return start;
}

struct node *sort(struct node *head)											//to swap two nodes
{
	if (head == NULL)
		return NULL;
	else
	{
		struct node *ptr, *indexptr = NULL;
		int flag = 1;
		while (flag != 0)
		{
			flag = 0;
			ptr = head;
			while (ptr->next != indexptr)
			{
				if (ptr->num > ptr->next->num)
				{
					num_swap(ptr, ptr->next);
					flag = 1;
				}
				ptr = ptr->next;
			}
			indexptr = ptr;
		}
		return head;
	}
}

void num_swap(struct node *ptr, struct node *ptrN)								//to swap two nodes
{
	int temp;
	temp = ptr->num;
	ptr->num = ptrN->num;
	ptrN->num = temp;
}

void print(struct node *start)													//to print the linked list
{
	while (start != NULL)
	{
		printf("%d ", start->num);
		start = start->next;
	}
	printf("\n");
}

void merge(struct node *p1, struct node *p2)									//to merge the linked list
{
	if (p1 != NULL || p2 != NULL)
	{
		while (p2 != NULL)
		{
			p1 = insert(p1, p2->num);
			p2 = p2->next;
		}
		sort(p1);
		printf("Merged list is = ");
		print(p1);
	}
	else
		printf("Merged list is = NULL");
}
