#include<stdio.h>
void basefib(int num);
int main()
{
	int num;
	printf("enter the number = ");
	scanf("%d",&num);
	basefib(num);
	getch();
}
void basefib(int num)
{
	int index, temp, arr1[20] = { 1,1 }, arr2[20] = { 1,2 }, arr3[20] = { 0 };			//
	for (index = 2;index < num;index++)
	{
		arr1[index] = arr1[index-1]+arr1[index-2];										//arr1 stores fibonacci series
		arr2[index] = arr2[index-1]+arr1[index];										//arr2 stores addition of fibonacci series upto the index
		if (num <= arr2[index])
			break;
	}
	temp = index;
	while (num != 0)
	{
		for (index = 0;index < num;index++)
			if (num <= arr2[index])														//compares the givien x number with the arr2 series
				break;
		if (num == arr1[index] && index>1)												//if the number is equal to the number in series then next two value with 1
		{
			arr3[index - 1] = arr3[index - 2] = 1;
			break;
		}
		num = num - arr1[index];														//num is sub with the number in fib series and at that index arr3 is set to 1
		arr3[index] = 1;
	}
	for (index = 0;index <= temp;index++)
		printf("%d",arr3[index]);
}