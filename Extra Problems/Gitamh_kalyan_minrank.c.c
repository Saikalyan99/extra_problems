#include<stdio.h>
struct test
{
	char str[1000];
};
struct test testcase[3] = { "123","213","412356" };
int fact(int n);
int combinations(char str[], int index1, int index2);
int minrank(char str[]);
int main()
{
	int rank,stcount;
	for (stcount = 0;stcount < 1;stcount++)
	{
		printf("Test case %d\n\nEntered number = ", stcount+1);
		puts(testcase[stcount].str);
		rank = minrank(testcase[stcount].str);
		printf("Min rank = %d\n\n\n", rank);
	}
	getch();
}
int minrank(char str[])
{
	int strlen = 0, nocombi, rank = 1, count, index;
	while (str[strlen] != '\0')
		strlen++;
	nocombi = fact(strlen);
	for (index = 0;index<strlen;index++)
	{
		nocombi = nocombi / (strlen - index);
		count = combinations(str, index, strlen - 1);
		rank = rank + count*nocombi;
		printf("\n%d %d %d %d\n",str[index],index,nocombi,rank);
	}
	return rank;
}
int fact(int strlen)
{
	if (strlen == 0 || strlen == 1)
		return 1;
	else
	{
		strlen = strlen*fact(strlen - 1);
		return strlen;
	}
}
int combinations(char str[], int index1, int index2)
{
	int count = 0, index;
	for (index = index1 + 1;index <= index2;++index)
		if (str[index] < str[index1])
		{
			printf("\nsyess\n");
			count++;
		}
	return count;
}
