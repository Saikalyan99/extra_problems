#include<stdio.h>
struct test
{
	int varX, varY;
};
struct test testcase[3] = { { 5,6 },{ -5,-6 },{ -2,2 } };
int multi1(int m, int n);
int multi2(int m, int n);
int main()
{
	int varX, varY, stcount;
	for (stcount = 0;stcount < 3;stcount++)
	{
		varX = testcase[stcount].varX;
		varY = testcase[stcount].varY;
		printf("Test case %d\n\nEntered numbers are %d and %d", stcount + 1, varX, varY);
		multi2(varX, varY);
		multi1(varX, varY);
	}
	getch();
}
int multi1(int varX, int varY)
{
	int index = 0, res = 0, count1, count2, x = varX, y = varY;   //x and y are to store values for printing only 
	if (varX < 0)
	{
		index++;
		varX = -varX;
	}
	if (varY < 0)
	{
		index++;
		varY = -varY;
	}
	for (count1 = 0;count1 < varY;count1++)
		for (count2 = 0;count2 < varX;count2++)
			res++;
	if (index % 2 != 0)
		res = -res;
	printf("\nMultiplication of %d and %d using increment operator = %d\n\n", x, y, res);
	return 0;
}
int multi2(int varX, int varY)
{
	int res = 0, index = 0, x = varX, y = varY;             //x and y are to store values for printing only 
	if (varX<0)
	{
		varX = -varX;
		index++;
	}
	if (varY<0)
	{
		varY = -varY;
		index++;
	}
	while (varY != 0)
	{
		if (varY & 1)
		{
			res = res + varX;
		}
		varX <<= 1;
		varY >>= 1;
	}
	if (index % 2 != 0)
		res = -res;
	printf("\nMultiplication of %d and %d using bit operator       = %d", x, y, res);
	return 0;
}
