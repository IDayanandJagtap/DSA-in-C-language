// Read the data from the ‘employee.txt’ file and sort on age using Counting
// sort or Quick sort and write the sorted data to another file 'sortedemponage.txt'.



#include<stdio.h>
#include<string.h>

typedef struct employee {
    char name[20];
    // int age;
} emp;

emp e[20];




void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){   
        printf("\t%d", a[i]);
    }
    printf("\n");
}


void merge(emp a[], int mid, int low, int high){
    int i=low, j=mid+1, k=low;
    emp B[high+1];

//    3   5  | 7   9
    while(i<=mid && j<=high){
        if(strcmp(a[i].name , a[j].name)<=0){
            B[k] = a[i];
            i++ ; k++;
        }
        else{
            B[k] = a[j];
            j++; k++;
        }
    }
    while(i<=mid){
        B[k] = a[i];
        i++; k++;
    }
    while(j<=high){
        B[k] = a[j];
        j++; k++;
    }

    // printf("Value of k is  : %d\n", k);
    // printf("Value of high is  : %d\n\n", high);
    
    for(i=low; i<=high; i++)
        a[i] = B[i];
}

void mergeSort(emp a[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;

        mergeSort(a,low, mid);
        mergeSort(a,mid+1, high);

        merge(a,mid,low,high);
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
            fscanf(fp, "%s", e[i].name);
        //  fscanf(fp, "%s %d", e[i].name, e[i].age);
            i++;
        }
        fclose(fp);
        size = i;

        printf("Name and age of employees : ");
        for(i=0; i<size; i++){
            printf("\n\t%s", e[i].name);
        }

        mergeSort(e,0,size-1);
        
        printf("\n\nSorted structure : ");

        fp1 = fopen("sortedemponage.txt", "w");

        for(i=0; i<size; i++){
            fprintf(fp1, "%s\n", e[i].name);
        }

            // printf("\n\t%s %d", e[i].name, e[i].age);
        fclose(fp1);

    }

    return 0; 
}