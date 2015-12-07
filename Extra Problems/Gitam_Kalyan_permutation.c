#include <stdio.h>
void sort(char *str);
void permute(char *a, int l, int r);
void swap(char *x, char *y);
int main()
{
	char str[] = "87654321";
	sort(str);
	getch();
}
void sort(char *str)
{
	int strlen = 0, x, y, temp;
	while (str[strlen] != '\0')
		strlen++;
	for (x = 0; x < strlen; x++)
		for (y = 0; y < strlen - 1; y++)
			if (str[y]>str[y + 1])
			{
				temp = str[y + 1];
				str[y + 1] = str[y];
				str[y] = temp;
			}
	permute(str, 0, strlen - 1);
}
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
	{
		printf("%s\n", a);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i));
		}
	}
}
void swap(char *x, char *y)
{
	char temp_for_sort;
	temp_for_sort = *x;
	*x = *y;
	*y = temp_for_sort;
}