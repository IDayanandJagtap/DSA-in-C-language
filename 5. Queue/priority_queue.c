#include<stdio.h>
#include"priority.h"

void main(){
	que q;
	init_que(&q);
	//printf("Value of front is : %d %d ", q.front, q.rear);
	int ch,data; 
	
	while(1){
	printf("Select an operation : \n\t1.Add an element\n\t2.Delete an element\n\t3.Exit\n\n\t");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			printf("Enter the data : ");
			scanf("%d", &data);
			enqueue(&q, data);
			display(&q);
			break;
		case 2: 
			dequeue(&q);
			display(&q);
			break;
			
	
		case 3:
			exit(0);
		default: 
			printf("Print select a valid option !");
			
	}
	
	}

}
