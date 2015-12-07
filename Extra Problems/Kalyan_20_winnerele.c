#include<stdio.h>
void winner(static int arr[], int size, int key);
void winnerskip(static int arr[], int size, int key);
int main()
{
	;static int arr[100], size, i, key;
	printf("Enter the size of the array = ");
	scanf("%d",&size);
	printf("Enter the array of the elements = ");
	for (i = 0;i < size;i++)
		scanf("%d", &arr[i]);
	printf("Enter the skip key of the array = ");
	scanf("%d", &key);
	winner(arr, size, key);
	winnerskip(arr, size, key);
	getch();
}
void winner(static int arr[], int size, int key)
{
	int temp, index1 = 0, index2, maxsum, indextemp = 0, lsum = 0, rsum = 0, set = 0;
	//"lsum" = sum of left side elements to the index and "rsum" = sum of right side elements to the index
	if (key % 2 == 0)
		set = 1;
	for (index2 = 0;index2 < key / 2;index2++)
		lsum = arr[index1 - index2 - 1] + lsum;												//adding left side elements
	for (index2 = 0;index2 < (key / 2) - set;index2++)
		rsum = arr[index1 + index2 + 1] + rsum;												//adding right side elements
	maxsum = lsum + arr[index1] + rsum;
	for (index1 = 1;index1 < size;index1++)
	{
		lsum = rsum = 0;
		for (index2 = 0;index2 < key / 2;index2++)
			lsum = arr[index1 - index2 - 1] + lsum;											//adding left side elements
		for (index2 = 0;index2 < (key / 2) - set;index2++)
			rsum = arr[index1 + index2 + 1] + rsum;											//adding right side elements
		temp = lsum + arr[index1] + rsum;
		if (temp > maxsum)																	//comparing temp with pervious sum
		{
			maxsum = temp;																	//assigning temp to maxsum
			indextemp = index1;																//assigning index to temp
		}
	}
	printf("The winner element by adding all %d adjacent = %d\n", key, arr[indextemp]);
}
void winnerskip(static int arr[], int size, int key)
{
	int temp, index1 = 0, maxsum, lsum, rsum, indextemp = 0, set = 0;
	//"lsum" = sum of left side elements to the index and "rsum" = sum of right side elements to the index
	if (key % 2 == 0)
		set = 1;
	lsum = arr[index1 - key / 2 - 1];														//left side element
	rsum = arr[index1 + (key / 2) - set + 1];												//right side element
	maxsum = lsum + arr[index1] + rsum;
	//the above step can also be assigned as ""maxsum = arr[index1 - key / 2 - 1] + arr[index1] + arr[index1 + (key / 2) - set + 1];""
	for (index1 = 1;index1 < size;index1++)
	{
		temp = arr[index1 - key / 2 - 1] + arr[index1] + arr[index1 + (key / 2) - set + 1];
		if (temp > maxsum)																	//comparing temp with pervious sum
		{
			maxsum = temp;																	//assigning temp to maxsum
			indextemp = index1;																//assigning index to temp
		}
	}
	printf("The winner element by skiping elements = %d", arr[indextemp]);
}
