// Sort an array using bubble sort 

/**
 In every iteration (pass) largest elements are moved to their proper place
 At end like a bubble 
 So it is called as bubble sort
*/



#include<stdio.h>

void bubbleSort(int arr[], int n){
    int i , j ,temp;

    for(i=0; i<n-1; i++){                   // NO of passes
        for(j=0; j < n-i-1; j++){           //To compare elements in every pass
            if(arr[j]>arr[j+1]){
                temp = arr[j] ;
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
     }
}


int main(){
    int arr[] = {1,5,2,67,23, 54 ,97, 3};
    int n = sizeof(arr)/ sizeof(int);

    bubbleSort(arr, n);


    printf("Sorted array : ");
    for(int i = 0 ; i<n; i++){
        printf("\t%d", arr[i]);
    }

    return 0; 
}