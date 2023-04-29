#include<stdio.h>
#include<string.h>

typedef struct city{
	char name[20];
	int code ;
}city;


void main()
{
	int i=0, n,lb,ub,flag=0,middle;
	char str[50];
	city a[50];
	FILE *fp;
	fp = fopen("sortedcities.txt", "r");
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
	//printf("n is %d",n);
	i=0;
	while(i<n-1){
		printf("%s\t%d\n",a[i].name,a[i].code);
		i++;
	}

	printf("Enter name of city to search: ");
	scanf("%s",str);

	lb=0,ub=n-2;
	while(lb  ub){
		middle = (lb+ub)/2;
		if(strcmp(a[middle].name, str) == 0){
			flag=1;
			break;
		}
		else if(strcmp(str, a[middle].name)<0){
			ub = middle-1;
		}
		else if(strcmp(str, a[middle].name)>0){
			lb = middle+1;
		}
	}

	if(flag==1){
		printf("City code is : %d\n", a[middle].code);
	}
	else{
		printf("City not in the list.\n");
	}


}
