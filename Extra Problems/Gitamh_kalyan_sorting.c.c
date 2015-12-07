#include<stdio.h>
struct test
{
	int size;
	int arr[100];
};
struct test testcase[3] = { { 5,{1,0,2,0,1} },{ 5,{1,0,1,0,1} },{ 8,{ 0,1,1,1,0,1,0,1 } } };
int sort1(int size, int arr[]);
int sort2(int size, int arr[]);
int sort3(int size, int arr[]);
int sort4(int size, int arr[]);
int sort5(int size, int arr[]);
int main()
{
	int count, size, arr[100], index, stcount;
	for (stcount = 0;stcount < 3;stcount++)
	{
		index = 0;
		size = testcase[stcount].size;
		printf("Test case %d\n\nSize of array = %d\nEntered array = ", stcount + 1, size);
		for (count = 0;count < size;count++)
		{
			arr[count] = testcase[stcount].arr[count];
			printf("%d ",arr[count]);
			if (arr[count] == 0 || arr[count] == 1)
				index++;
		}
		if (index == size)
		{
			sort1(size, arr);
			sort2(size, arr);
			sort3(size, arr);
			sort4(size, arr);
			sort5(size, arr);
		}
		else
			printf("\nError in input!!\n\n");
	}
	getch();
}
int sort1(int size, int arr[])
{
	int count, index = 0;
	for (count = 0;count < size;count++)
		if (arr[count] == 0)
			index++;
	printf("\nSorted array by counting '0'           = ");
	for (count = 0;count < index;count++)
		printf("0 ");
	for (count = 0;count < size - index;count++)
		printf("1 ");
	printf("\n");
}
int sort2(int size, int arr[])
{
	int count, index = 0, arr1[100] = {0};
	for (count = 0;count < size;count++)
		if (arr[count] == 1)
			index++;
	for (count = size;count > size - index;count--)
		arr1[count-1] = 1;
	printf("Sorted array by counting '1'           = ");
	for (count = 0;count < size;count++)
		printf("%d ",arr1[count]);
	printf("\n");
}
int sort3(int size, int arr[])
{
	int leftin, rightin;
	rightin = size - 1;
	for (leftin = 0;leftin < size;leftin++)
	{
		if (leftin < rightin)
		{
			while (arr[leftin] == 0 && leftin < rightin)
				leftin++;
			while (arr[rightin] == 1)
				rightin--;
			if (leftin < rightin)
			{
				arr[leftin] = 0;
				arr[rightin] = 1;
			}
		}
	}
	printf("Sorted array by using quick sort       = ");
	for (leftin = 0;leftin<size;leftin++)
		printf("%d ", arr[leftin]);
	printf("\n");
}
int sort4(int size, int arr[])
{
	int sum = 0,count;
	for (count = 0;count<size;count++)
	sum = sum + arr[count];
	printf("Sorted array by using sum              = ");
	for (count = 0;count < size - sum;count++)
		printf("0 ");
	for (count = 0;count < sum;count++)
		printf("1 ");
	printf("\n");
}
int sort5(int size, int arr[])
{
	int i, j, arr1[100], temp;
	for (i = 0;i < size;i++)
		arr1[i] = arr[i];
	for (i = 0;i < size;i++)
		for (j = 0;j < size - 1;j++)
			if (arr1[j] > arr1[j+1])
		{
			temp = arr1[j];
			arr1[j] = arr1[j + 1];
			arr1[j + 1] = temp;
		}
	printf("Sorted array by swaping                = ");
	for (i = 0;i < size;i++)
		printf("%d ",arr1[i]);
	printf("\n\n");
}
