#include<stdio.h>
void quicksort(int arr[], int left, int right);
void win(int arr[], int size, int num);
void winmax(int arr[], int size, int num);
int occurrence(int arr[], int size, int i);
int main()
{
	int arr[20], size, index, num;
	printf("Enter size of the array : ");
	scanf("%d", &size);
	printf("Enter %d elements of the array : ", size);
	for (index = 0;index<size;index++)
		scanf("%d", &arr[index]);
	printf("Enter the key value : ");
	scanf("%d", &num);
	if (size<num)																//checking for the condition that key should be less than size
		printf("Error size is less than entered key!!\n");
	else
	{
		quicksort(arr, 0, size - 1);											//calling quicksort function
		win(arr, size, num);													//calling Win function
	}
	getch();
}
void quicksort(int arr[], int left, int right)									//this quicksort function to arrange the elements in ascending order
{
	int index1 = left, index2 = right, temp, pivot = left;
	while (index1<index2)
	{
		while (arr[pivot] <= arr[index2] && index1<index2)
			index2--;
		if (index1 != index2)
		{
			temp = arr[pivot];
			arr[pivot] = arr[index2];
			arr[index2] = temp;
			pivot = index2;
		}
		while (arr[pivot] >= arr[index1] && index1<index2)
			index1++;
		if (index1 != index2)
		{
			temp = arr[pivot];
			arr[pivot] = arr[index1];
			arr[index1] = temp;
			pivot = index1;
		}
	}
	if (left<pivot)
		quicksort(arr, left, pivot - 1);
	if (right>pivot)
		quicksort(arr, pivot + 1, right);
}
void win(int arr[], int size, int num)
{
	//this function is to find the winner element when the "frequency of a element"= "key". this function is to save time only!!!
	int index, arr1[10] = {0}, temp = 0;
	for (index = 0;index < size;index++)
		arr1[arr[index]]++;
	for (index = 0;index < size;index++)
		if (arr1[index] == num)
		{
			temp = 1;
			break;
		}
	if(temp==1)
		printf("\nThe winner element is : %d", index);
	else
		winmax(arr, size, num);
}
void winmax(int arr[], int size, int num)										//this function is to find the winner element
{
	//finding the most recurring element in the array
	int most, var, index;
	most = occurrence(arr, size, 0);											//occurrence function is called for current winner element in array
	for (index = 0;index<size;index++)											//conditions to find the min cost
	{
		if (arr[index] == most - 1)
			arr[index] = most;
		else if (arr[index] == most + 1)
			arr[index] = most;
		else if (arr[index]>most)
			arr[index] = arr[index] - 1;
		else if (arr[index]<most)
			arr[index] = arr[index] + 1;
	}
	//finding the most recurring element in the above array
	var = occurrence(arr, size, 1);												//occurrence function is called for most occurrencing variable
	if (var >= num)
		printf("\nThe winner element is : %d", most);								//printing the winner element
	else
		winmax(arr, size, num);													//using recursion to repeat the process
}
int occurrence(int arr[], int size, int i)										//this function is for finding occurrence of element
{
	int most = 0, var = 0, var1 = 0, index, index1;
	for (index = 0;index<size;index++)
	{
		var1 = 1;
		for (index1 = index + 1;index1<size;index1++)
		{
			if (arr[index] == arr[index1])
				var1++;
		}
		if (var1>var)
		{
			var = var1;
			most = arr[index];
		}
	}
	if (i == 0)
		return most;
	if (i == 1)
		return var;
}