#include<stdio.h>
#include<stdlib.h>
#include"dstqueue.h"




void main(){
	int ch, data,x;
	
	while(1){
		printf("Select an operation: \n\t1.Get front\n\t2.Get rear\n\t3.Add front\n\t4.Delete Front\n\t5.Add rear\n\t6.Delete Rear\n\t7.Exit\n\n\t");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: 
				x= getData(q,1);
				if(x == -1)
					printf("Queue is empty !\n");
				else 
					printf("Data at front : %d\n", x);
				break;
			case 2:
				x = getData(q,2);
				if(x == -1)
					printf("Queue is empty !\n");
				else 
					printf("Data at rear : %d\n", x);
				break;
			case 3:
				printf("Enter data : ");
				scanf("%d", &data);
				enqueue(q,1,data);
				break;
			case 4:
				x = dequeue(q,1);
				if(x == -1)
					printf("Queue is empty!\n");
				else 
					printf("Deleted data : %d\n",x);
				display(q);
				break;
			case 5:
				printf("Enter data : ");
				scanf("%d", &data);
				enqueue(q,2,data);
				break;
			case 6:
				x = dequeue(q,2);
				if(x == -1)
					printf("Queue is empty!\n");
				else 
					printf("Deleted data : %d\n",x);
				display(q);
				break;
			case 7:
				exit(0);
			default:
				printf("Please select a valid option!\n");
				
				
		}
	
	}
}
