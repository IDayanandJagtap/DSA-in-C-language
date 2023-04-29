// Read data from file and sort on names in alphabetical order 

#include<stdio.h>
#include<string.h>

typedef struct employee{
	char name[20];
}emp;
emp e[50];


void selectionSort(emp *e, int n);
void bubbleSort(emp *e, int n);

void main(){
	
	int i=0, n;
	FILE *fp;
	fp = fopen("employees.txt", "r");
	if(fp == NULL){
		printf("Error opening file !");
	}
	else{
		
		while(!(feof(fp))){
			fscanf(fp, "%s", e[i].name);
			i++;
		}	
		fclose(fp);
		
		n=i-1;
		
		
		//selectionSort(e,n);
		bubbleSort(e,n);
	
		printf("Sorted Structure is : \n");
		for(i=0; i<n; i++){
			printf("%s\n", e[i].name);
		}
		printf("\n");
	
	}
}

void selectionSort(emp e[50], int n){
	int i,j,temp, min, x=n+1;
	
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<=n-1; j++){
			if(strcmp(e[j].name , e[min].name) < 0){
				min = j;
			}
		}
		if(i != min){
			strcpy(e[x].name ,e[i].name);
			strcpy(e[i].name, e[min].name);
			strcpy(e[min].name, e[x].name);
			
		}
	}
}

void bubbleSort(emp e[50], int n){
	int i, j, x=n+1;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(strcmp(e[j].name,e[j+1].name)>0){
				strcpy(e[x].name ,e[j].name);
				strcpy(e[j].name, e[j+1].name);
				strcpy(e[j+1].name, e[x].name);
			}
		}
	}

}
