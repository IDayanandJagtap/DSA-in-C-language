// Binary search 

#include<stdio.h>

void main(){
	int arr[100], lb=0, ub, middle, val, flag=0,n, i;

	printf("Enter size of array : ");
	scanf("%d", &n);

	ub = n-1;

	for(i=0; i<n; i++){
		printf("Enter %d element of array : ", i+1);
		scanf("%d",&arr[i]);
	}

	printf("Enter a value to find in array : ");
	scanf("%d", &val);
	

	while(lb != ub){
		middle = (lb+ub)/2;

		if(arr[middle] == val){
			flag=1;
			break;
		}
		else if(val < arr[middle]){
			ub = middle-1;
		}
		else if(val > arr[middle]){
			lb = middle+1;
		}
	}

	if(flag==1){
		printf("Data found at %d position.\n",middle+1);
	}
	else{
		printf("Data not found.\n");
	}
}
