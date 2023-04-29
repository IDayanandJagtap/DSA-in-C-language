/*
    index =>    0  1  2  3  4  5  6   7
    ele   =>    4  6  8  3  7  4  11  1
        
            
            !    4  6  8  3 |  7  4  11  1 
                left part    right part

            !   4   6   |  8   3                        7    4   |   11     1 
                left        right                       left            right


            !   4  |  6             8  |   3                    7   |   4               11      |       1

            #  Now sorting begins 
                        compare elements on left(i) and right(j)

        todo:   ***** 1 ****
        !                   4  |  6             8  |   3                    7   |  4               11  |   1
                            i     j             i      j                    i       j               i       j

        # Temp array: B     4  6                3  8                         4  7                   1   11
        * Copy to original: 

        !              4   6     |        3   8                   4   7        |         1    11 


        todo:   ***** 2 ****

        !                4    6      |    3    8                   4    7      |      1    11 
                         i                j                        i                  j

        !                4    6      |    3    8                   4    7      |      1    11 
                         i                     j                   i                        j

        !                4    6      |    3    8                   4    7      |      1    11 
                              i                j                        i                   j

        #temp B          3    4    6     8            |            1    4    7     11
        copy to original 


        todo:   ***** 3 **** 

        !                3    4    6     8            |            1    4    7     11
                         i                                         j

        !                3    4    6     8            |            1    4    7     11
                         i                                              j

        !                3    4    6     8            |            1    4    7     11
                              i                                         j

        !                3    4    6     8            |            1    4    7     11
                                   i                                    j

        !                3    4    6     8            |            1    4    7     11
                                   i                                         j

        !                3    4    6     8            |            1    4    7     11
                                         i                                   j

        !                3    4    6     8            |            1    4    7     11
                                         i                                          j

        !                3    4    6     8            |            1    4    7     11
                                         i                                          j

        # temp B:        1    3    4     4     6     7       8      11
        copy to original

        And in this way our array will be sorted 






                

   
    MergeSort functioon : 
        1. find mid ;
        2. run mergeSort for left side 
        3. run mergeSort for right side 
        4. merge the array


    Merge function : 
        1. i=low  ...  j= mid+1

        2. while(i<=mid && j<=high)
            compare a[i] & a[j] and insert smaller element into b[k] 
            increment accordingly 
        
        3. while(i<=mid)
        3. while(j<=high)       to insert remaining elements 

        4. copy elements from b[] to a[]

*/



#include<stdio.h>



void merge(int a[], int mid, int low , int high){
    int i,j,k, b[high+1];
    i= low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(a[i] <= a[j]){
            b[k] = a[i];
            k++; 
            i++;
        }
        else{
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
        b[k] = a[i];
        k++ ; i++;
    }
    while(j<=high){
        b[k] = a[j];
        k++ ; j++;
    }

    for(i=low ; i<=high; i++){
        a[i] = b[i];                        // remember bounds ... this isn't for whole array ... for parts of array ... 
    }
}


void mergeSort(int a[], int low, int high){
    int mid;
    if(low < high){
        mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,mid, low , high);
    }
}



void printArray(int a[], int n)
{
    int i;
    printf("Data elements : ");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int main(){
    
    int a[] = {4, 6, 8, 3, 7, 4, 11, 1};
    int high =8;
    int low = 0;
    printArray(a, high);
    mergeSort(a, low, high);
    printArray(a, high);

    return 0; 
}