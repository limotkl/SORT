#ifndef METHODS_H
#define METHODS_H
#include <stdio.h>

//Exchange sort
void exchange(int a[],int n);

//Insertion sort
void insertion(int a[],int n);

//Merge sort
void merge_q(int a[],int head ,int tail);
void merge(int a[],int head, int mid, int tail);
void Mergesort(int a[],int head,int tail,int n);

//Random quick sort
void quicksort(int a[],int head ,int tail,int n);
void random_q(int a[],int head ,int tail);

void print_star(int a[],int n);//Print star   *** 
void print_data(int a[],int n);//Print array
#endif /* METHODS_h */
