#include<stdio.h>
int modulo1(long unsigned x, long unsigned y, long unsigned a);
int main()
{
	long unsigned x,y,a,z;
	printf("Enter the values of x,y,a : ");
	scanf("%lu %lu %lu", &x, &y, &a);
	z = modulo1(x, y, a);
	printf("\nResult = %lu\n",z);
	getch();
}
int modulo1(long unsigned x, long unsigned y, long unsigned a)
{
	long unsigned num[100], temp[100], bin[100], index = 0, index1, multi = 1, rem, k = 1;
	while (y != 0)
	{
		rem = y % 2;
		y = y / 2;
		temp[index] = rem;
		num[index++] = multi;
		multi = multi * 2;
	}
	rem = index;
	for (index1 = 0;index1 < rem;index1++)
		bin[index1] = temp[--index];
	multi = x;
	for (index = 0;index < rem;index++)
	{
		if (bin[index] == 1)
		{
			multi = multi%a;
			k = k*multi;
			for (index1 = 0;index1 < num[index];index1++)
				multi = multi*x;
		}
	}
	return k%a;
}
