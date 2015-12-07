#include<stdio.h>
struct test
{
	char str[50];
};
struct test testcase = { "hello world" };
void check();
int main()
{
	check();
	getch();
}
void check()
{
	int index = 0, strlen = 0, arr[256];
	while (testcase.str[strlen] != '\0')
		strlen++;
	for (index = 0;index < 256;index++)
		arr[index] = 0;
	if (strlen<1)
		printf("ERROR!! size of array is less than 1");
	else
	{
		for (index = 0;index<strlen;index++)
			arr[testcase.str[index]]++;
		for (index = 0;index < 256;index++)
			if (arr[index]>0)
				printf("%c has repeated %d times\n", index, arr[index]);
	}
}
