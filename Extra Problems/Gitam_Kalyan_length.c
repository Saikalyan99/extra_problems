#include<stdio.h>
void calculate_length(int arr[]);
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	calculate_length(arr);
	getch();
}
void calculate_length(int arr[])
{
	int index = 1, length, temp;							//here index represents index for array or size
	while (1)
	{
		if (arr[index + 1]<arr[index])						//check whether n+1 value is lesser than n value of array
		{
			if (arr[index + 1] == 0)						//check n+1 value is zero or not in array. If zero then len =n-2
			{
				length = index - 2;
				break;
			}
			else
			{
				length = index - 1;
				break;
			}
		}
		else if (arr[index] == 0)
		{
			if (arr[index - 1] != 0)						//if index is near to the size by 3 it will give the length
			{
				length = index - 3;
				break;
			}
			else
			{												//if number is not zero then decrease size
				temp = index / 2;
				temp = temp + (temp / 2);
				index = temp;
			}
		}
		else index = 2 * index;								//double the index
	}
	printf("length = %d\n", length + 1);
}