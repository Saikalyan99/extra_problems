#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct node *insert(struct node *start, int data);
void print(struct node *start, struct node *pointer);

int main()
{
	int number_nodes, index, data, arr[10] = { 1,2,3,4,5,6,7,8,9 };
	struct node *head, *temp;
	head = (struct node *)malloc(sizeof(struct node));
	temp = head;
	temp->next = head;
	for (index = 0; index < 6; index++)											//please change index for selecting the length of linked list
		insert(head, arr[index]);
	printf("The circular linked list = ");
	print(head, head->next);
	printf("\nNumber nodes do you want to enter = ");
	scanf("%d",&number_nodes);
	printf("\nEnter item to store data : ");
	index = 0;
	while (index != number_nodes)
	{
		scanf("%d", &data);
		insert(head, data);
		index++;
	}
	printf("\nThe new circular linked list is ");
	print(head, head->next);
	printf("\n");
	getch();
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
		while (p->next != start)
		{
			p = p->next;
		}
		tmp->next = start;
		p->next = tmp;
	}
	return start;
}
void print(struct node *start, struct node *pointer)							//to print the linked list
{
	if (pointer == start)
		return;
	printf("%d ", pointer->num);
	print(start, pointer->next);
}