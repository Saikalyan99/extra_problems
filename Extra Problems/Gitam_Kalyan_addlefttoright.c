#include<stdio.h>
#include<malloc.h>
void addition(char *str1, char *str2);
void main()
{
	char *str1 = (char*)malloc(10000), *str2 = (char*)malloc(10000);
	printf("Enter the number 1 : ");
	gets(str1);
	printf("Enter the number 2 : ");
	gets(str2);
		addition(str1, str2);
	getch();
}
void addition(char *str1, char *str2)
{
	int  temp, i=0;
	char c = ' ';
	while (str1[i] != 0 || str1[i] != 0)
	{
		str1[i] = str1[i] + str2[i] - '0';
		if (str1>'9')
		{
			temp = i;
			while (temp != 0)									//if carry if generated more than one variable it will pass the carry
			{
				if (str1[temp] > '9')
				{
					str1[temp] = str1[temp] - 10;
					if ((temp - 1) == -1)						//if the pointer is in MSB it will enable another bit
						c = '1';
					else
						str1[temp - 1] = str1[temp - 1] + 1;	//passing carry to next bit
				}
				temp--;
			}
		}
		i++;
	}
	printf("Sum of the given numbers = %c", c);
	puts(str1);
	free(str1, str2);
}
