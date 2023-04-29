// Dynamic stack implementation with all basic functions 

#include<stdio.h>
#include<stdlib.h>
#include"dystack.h"


void main(){
	int ch,data; 
	
	while(1){
		printf("\nSelect an operation : \n\t1.Push \n\t2.Pop \n\t3.Peek \n\t4.isEmpty \n\t");
		scanf("%d", &ch);
	
		switch(ch){
			case 1:
				printf("Enter data to be inserted : ");
				scanf("%d", &data);
				top = push(top, data);
				printf("Current data at top : %d", top->data);
				break;
			case 2: 
				top = pop(top);
				printf("Current data at top : %d", top->data);
				break;
			case 3:
				if(peek(top) == -1)
					printf("Invalid list");
				else 
					printf("Data at top : %d", peek(top));
				break;
			case 4:
				if(isEmpty(top))
					printf("List is empty");
				else 
					printf("List is not empty");
				break;
			default:
				printf("Enter a valid choice !");
				break;
				
		}	
		
	}
	 
}
