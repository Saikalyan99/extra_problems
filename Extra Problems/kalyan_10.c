#include<stdio.h>
int check();
int main()
{
	check();
	getch();
}
int check()
{
	int index, strlen1 = 0, strlen2 = 0, arr1[256], arr2[256];
	char str1[100] = "abcde,?eh", str2[100] = "helloeh";
	while (str1[strlen1] != '\0')
		strlen1++;
	while (str2[strlen2] != '\0')
		strlen2++;
	for (index = 0;index < 256;index++)
	{
		arr1[index] = 0; arr2[index] = 0;
	}
	for (index = 0;index < strlen1;index++)
		arr1[str1[index]] = 1;
	for (index = 0;index < strlen2;index++)
		arr2[str2[index]] = 1;
	printf("the common variables are :");
	for (index = 0;index < 256;index++)
	{
		if (arr1[index] == arr2[index])
			if (arr1[index]>0)
				printf(" %c", index);
	}
}
