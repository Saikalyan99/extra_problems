#include<stdio.h>
int main()
{
	FILE *fp1;														//file pointer
	char str[200];
	int count = 0, index = 0, N_lastlines;
	fp1 = fopen("sample.txt", "r");									//taking file name as sample.txt
	if (fp1 == NULL)												//checking for the file
	{
		printf("File not found");
		return;
	}
	printf("\nHow many lines to read from the end = ");
	scanf("%d", &N_lastlines);
	while (fgets(str, 200, fp1) != NULL)							//counting
		count++;
	printf("\nNumber of lines in file = %d", count);				//printing number of lines in file
	rewind(fp1);
	while (index<count - N_lastlines)								//copying last line into string
	{
		fgets(str, 200, fp1);
		index++;
	}

	index = 0;
	printf("\nlast %d lines in the file are : \n", N_lastlines);
	while (index<N_lastlines)
	{
		fgets(str, 200, fp1);
		printf("%d %s", (index++) + 1, str);
	}

	fclose(fp1);													//closing the file
	getch();
}
