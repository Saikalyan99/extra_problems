#include<stdio.h>
int base(int n);
int main()
{
	int n;
	printf("Enter the number you want in base '-2' = ");
	scanf("%d", &n);
	base(n);
	getch();
}
int base(int num)
{
	int q = 0, r, i = 0;
	char str[100];
	r = num % (-2);
	q = num / (-2);
	str[i++] = r + 48;
	while (q != 1)
	{
		r = q % (-2);
		q = q / (-2);
		if (r == -1)
		{
			q++;
			r = -r;
		}
		printf("%d", r);
		str[i] = r + 48;
		i++;
		if (q == -1)
		{
			str[i] = '1';
			str[i + 1] = '1';
			str[i + 2] = '\0';
			break;
		}
		if (q == 1)
		{
			str[i] = '1';
			str[i + 1] = '\0';
		}
	}
	r = 0;
	while (str[r] != '\0')
		r++;
	printf("the number in base '-2' %d = ", r);
	for (i = r - 1; i >= 0; i--)
		printf("%c", str[i]);
}