#include<stdio.h>
int count();
int main()
{
	count();
	getch();
}
int count()
{
	int arr[100], size, count, key, index1=0, index2=0;
	printf("enter the size of the array : ");
	scanf("%d", &size);
	if (size < 1)
		printf("error");
	else
	{
		printf("enter the elements of the array : ");
		for (count = 0;count < size;count++)
			scanf("%d", &arr[count]);
		printf("enter the key element : ");
		scanf("%d", &key);
		for (count = 0;count < size;count++)
		{
			if (key < arr[count])
				index1++;
			if (key > arr[count])
				index2++;
		}
		printf("The number of elements greater than %d = %d", key, index1);
		printf("\nThe number of elements smaller than %d = %d", key, index2);
	}

}
