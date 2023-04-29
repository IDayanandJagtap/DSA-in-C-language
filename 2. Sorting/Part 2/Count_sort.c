// Count sort 


#include<stdio.h>

void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){   
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int maximum(int a[], int n){
    int i=0;
    int max = a[i];

    for(i=1; i<n; i++){
        if( a[i] > max){
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[], int n){
    int i,j,max;
    max = maximum(a,n);

//  create a temp array : 
    int count[max+1];

    // initialise count array to 0
    for(i=0 ; i<=max; i++){
        count[i] = 0;
    }

    // Check occurrences from main array 
    for(i=0; i<n; i++){
        count[a[i]] = count[a[i]] + 1;
    }

    // Insert into main array 
    i=0;        // counter for count array
    j=0;        // counter for main array 

    while(i<=max){
        if(count[i]>0){
            a[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else{
            i++;
        }
    }



}


int main(){
    int arr[] = {4 , 6 ,  8 , 3 , 7 , 4 , 11 , 1};   
    int low=0 , high = 8;

    // quickSort(arr, low, high-1);
    //mergeSort(arr, low, high);
    countSort(arr, high);
    printArray(arr, high);

    return 0;  
}