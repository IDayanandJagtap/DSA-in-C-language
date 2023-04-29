// Count sort 


#include<stdio.h>
#include<string.h>

typedef struct employee{
    char name[20];
    int age; 
}emp;

emp c[20];


void printArray(int a[], int n){
    printf("Elements : ");
    for(int i=0; i<n; i++){   
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int maximum(emp a[], int n){
    int i=0;
    int max = a[i].age;

    for(i=1; i<n; i++){
        if( a[i].age > max){
            max = a[i].age;
        }
    }
    return max;
}

void countSort(emp a[], int n){
    int i,j,max;
    max = maximum(a,n);

//  create a temp array : 
    emp count[max+1];

    // initialise count array to 0
    for(i=0 ; i<=max; i++){
        count[i].age = 0;
    }

    // Check occurrences from main array 
    for(i=0; i<n; i++){
        strcpy(count[a[i].age].name , a[i].name);
        count[a[i].age].age = count[a[i].age].age + 1;
        // count [47].age = count[47].age++
    }

    // Insert into main array 
    i=0;        // counter for count array
    j=0;        // counter for main array 

    while(i<=max){
        if(count[i].age >0){
            strcpy(a[j].name , count[i].name);
            a[j].age = i;

            count[i].age = count[i].age -1;
            j++;
        }
        else{
            i++;
        }
    }



}


int main(){
    int i=0, size, code;
    char str[20];
    FILE *fp;
    fp = fopen("cities.txt", "r");
    if(fp==NULL){
        printf("Error op file ");
    }
    else{
        while(!feof(fp)){
            fscanf(fp, "%s %d", c[i].name, &c[i].code);
            i++;
        }
        size = i;

        printf("cities : \n");
        for(i=0; i<size; i++){
            printf("\n\t%s", c[i].name);
        }

        printf("Enter the name of city : ");
        scanf("%s", str);

        strcpy(c[size].name, str);

        i = binarySearch(c, size, str);

        if(i==-1){
            printf("City not found !");
        }
        else{
            printf("code of %s is : %d\n", c[i].name, c[i].code);
        }




    } 
}