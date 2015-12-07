#include<stdio.h>
int check();
int main()
{
	check();
	getch();
}
int check()
{
	int  i, j, temp1, temp2, length = 7, arr[100] = { 1,2,5,12,23,8,30 };
	for (i = 1;i < length;i++)
	{
		if (arr[i - 1] < arr[i])
			continue;
		else
			break;
	}
	temp1 = arr[i];
	for (i = 0;i < length;i++)
	{
		if (arr[i] < temp1)
			continue;
		else
			break;
	}
	temp1 = i;
	printf("%d \n", temp1);
	for (i = temp1;i < length-1;i++)
	{
		for (j = temp1;j < length-1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				printf("%d-%d    %d-%d\n", j, arr[j], j + 1, arr[j + 1]);
				temp2 = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp2;
			}
			else
			{
				continue;
			}
		}
	}
	for (i = 0;i < length;i++)
		printf("%d ", arr[i]);
}