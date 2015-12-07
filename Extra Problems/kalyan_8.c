#include<stdio.h>
void minimum_sum(int arr[], int array_length);
int main()
{
	int arr[100], size, loopcount;
	printf("Enter the size of the array : ");
	scanf("%d", &size);
	if (size < 1)
		printf("ERROR!! size of array is less than one");
	else
	{
		printf("Enter the elements : ");
		for (loopcount = 0; loopcount < size; loopcount++)
		{
			scanf("%d", &arr[loopcount]);
		}
		minimum_sum(arr, size);
	}
	getch();
}
void minimum_sum(int arr[], int array_length)
{
	int loopcount, var1, var2, temp = 0;
	var2 = arr[1];
	var1 = arr[0];
	for (loopcount = 0; loopcount < array_length;loopcount++)
	{
		if (var2 > arr[loopcount])
		{
			temp = var2;
			var2 = arr[loopcount];
			var1 = temp;
			temp = 0;
		}
	}
	printf("The numbers whose sum is minimal among the string is %d and %d", var2, var1);
}
