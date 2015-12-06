#include<stdio.h>
void subarray(int arr[], int length);

int main()
{
	int arr[11] = { 1,2,3,4,5,-2,-3,-4,-20,10,2 };					//initializing array
	subarray(arr, 11);												//calling function
	getch();
}

void subarray(int arr[], int length)
{
	int temp = 0, temp1 = 0, begin = 0, end = 0, index, index1 = 0;

	for (index = 0; index < length; index++)						//finding begining and ending index of sub array
	{
		temp1 = temp1 + arr[index];
		if (temp1 <= 0)
		{
			temp1 = 0;
			index1 = index + 1;
		}
		else if (temp < temp1)
		{
			temp = temp1;
			begin = index1;
			end = index;
		}
	}
	printf("The sub array = (");
	for (index = begin; index <= end; index++)						//printing sub array
		printf(" %d", arr[index]);
	printf(" )\n");
	printf("sum = %d", temp);										//printiing the sum
}