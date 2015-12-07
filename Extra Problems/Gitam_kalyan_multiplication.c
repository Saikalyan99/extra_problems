#include<stdio.h>
#include<string.h>
void multiply(char *a, char *b);
int main()
{
	unsigned int len = sizeof(char), size = 0, index;
	int ch;
	char *num1,*num2;
	num1 = (char*)malloc(len);								//memory allocation
	size = len;
	printf("Enter the first number : ");
	if (num1 != NULL)
	{
		index = 0;
		while ((ch = getchar()) != '\n')
		{
			num1[index++] = ch;
			if (index == size)								//reallocate memory if needed
			{
				size = index + len;
				num1 = (char*)realloc(num1, size);
			}
		}
	}
	num1[index] = '\0';
	printf("Enter the second number : ");
	num2 = (char*)malloc(len);								//memory allocation
	size = len;
	if (num2 != NULL)
	{
		index = 0;
		while ((ch = getchar()) != '\n')
		{
			num2[index++] = ch;
			if (index == size)								//reallocate memory if needed
			{
				size = index + len;
				num2 = (char*)realloc(num2, size);
			}
		}
	}
	num2[index] = '\0';
	printf("Multiplication of two numbers : ");
	multiply(num1, num2);
	free(num1, num2);
	getch();
}

void multiply(char *num1, char *num2) 
{
	static char mul[10000];
	char carry[10000], temp[10000];
	int count1, count2, count3, sizeindex = 0, index = 0, lennum1 = strlen(num1) - 1, lennum2 = strlen(num2) - 1;
	long int r = 0, sum = 0;
	for (count1 = lennum2;count1 >= 0;count1--)
	{
		r = 0;
		for (count2 = lennum1;count2 >= 0;count2--)
		{
			temp[sizeindex++] = ((num2[count1]-'0') * (num1[count2]-'0') + r) % 10;
			r = ((num2[count1]-'0') * (num1[count2]-'0') + r) / 10;
		}
		temp[sizeindex++] = r;
		index++;
		for (count3 = 0;count3<index;count3++)
			temp[sizeindex++] = 0;
	}
	sizeindex = 0;
	r = 0;
	for (count1 = 0;count1<lennum1 + lennum2 + 2;count1++)
	{
		sum = 0;
		count3 = 0;
		for (count2 = 1;count2 <= lennum2 + 1;count2++) 
		{
			if (count1 <= lennum1 + count2)
				sum = sum + temp[count3 + count1];
			count3 += count2 + lennum1 + 1;
		}
		carry[sizeindex++] = (sum + r) % 10 + 48;
		r = (sum + r) / 10;
	}
	carry[sizeindex] = r;
	count2 = -1;
	for (count1 = sizeindex - 1;count1 >= 0;count1--)
		mul[count2++] = carry[count1];
	mul[count2] = '\0';
	puts(mul);
}