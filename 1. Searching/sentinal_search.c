// Sentinel search in array 

#include<stdio.h>

void main(){
	int arr[100], val, i=0, n;

	printf("Enter size of array : ");
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("Enter %d element of array : ", i+1);
		scanf("%d",&arr[i]);
	}

	printf("Enter a value to search in array : ");
	scanf("%d", &val);
	
	arr[n] = val;
	i=0;
	while(arr[i]!=val){
		i++;
	} 

	if(i==n){
		printf("Data not found\n");
	}
	else{
		printf("Data found at %d position\n", i+1);
	}


}
