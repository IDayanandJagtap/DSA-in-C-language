// Write program to sort ll
// Concept of bubble sort is used here.

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	int data; 
	struct NODE* next;
}NODE;

NODE *head;

struct NODE * createLL(int n){
	NODE * newNode , *head, *temp;
	head = NULL;
	int i,d;
	
	for(i=0; i<n; i++){
		newNode = (struct NODE *)malloc (sizeof(struct NODE));
		printf("Enter the %d data element : ", i+1);
		scanf("%d", &d);
		newNode->data= d;
		newNode->next = NULL;
		
		if(head == NULL){
			head = newNode;
			temp = newNode ;
		}
		else{
			temp->next = newNode;
			temp = newNode;
		}	
	}
	
	  
	return head;
}

void display(struct NODE * headptr){
	NODE *temp ; 
	temp = headptr ; 
	
	printf("Data elements : ");
	while(temp!=NULL){
	
		printf("\t%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
}

void sort(struct NODE *headptr){
	NODE *ptr1, *ptr2;
	int temp;
	ptr1 = headptr;
	while( ptr1->next != NULL){
		ptr2 = ptr1->next;
		
		while(ptr2!= NULL){
			if(ptr1->data > ptr2->data){
				temp = ptr1->data;
				ptr1->data= ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	
}

void main(){
	int n ; 
	printf("Enter no of nodes in list : ");
	scanf("%d", &n);
	head = createLL(n);
	display(head);
	sort(head);
	display(head);
}
