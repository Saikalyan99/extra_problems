#include<stdio.h>
#include<string.h>
struct test
{
	unsigned char x[1000];
	unsigned char y[1000];
};
struct test testcase[2] = { "12001201020000111222","00000000111111222222" };
int sumofdigits();
int main()
{
	sumofdigits();
	getch();
}
int sumofdigits()
{
	long int  arr[1000][1], flag = 0, count1, count2, position1, position2 = 0, temp = 0;
	for (position1 = 0;position1 < 2;position1++, temp++)
		for (count1 = 0;count1<strlen(testcase[position1].x);count1++)
		{
			if (testcase[position1].x[position1]>47 && testcase[position1].x[count1]<51)
			{
				for (count2 = 0;count2 < 10;count2++)
				{
					if (testcase[position1].x[count1] == (count2 + 48))
					{
						arr[position2][temp] = count2;
						++position2;
						break;
					}
				}
			}
			else
				flag++;
		}
	if (flag>0)
		printf("You have entered another character other than 0,1 and 2");
	else
	{
		for (count2 = 0;count2 < position2;count2++)
		{
			for (count1 = 0;count1 < position2;count1++)
			{
				if (arr[count1][0] > arr[count1 + 1][0])
				{
					temp = arr[count1][0];
					arr[count1][0] = arr[count1 + 1][0];
					arr[count1 + 1][0] = temp;
				}
			}
		}
		flag = 0;
		for (count2 = 0;count2 < position2;count2++)
		{
			if (arr[count2][0] == arr[count2 - 1][1])
				flag++;
		}
	}
	if (flag == strlen(testcase[0].x))
		printf("pass");
	else
		printf("fail");
}
