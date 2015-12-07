#include<stdio.h>
struct test
{
	char arr1[1000];
	int count;
};
struct test testcase = { "This is a string",4 };
int check();
int main()
{
	check();
	getch();
}
int check()
{
	int strlen = 0, count1;
	char arr[1001] = " ";
	while (testcase.arr1[strlen] != '\0')
		strlen++;
	for (count1 = 0;count1 < strlen;count1++)
		arr[count1 + 1] = testcase.arr1[count1];
	for (count1 = 0;count1 < strlen;count1++)
	{
		if (arr[count1]=='s' && arr[count1+1] =='t' && arr[count1+2]=='r')
		{
			printf("String length = %d",count1);
		}
	}
}
