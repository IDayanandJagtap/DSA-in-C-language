// linear queue static implementation 
#include<stdio.h>
#include"st_queue.h"
#include<stdlib.h>


void main(){
	que q1; 
	init_que(&q1);
	
	int ch,data;
	
	while(1){
		printf("Select an operation : \n\t1.Enqueue\n\t2.Dequeue\n\t3.Peek\n\t4.Display\n\t5.Exit\n\n\t");
		scanf("%d", &ch);
		switch(ch){
			case 1: 
				printf("Enter data : ");
				scanf("%d", &data);
				enqueue(&q1, data);
				display(q1);
				break;
			case 2: 
				data = dequeue(&q1);
				if(data!=-1){
					printf("Deleted data : %d\n", data);
					display(q1);
				}
				else
					printf("Queue is empty !");
				break;
			case 3: 
				peek(&q1);
				break;
			case 4:
				display(q1);
				break;
			case 5:
				exit(0);
			default : 
				printf("Enter valid option !");
		}
	
}
}
