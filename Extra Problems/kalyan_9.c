#include<stdio.h>
void check();
int main()
{
	check();
	getch();
}
void check()
{
	int index = 0, strlen = 0, arr[256], temp1 = 0, temp2;
	char str[500] = "hello world";
	while (str[strlen] != '\0')
		strlen++;
	for (index = 0;index < 256;index++)
		arr[index] = 0;
	if (strlen<1)
		printf("ERROR!! size of array is less than 1");
	else
	{
		for (index = 0;index<strlen;index++)
			arr[str[index]]++;
		for (index = 0;index < 256;index++)
			if (arr[index]>0)
			{
				if (arr[index] > temp1)
				{
					temp1 = arr[index];
					temp2 = index;
				}
			}
		printf("most occuring charecter is '%c' and has repeated %d times\n", temp2, arr[temp2]);
	}
}
