#include<stdio.h>
int main()
{
     FILE *fp1;
     char str[200]; 
     int count=0, j, n;
     fp1 = fopen("sample.txt", "r");
     if(fp1==NULL)
     {
     	printf("File not found");
     	return;
	 }
     printf("\nHow many lines to read from the end: ");
	 scanf("%d", &n);
     while(fgets(str, 200, fp1) != NULL)
     count++;
     j=0;
     printf("\n No. of lines = %d", count);
     rewind(fp1);
     while(j<count-n){	
       fgets(str, 200, fp1);
       j++;
   }
    
    j=0;
    printf("\n last\n");
    while(j<n)
    {
    	fgets(str, 200, fp1);
    	printf("%s", str);
    	j++;
	}   
	     
    fclose(fp1);
    
    return 0;
}

