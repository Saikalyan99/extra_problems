#include <stdio.h>
struct test
{
	char arr[40];
};
struct test testcase[3] = { "8/02/1995","18 02 2005","10/1/1992" };
int convert(unsigned char arr[],int strlen);
int check(int d, int m, int y);
int print(int date, int  month, int year);
int printdate(int date);
int printmonth(int month);
int printyear(int year);
int main()
{
	char arr[40];
	int i, strlen, j=0;
	for (j = 0;j < 3;j++)
	{
		printf("Test case %d\n\n",j+1);
		strlen = 0;
		while (testcase[j].arr[strlen] != '\0')
			strlen++;
		for (i = 0;i < strlen;i++)
			arr[i] = testcase[j].arr[i];
		convert(arr, strlen);
	}
	getch();
}
int convert(unsigned char arr[],int strlen)
{
	long int i, j, temp[3] = { 0 }, flag = 0, position = 0;
	for (i = 0;i<strlen;i++)
	{
		if (arr[i] > 47 && arr[i] < 58)
		{
			for (j = 0;j < 10;j++)
			{
				if (arr[i] == (j + 48))
				{
					temp[position] = temp[position] + j;
					if (arr[i + 1] == '/' || arr[i + 1] == '\0')
						break;
					else
						temp[position] = temp[position] * 10;
					break;
				}
			}
		}
		else if (arr[i] == '/')
			position++;
		else
			flag++;
	}
	if (flag == 0)
	{
		printf("%d/%d/%d\n", temp[0], temp[1], temp[2] / 10);
		check(temp[0], temp[1], temp[2] / 10);
	}
	else
		printf("Error!! Entered invalid data!\n\n");
	return 0;
}
int check(int day,int month,int year)
{
	long int leap = 0, flag = 0;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		leap = 1;
	if (month<13)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 1 || day < 32)
				flag = 1;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 31)
				flag = 1;
		}
		else
		{
			if (leap == 1)
				if (day <= 29)
					flag = 1;
			if (leap == 0)
				if (day <= 28)
					flag = 1;
		}
	}
	if (flag == 1)
		print(day, month, year);
		else
			printf("The date you have entered doesn't exist \n\n");
		return 0;
}
int print(int date, int  month, int year)
{
	printf("The entered date is '");
	printdate(date);
	printmonth(month);
	printyear(year);
	return 0;
}
int printdate(int date)
{
	int a[2] = {0}, i = 0;
	const char *digits1[10] = { "","first","second","third","fourth","fifth","sixth","seventh","eighth","ninth" };
	const char *digits2[10] = { "tenth","eleventh","twelveth","thirteenth","fourteenth","fifteenth","sixteenth","seventeenth","eighteenth","nineteenth" };
	const char *tens[4] = { "","","twenty","thirty" };
	while (date != 0)
	{
		a[i] = date % 10;
		date = date / 10;
		i++;
	}
	if (a[1] == 1)
		printf("%s", digits2[a[0]]);
	else if (a[1] == 0)
		printf("%s", digits1[a[0]]);
	else
		printf("%s %s", tens[a[1]], digits1[a[0]]);
	return 0;
}
int printmonth(int month)
{
	const char *months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	printf(" %s of",months[month-1]);
	return 0;
}
int printyear(int year)
{
	int a[4], i = 0;
	const char *digits1[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	const char *digits2[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char *tens[10] = { "","","twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety" };
	const char *power[1] = { "thousand" };
	while (year != 0)
	{
		a[i] = year % 10;
		year = year / 10;
		i++;
	}
	if (a[2] == 0)										//thousands and hundred place is printed first.
		printf(" %s %s ", digits1[a[3]], power[0]);
	else if (a[3] == 1)
		printf(" %s ", digits2[a[2]]);
	else
		printf(" %s %s ", tens[a[3]], digits1[a[2]]);
	if (a[1] == 1)										//now tens and units place is printed.
		printf("%s'", digits2[a[0]]);
	else
		printf("%s %s'", tens[a[1]], digits1[a[0]]);
	printf("\n\n");
	return 0;
}
