#include<stdio.h>
struct test
{
	int size;
	int arr[100];
};
struct test testcase[3] = { { 5,{ 1,2,0,0,5 } },{ 5,{ 1,0,3,4,5 } },{ 6,{ -1,2,3,4,5,6 } } };
void product1(int size, int arr[]);
void product2(int size, int arr[]);
int main()
{
	int arr[100], size, count,stcount;
	for (stcount = 0;stcount < 3;stcount++)
	{
		size = testcase[stcount].size;
		printf("Test case %d\n\nSize of array = %d\nEntered array = ", stcount + 1, size);
		for (count = 0;count < size;count++)
		{
			arr[count] = testcase[stcount].arr[count];
			printf("%d ", arr[count]);
		}
		product1(size, arr);
		product2(size, arr);
	}
	getch();
}
void product1(int n, int arr[])
{
	long count, mull = 1, flag = 0;
	for (count = 0;count < n;count++)
	{
		if (arr[count] != 0)
			mull = mull*arr[count];
		else
			flag++;
	}
	printf("\nResultant Series of array by using '/'         = ");
	if (flag < 2)
	{
		if (flag == 0)
			for (count = 0;count < n;count++)
				printf("%d ", mull / arr[count]);
		else
			for (count = 0;count < n;count++)
				if (arr[count] == 0)
					printf("%d ", mull);
				else
					printf("0 ");
	}
	else
		for (count = 0;count < n;count++)
			printf("0 ");
}
void product2(int n, int arr[])
{
	long count1, count2, leftmul, rightmul, result[100];
	for (count1 = 0;count1 < n;count1++)
	{
		leftmul = 1;rightmul = 1;
		for (count2 = 0;count2 < count1;count2++)
			leftmul = leftmul*arr[count2];
		for (count2 = n-1;count2 > count1;count2--)
			rightmul = rightmul*arr[count2];
		result[count1] = leftmul*rightmul;
	}
	printf("\nResultant Series of array by without using '/' = ");
	for (count1 = 0;count1 < n;count1++)
		printf("%d ", result[count1]);
	printf("\n\n");
}