// Read cities.txt containing name and code of cities ... accept city name from user and use sentinal linear search algo 

#include<stdio.h>
#include<string.h>

typedef struct city{
	char name[20];
	int code ;
}city;

void main(){
	int i=0, n;                                        
	char str[50];
	city a[50];
	FILE *fp;
	fp = fopen("cities.txt", "r");
	if(fp==NULL){
		printf("Error opening file !"); 
	}
	else{
		while(!(feof(fp))){
			fscanf(fp,"%s %d", a[i].name, &a[i].code);
			i++;		
		}
		fclose(fp);
		
	}
	n=i;
	i=0;                                                                                                                                                                                                                                                                                                                                                                                                            
	while(i<n){
		printf("%s\t%d\n",a[i].name,a[i].code);
		i++;
	}

	printf("Enter name of city to search: ");
	scanf("%s",str);
	strcpy(a[n].name, str);

	i=0;
	while(strcmp(a[i].name,str)!=0){
		i++;
	} 
	if(i<n){
		printf("City code is : %d\n", a[i].code);
	}
	else{
		printf("Entered city is not present in file\n");
	}


}
