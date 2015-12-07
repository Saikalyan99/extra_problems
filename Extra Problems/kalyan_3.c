#include<stdio.h>
struct test
{
	char arr1[1000];
	int count;
};
struct test testcase = { "This is a string",4 };
check();
int main()
{
	check();
	getch();
}
check()
{
	int strlen = 0, count1, spacecount = 0,wordcount=0;
	char arr[1001] = " ";
	while (testcase.arr1[strlen] != '\0')
		strlen++;
	for (count1 = 0;count1 < strlen;count1++)
		arr[count1 + 1] = testcase.arr1[count1];
	for (count1 = 0;count1 < strlen;count1++)
	{
		if (arr[count1]>96 && arr[count1] < 123 || arr[count1]>64 && arr[count1] < 91)
		{
			if (spacecount > 0)
				wordcount++;
			spacecount = 0;
		}
		else
		{
			spacecount++;
		}
	}
	if(testcase.count==wordcount)
		printf("pass");
	else
		printf("fail");
}
