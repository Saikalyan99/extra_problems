#include<stdio.h>
#include<stdlib.h>

void insert(struct node **head, int newData);
int Length(struct node *ptr);
void Median(struct node *head, int medianlength);

struct node 
{
	int num;
	struct node *next;
};

int main()
{
	struct node *head = NULL;
	int index, length, arr[10] = {1,2,3,4,5,6,7,8,9};
	for (index = 6; index > 0; index--)									//please change index for selecting the length of linked list
		insert(&head, arr[index-1]);
	length = Length(head);												//calling "Length" function for the length of list
	Median(head, length);												//to calculate median
	getch();
}
void insert(struct node **head, int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->num = data;
	newNode->next = *(head);
	*(head) = newNode;
}
int Length(struct node *ptr)
{
	int length = 0;
	printf("the linked list is : ");
	printf("%d", ptr->num);
	ptr = ptr->next;
	while (ptr != NULL)
	{
		printf("->%d", ptr->num);
		ptr = ptr->next;
		length++;
	}
	return length + 1;
}
void Median(struct node *head, int length)
{
	int index = 0;
	float median, temp1, temp2;
	struct node *node = head;
	if (length % 2 != 0)												//median for odd number of observations(data)
	{
		while (index != length / 2)
		{
			node = node->next;
			index++;
		}
		median = node->num;;
	}
	else																//median for even number of observations(data)
	{
		while (index != length / 2)
		{
			node = node->next;
			index++;
			if(index==length/2-1)
				temp1 = node->num;
		}
		temp2 = node->num;
		median = (temp1 + temp2) / 2;
	}
	printf("\nThe median is : %0.1f\n", median);
}