#include<stdio.h>
#include<string.h>
int converter(char str[]);
int main()
{
	char str[100] = "001010011100";
	printf("Entered binary number : ");
	puts(str);
	converter(str);
	getch();
}
int converter(char str[])
{
	int i, x = 1, j = 0, r = 0, dec[10] = { 0 };	
	while (str[r] != '\0')
		r++;
	for (i = r-1; i >= 0; i--)
	{
		dec[j] = ((str[i] - '0') * x) + dec[j];
		x = x * 2;
		if (x == 8)
		{
			j++;
			x = 1;
		}
	}
	printf("Equivalent octal number : ");
	for (i = j-1; i >= 0; i--)
		printf("%d", dec[i]);
}