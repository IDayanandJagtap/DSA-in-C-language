// Sort using quick sort
/*
index =>    0  1  2  3  4  5  6   7
ele   =>    4  6  8  3  7  4  11  1
     pivot =^  ^=low              ^= high


    ************************ WORKING ***********************

                !elems :         4  6  8  3  7  4  11  1

        todo:  1st iteration 
                !               4   6   8   3   7   4   11  1
                           pivot^   i                       j
                                    ---->                <---                           //j = until first smallest number than pivot
                |                                                                      //i = until first greater number than pivot
                !               4   6   8   3   7   4   11  1
                                    i                       j
                #               swap i & j
                !               4   1   8   3   7   4   11  6 
                                        i           j

                !               4   1   4   3   7   8   11  6 
                                            j   i   


                !               3   1   4   4   7   8   11  6 
                                            j

                                            return         

                !               3   1   4                     7   8   11  6       
                                    j   i                         i        j

                !               1   3   4                     7   6   11   8    
                                                                  i         j

                !                                             7   6   11    8
                                                                  j    i

                !                                             6   7   11    8
                                                                  j    i

                !                                                  11   8
                                                                    p   ij

                !                                                   8   11 
                                                                        j

                !               1   3   4   4   6   7   8   11


    ********************************************************

    1. i = low
    2. j = high
    3. pivot = low
    4. i++ until element > pivot is found.
    5. j-- until element < pivot is found.
    6. swap A[i] & A[j] ...
        repeat 4 and 5 until j<=i
    7. swap pivot & A[j]

*/

#include <stdio.h>

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

int partition(int a[], int low, int high)
{
    int i, j, pivot, temp;
    pivot = low;
    i = low + 1;
    j = high;

    do
    {

        while (a[i] <= a[pivot])
            i++;

        while (a[j] >= a[pivot])
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {

        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);  //left array
        quickSort(a, partitionIndex + 1, high); // right array
    }
}

int main()
{
    int a[] = {43, 1, 62, 95, 22, 15};
    int n = 6;
    printArray(a, n);
    quickSort(a, 0, n-1);
    printArray(a, n);

    return 0;
}