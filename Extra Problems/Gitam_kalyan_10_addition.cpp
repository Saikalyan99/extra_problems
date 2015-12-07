#include<stdio.h>
void addition(char *str1, char *str2, int strlen1, int strlen2);
void main()
{
	int strlen1 = 0, strlen2 = 0, len = sizeof(char), size = 0, char_in;
	char *str1 = (char*)malloc(len), *str2 = (char*)malloc(len);						//memory allocation
	size = len;
	printf("Enter the number 1 : ");
	if (str1 != NULL)
	{
		strlen1 = 0;
		while ((char_in = getchar()) != '\n')
		{
			str1[strlen1++] = char_in;
			if (strlen1 == size)														//reallocate memory if needed and finding string length
			{
				size = strlen1 + len;
				str1 = (char*)realloc(str1, size);
			}
		}
	}
	str1[strlen1] = '\0';
	printf("Enter the number 2 : ");
	if (str2 != NULL)
	{
		strlen2 = 0;
		while ((char_in = getchar()) != '\n')
		{
			str2[strlen2++] = char_in;
			if (strlen2 == size)														//reallocate memory if needed and finding string length
			{
				size = strlen2 + len;
				str2 = (char*)realloc(str2, size);
			}
		}
	}
	str2[strlen2] = '\0';
	if (strlen1 > strlen2)																//if is used to send the biggest string as first string to function
		addition(str1, str2, strlen1, strlen2);										
	else
		addition(str2, str1, strlen2, strlen1);
	free(str1,str2);
	getch();
}
void addition(char *str1, char *str2, int strlen1, int strlen2)
{
	int  flag = 0, add = 0, count1, c = ' ';
	for (count1 = strlen1 - 1;count1 >= 0;count1--)
	{
		if (str1[count1] > 47 && str1[count1] < 58 || str1[count1] > 47 && str1[count1] < 58)		//checking whether the input is number or not
		{
			str1[count1] = str1[count1] + str2[strlen2 - 1] - 48;
			if (str1[count1] > 57)														//if str1[count1]>'9'
			{
				str1[count1] = str1[count1] - 10;
				if (count1 - 1 == -1)
					c='1';
				else
					str1[count1 - 1] = str1[count1 - 1] + 1;							//adding to next digit
			}
			strlen2--;
			if (strlen2 == 0)
				break;
		}
		else
			flag++;
	}
	if (flag != 0)
		printf("Error in input");
	printf("Sum of the given numbers = %c", c);
	puts(str1);
}
