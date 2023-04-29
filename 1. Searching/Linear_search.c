// Linear search in array 

#include<stdio.h>

void main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10}, val, flag=0, i;
	printf("Enter a value to search in array : ");
	scanf("%d", &val);

	for(i=0; i<10; i++){
		if(arr[i] == val){
			flag=1;
			break;
		}
	} 

	if(flag==1){
		printf("Data found at %d position\n", i+1);
	}
	else{
		printf("Data not found\n");
	}


}
