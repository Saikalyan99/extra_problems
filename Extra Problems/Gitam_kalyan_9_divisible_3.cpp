#include<stdio.h>
#include<malloc.h>
struct test
{
	char str[1000];
	int repeat;
};
struct test testcase[3] = { { "121",3 },{ "213",7 },{ "4123516",2 } };
void divisible(char *str, int strlen, int repeat);
int main()
{
	int strlen = 0, stcount = 0, len = sizeof(char), size = 0, repeat, index;
	char *str, ch;																		//character pointer
	str = (char*)malloc(len);															//memory allocation
	size = len;
	for (stcount = 0;stcount < 3;stcount++)												//loop for testcases
	{
		printf("Test case %d\n\nEntered number = ", stcount + 1);
		puts(testcase[stcount].str);
		while (testcase[stcount].str[strlen] != '\0')									//counting string length manually
			strlen++;
		if (str != NULL)
		{
			index = 0;
			while ((ch = testcase[stcount].str[index]) != '\n')
			{
				str[index++] = ch;
				if (index == size)														//reallocate memory if needed
				{
					size = index + len;
					str = (char*)realloc(str, size);
				}
			}
		}
		repeat = testcase[stcount].repeat;
		divisible(str, strlen, repeat);													//calling function
		printf("\n\n");
	}
	free(str);																			//freeing memory
	getch();
}
void divisible(char *str, int strlen, int repeat)
{
	int count1, flag = 0, count2, add = 0;
	for (count1 = 1;count1 < repeat;count1++)											//loop for repeatition
		for (count2 = strlen - 1;count2 > -1;count2--)
			str[(strlen*count1) + count2] = str[count2];
	while (str[strlen] != '\0')															//counting string length manually for new string
		strlen++;
	printf("Repetition value = %d\nString = ", repeat);
	puts(str);
	for (count1 = strlen - 1;count1 > -1;count1--)										//loop for incrementing position in string
	{
		if (str[count1] > 47 && str[count1] < 58)										//checking whether string contains numbers or not
		{
			for (count2 = 0;count2 < 10;count2++)										//loop
			{
				if (str[count1] == (count2 + 48))										//finding equivalent number present in string
				{
					add = add + count2;													//adding all the numbers in string
					break;
				}
			}
		}
		else
			flag++;																		//if string contains anyother character other than numbers flag++
	}
	if (flag < 1)																		//printing block
	{
		if (add % 3 == 0)																//checking its divisible by 3 or not
			printf("the number is divisible by 3");
		else
			printf("the number isn't divisible by 3");
	}
	else
		printf("Error in input!");
}
