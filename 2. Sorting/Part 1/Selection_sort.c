// Sort an array using selection sort

/*
    In first iteration we find smallest element in array and swap it with first element;
    And then 
    In every next iteration ... we find next smallest element (which will be ofc greater that previous smallest elment)
    And insert it at proper position

    So 
    we select the smallest element and insert it at proper position so it is called selection sort;
*/

#include<stdio.h>

void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){
        printf("\t%d", a[i]);
    }
    printf("\n");
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b  = temp;
}

void selectionSort(int a[], int n){
    int min, temp, i, j;

    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }  
        if(min != i){
            temp = a[i] ; 
            a[i] = a[min];
            a[min] = temp;
        }

    }
}

int main(){
    int arr[] = {1,5,2,67,23, 54 ,97, 3};
    int n = sizeof(arr)/ sizeof(int);

    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);

    return 0; 
}