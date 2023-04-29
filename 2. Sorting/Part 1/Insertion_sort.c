// Sort an array using insertion sort 
/*
    We start from one element array 
    We sort it     
    And keep inserting  next element in this sorted array 
    After every iteration one smallest element is inserted at its proper position

        1 5 2 67 23 54 97 3
1st     1
2       1 5
3       1 5 2
          j i

        1 5 5
        j
    
    j=1 (Key) = 2
        1 2 5 67


*/


#include<stdio.h>

void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){   
        printf("\t%d", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n){
    int i,j,key;
    for(i=1; i<n; i++){
        key = a[i];                 // element to be inserted

        j = i-1;                    
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;

    }
}

int main(){
    int arr[] = {1,5,2,67,23, 54 ,97, 3};
    int n = sizeof(arr)/ sizeof(int);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0; 
}