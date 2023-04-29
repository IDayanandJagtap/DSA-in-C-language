
#include<stdio.h>
#include<stdlib.h>
#include"doublylist.h"

void main(){
	int op, data, pos, n ; 
	
	printf("Enter no of Nodes in list : ");
	scanf("%d", &n);
	head = createLL(n); 
	display(head);
	
	while(1){
	printf("Select an operation : \n \t1.Append \n\t2.Insert\n\t3.Search \n\t4.Delete by element \n\t5.Delete by position \n\t6.Display \n\t 7.Reverse\n\t8.Exit\n\n\t");
	scanf("%d", &op);
	
	
	
	
	switch(op){
		case 1: 
			printf("Enter the element to append to list : ");
			scanf("%d", &data);
			append(head, data);
			display(head);
			break;
		case 2: 
			printf("Enter the data to be inserted and position resp : ");
			scanf("%d%d", &data , &pos);
			insert(head,pos,data);
			display(head);
			break;
		case 3: 
			printf("Enter the data to be searched : ");
			scanf("%d", &data);
			pos = search(head,data);
			if(pos==-1)
				printf("Data not found !\n");
			else
				printf("Data found at pos : %d\n", pos);
			break;
		case 4: 
			printf("Enter the data to be deleted : ");
			scanf("%d", &data);
			printf("Data deleted : %d\n", deleteByData(head,data));
			display(head);
			break;
			
		case 5: 
			printf("Enter the position to be deleted : ");
			scanf("%d", &pos);
			printf("Data deleted : %d\n", deleteByPos(head,pos));
			display(head);
			break;
		case 6: 
			display(head);
			break;
		case 7 :
			reverse(head);
			
			break;
		case 8:
			exit(0);
		default:
			printf("Select valid option !");
			break;
	}
	}
}
