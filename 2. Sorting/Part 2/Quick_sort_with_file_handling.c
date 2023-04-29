// Read the data from the ‘employee.txt’ file and sort on age using Counting
// sort or Quick sort and write the sorted data to another file 'sortedemponage.txt'.



#include<stdio.h>

typedef struct employee {
    char name[20];
    int age;
} emp;

emp e[20];

/*
    emp e1 , e2 ,e3, e4 ,e5 

        e1  > name, age

        e1              e2
    name, age       name age 

        e1.age  >   e2.age


    emp e[5]
        e[0]        e[1]
    name age        name age

        e[0].age   >    e[1].age;

                // e[0] > e[1]



*/


void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){   
        printf("\t%d", a[i]);
    }
    printf("\n");
}


int partition(emp a[], int low, int high){
    int pivot, i, j; 
    emp temp ;
    pivot = low;
    i = low+1;
    j = high;

    while(i<j){
        // first greater element
        while(a[i].age < a[pivot].age)
            i++;

        // first smaller element
        while(a[j].age > a[pivot].age)
            j--;

        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }         
    }

    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;

    return j;

}

void quickSort(emp a[], int low, int high){
    int partitionIndex;

    if(low<high){
        partitionIndex = partition(a, low, high);
        quickSort(a,low,partitionIndex-1);
        quickSort(a,partitionIndex+1, high);
    }
}


int main(){
    int i =0, size ;
    FILE *fp, *fp1;
    fp = fopen("employee.txt", "r");
    if(fp==NULL){
        printf("Error opening file ");
    }
    else{
        while(! feof(fp)){
            fscanf(fp, "%s %d", e[i].name, &e[i].age);
        //  fscanf(fp, "%s %d", e[i].name, e[i].age);
            i++;
        }
        fclose(fp);
        size = i;

        printf("Name and age of employees : ");
        for(i=0; i<size; i++){
            printf("\n\t%s %d", e[i].name, e[i].age);
        }

        quickSort(e,0,size-1);
        
        printf("\n\nSorted structure : ");

        fp1 = fopen("sortedemponage.txt", "w");

        for(i=0; i<size; i++){
            fprintf(fp1, "%s %d\n", e[i].name, e[i].age);
        }

            // printf("\n\t%s %d", e[i].name, e[i].age);
        fclose(fp1);

    }

    return 0; 
}