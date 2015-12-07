#include<stdio.h>
struct test
{
	int arr1[100];
};
struct test testcase;
void check(struct test t, int arr[]);
int main()
{
	int arr[] = { 21,34,54,67,8,4,32 }, count = 0;
	while (arr[count] != '\0')
	{
		testcase.arr1[count] = arr[count];
		count++;
	}
	check(testcase, arr);
	getch();
}
void check(struct test t, int arr[])
{
	int count1, count2 = 0, position = 2, element = 24;
	if (position < 0 || position>7)
		printf("ERRoR :(\nposition index wrong");
	else
	{
		for (count1 = 0;count1 < position;count1++)
			t.arr1[count2++] = arr[count1];
		t.arr1[count2++] = element;
		for (count1 = position;count1 < 7;count1++)
			t.arr1[count2++] = arr[count1];
		for (count1 = 0;count1 <= 7;count1++)
			printf("%d ", t.arr1[count1]);
		printf("\nTest case passed\n\n");
	}
}
