#include <stdio.h>
struct test
{
	int day;
	int month;
	int year;
};
struct test testc[3] = { { 32,07,1995 },{ 29,02,2100 },{ -29,02,2000 } };
int check();
int main()
{
	check();
	getch();
}
int check()
{
	long int index, leap = 0, flag = 0;
	for (index = 0;index < 3;index++)
	{
		printf("%d %d %d\n", testc[index].day, testc[index].month, testc[index].year);
		if (testc[index].year % 400 == 0 || (testc[index].year % 100 != 0 && testc[index].year % 4 == 0))
			leap = 1;
		if (testc[index].month < 13)
		{
			if (testc[index].month == 1 || testc[index].month == 3 || testc[index].month == 5 || testc[index].month == 7 || testc[index].month == 8 || testc[index].month == 10 || testc[index].month == 12)
			{
				if (testc[index].day > 0 && testc[index].day <= 31)
				{
					flag = 1;
					printf("yes %d %d ", testc[index].day, flag);
				}
			}
			else if (testc[index].month == 4 || testc[index].month == 6 || testc[index].month == 9 || testc[index].month == 11)
			{
				if (testc[index].day > 0 && testc[index].day < 31)
					flag = 1;
			}
			else
			{
				if (testc[index].day > 0 && testc[index].day < 29)
				{
					if (leap == 1)
						if (testc[index].day <= 29)
							flag = 1;
					if (leap == 0)
						if (testc[index].day <= 28)
							flag = 1;
				}
			}
		}
		if (flag == 1)
			printf("The date you have entered does exist\n");
		else
			printf("The date you have entered doesn't exist");
	}
}
