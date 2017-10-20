#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include "methods.h"
int count;
void print_star(int a[],int n)
{
	int x,y;
	for(x=0;x<n;x++) {
			for(y=0;y<a[x];y++)
				printf("*");
			printf("\n");
		}
}
void print_data(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}
//================EXCHANGE SORT======================
void exchange(int a[],int n)
{
	count=1;
    int x,y,temp;
	if(n<=20) {
		print_star(a,n);
		print_data(a,n);
	}
	for(x=0;x<n-1;x++) {
		for(y=x+1;y<n;y++) {
			if(a[x]>a[y]) {
				temp=a[x];//  swap 
				a[x]=a[y];
				a[y]=temp;
				if(n<=20) {
					printf("\n=========round:%d========\n",count);
					print_star(a,n);
					print_data(a,n);
                    count++;
				}
			}
		}
	}
}
//================INSERTION SORT======================
void insertion(int a[],int n){
	count=1;
    int x,y,temp;
	if(n<=20)
	{
		print_star(a,n);
		print_data(a,n);
	}
	for (x=1;x<n;x++)
	{
		if(a[x]<a[x-1])//find an element that is smaller than the element befor it;
		{
			temp=a[x];
			for(y=x-1;y>=0;y--)
			{
					if(a[y]>temp)//move elements, bigger than current one, backward;
						a[y+1]=a[y];
					else
						break;//found a element that is smaller than current one,stop;
        			a[y]=temp;

                	if(n<=20)
                	{
                		printf("\n========round:%d==========\n",count);
                		print_star(a,n);
                		print_data(a,n);
                        count++;
                	}
		    }
	   }
    }
}
//================MERGE SORT========================
void merge(int a[],int head, int mid, int tail){
       
        int l = mid-head+1, r = tail-mid;
        int left[l+1], right[r+1]; //extra space needed;
        int i;
        for(i=0; i< l; i++)//copy array into left[] and right[];
        {
            left[i] = a[head+i];
        }
        for (i=0; i< r; i++)
        {
            right[i] = a[mid+1+i];
        }
        left[l] = 32767;
        right[r] = 32767;        
        l = 0;
        r = 0;
        for(i=0; i< tail-head+1; i++)//array a[] is the sorted merge of left[] & right[];
       {
            
                if(left[l] < right[r])
                {
                    a[head+i] = left[l];
                    l ++;
                }
                else { 
                        a[head+i] = right[r];
                        r ++;
                }
        }
}

void Mergesort(int a[],int head,int tail,int n){
    int mid;
	if(head!=tail)//divide the array;
	{
		mid=(head+tail)/2;
		Mergesort(a,head,mid,n);//recursive call;
		Mergesort(a,mid+1,tail,n);
		merge(a,head,mid,tail);
         if(n!=-1)
        {
            printf("\n=========round:%d==========\n",count);
            print_star(a,tail+1);
            print_data(a,tail+1);
            count++;
        }
	}

}

void merge_q(int a[],int head ,int tail)
{
    count=1;
    int n;//Add contral variable 'n' to contral star printing;
    if(tail<20)
        n=tail;
    else 
        n=-1;
    Mergesort(a,head,tail,n);

}

//================QUICK SORT=========================
void quicksort(int a[],int head ,int tail,int n)
{
    srand(time(NULL));
    int temp;
    int x=head;
    int y=head+1;
    int fin=0;

    int rand_=head+rand()%(tail-head+1);//set a random number as pivot element;
    temp=a[rand_];
    a[rand_]=a[head];
    a[head]=temp;

    int pivot=a[head];
    if(head>=tail) return;
    while(y<=tail) 
    {
        if(a[x]==a[y]) //bigger one as pivot element;
        {
            x++;
            y++;
        }
        else
        {
            if(a[x]>a[y])
                pivot=a[x];
            if(a[x]<a[y])
                pivot=a[y];
            fin=1;
            break;
        }
    }
    if(!fin)return;
    x=head;
    y=tail;
    //x,y point to head and tail of the array;
    while(x<=y)
    {
        while(a[x]<pivot)x++;
        while(a[y]>=pivot)y--;
        if(x<y) 
        {
            temp=a[x];//swap elements;
            a[x]=a[y];
            a[y]=temp;
        }
    }

    if(n!=-1)
    {
        printf("\n=====round:%d,pivot=%d=======\n",count,pivot);
        print_star(a,tail+1);
        print_data(a,tail+1);
        count++;
    }
    quicksort(a,head,y,n);
    quicksort(a,x,tail,n);
    return;

}
void random_q(int a[],int head ,int tail)
{
    count=1;
    int n;//Add contral variable 'n' to contral star printing
    if(tail<20)
        n=tail;
    else 
        n=-1;
    quicksort(a,head,tail,n);

}



