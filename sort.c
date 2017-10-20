#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "methods.h"
#define MAX 1000

int main(int argc, char const *argv[])
{
	int i,n;
	int sort[MAX];
	char ch='v';
	srand(time(NULL));
	while(1)
	{
		printf("input how many numbers you want to sort\n");
		while(scanf("%d",&n)==1)// Error check
		{
			if(n<=0||n>MAX)
				printf("ERROR:input number illegal(0<n<1000)\nreinput:\n");
			else 
				break;
		}

		printf("%d number to be sorted,input data:\n",n);

		if(n<=20)
		{
			for(i=0;i<n;i++)
				sort[i]= rand()%15+1;//when n≤20,range between 1 and 15
			for(i=0;i<n;i++)
				printf("%d  ",sort[i]);
			//=============================================
			printf("\n=================\n");
		}
		else
		{
			for(i=0;i<n;i++)
				sort[i]= rand()%32767+1;//when n>20,range int(32767)
			for(i=0;i<n;i++)
			printf("%d  ",sort[i]);
		printf("\n=================\n");
		}
			printf("\n======put in the sort methord you want to choose======\n\t1:exchange sort\n\t2:insertion sort\n\t3:merge sort\n\t4:randomized quick sort\n");
			scanf("%d",&i);
			switch(i)
			{
					case 1:
					exchange(sort,n); 
					printf("\n====result=====\n");
	     			print_data(sort,n);
					break;
					case 2:
					insertion(sort,n);
					printf("\n====result=====\n");
	     			print_data(sort,n);
					break;
					case 3:
					merge_q(sort,0,n-1);
					printf("\n====result=====\n");
					print_data(sort,n);
					break;
					case 4:
					random_q(sort,0,n-1);
					printf("\n====result=====\n");
					print_data(sort,n);
					break;
			}
			printf("\npress'q' to Quit,press anything else to continue\n");
			getchar();
			scanf("%c",&ch);
			if(ch=='q')
				break;
	}
		return 0;
}