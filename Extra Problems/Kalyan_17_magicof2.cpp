#include<stdio.h>
void function(long int a, int mult);
void gen();
int main()
{
	printf("The magic numbers are : \n");
	gen();
	getch();
}
void gen()
{
	long int temp = 100000;
	while (1)										//this is infinite loop
	{
		if (temp*2 > 200000)						//the Minimum posible ans of (6-digit * num) is 200000. This to avoid unnecessary cases
		{
			if (temp*2 >= 1000000)					//checking ans of (6-digit * num) is below 6 digit or not
				break;
			function(temp*2, 2);					//calling function
		}
		temp = temp + 2;
	}
}
void function(long int num, int mult)				//this function decides the number is a magic number or not
{
	int temparr[10] = { 0 }, index, flag = 1;
	long int temp = num;
	temp = num / mult;								//retrieving the initial 6-digit number
	if (temp*mult == num)
	{
		for (index = 0;index < 6;index++)
		{
			temparr[temp % 10]++;					//setting the count of the each 6-digit number to the array
			temp = temp / 10;
		}
		temp = num;
		for (index = 0;index < 6;index++)			//this loop compares every digit with intial number
		{
			if (temparr[temp % 10] == 0)
			{
				flag = 0;							//if the given number is not a magic number the flag will be zero
				break;
			}
			temp = temp / 10;
		}
		if (flag == 1)
		{
			printf("%lu\t", num / mult);
		}
	}
}
