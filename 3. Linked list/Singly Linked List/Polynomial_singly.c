// Creating a LL and store polynomial in it.
// Display it 
// Another ll to store addition of poly 


#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	int expo;
	int coe;
	struct NODE * next ; 
}NODE;


// VARS 
NODE * head1, *head2, *head3;


// Create poly
struct NODE * create(int n){
	NODE * temp, *newNode, *head;
	int i = 1, c, e; 
	
	for(i=1; i<=n; i++){
		newNode = (struct NODE * )malloc(sizeof(struct NODE));
		printf("Enter coefficient and expo of %d term resp : ", i);
		scanf("%d%d", &c, &e);
		newNode->coe = c;
		newNode->expo = e;
		newNode->next = NULL;
		
		if(head == NULL){
			head = temp = newNode;
		}
		else{
			temp->next = newNode;
			temp = newNode;
		}
		
	} 
	
	return head;

}

// Function to display poly 
void display(struct NODE * head){
	NODE * temp; 
	temp = head; 
	
	while(temp){
		if(temp->expo != 0)
			printf("%dX^%d",temp->coe, temp->expo);
		else 
			printf("%d", temp->coe);
			
		if(temp->next != NULL){
			if(temp->coe >= 0)
				printf("+");
			else
				printf("-");
		}			
		
		temp = temp->next;
	}
	
	printf("\n");
}

// FUNCTION TO ADD POLY 
struct NODE * addPoly(struct NODE *head1, struct NODE * head2){
	NODE * temp1, *temp2, *temp3, *newNode, *head = NULL;
	int c, e;
	
	temp1= head1;
	temp2= head2;
	
	while(temp1 && temp2){
		if(temp1->expo == temp2->expo){
			e = temp1->expo;
			c = temp1->coe + temp2->coe;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->expo < temp2->expo){
			e = temp2->expo;
			c = temp2->coe;
			temp2 = temp2->next;
		}
		else {
			e = temp1->expo;
			c = temp1->coe;
			temp1 = temp1->next;
		}
		
		newNode = (struct NODE * )malloc (sizeof(struct NODE));
		newNode->coe = c;
		newNode->expo = e;
		newNode->next = NULL;
		
		if(head==NULL){
			head = temp3 = newNode;
		}
		else{
			temp3->next = newNode; 
			temp3 = newNode;
		}
	}
	
	while(temp1){
		newNode = (struct NODE * )malloc (sizeof(struct NODE));
		newNode = temp1;
		newNode->next = NULL;
		
		temp3->next = newNode;
		temp3 = newNode;
		temp1 = temp1->next;
	}
	while(temp2){
		newNode = (struct NODE * )malloc (sizeof(struct NODE));
		newNode = temp2;
		newNode->next = NULL;
		
		temp3->next = newNode;
		temp3 = newNode;
		temp2 = temp2->next;
	}
	
	return head;

}




void main(){
	int n ; 
	printf("Enter no of terms in polynomial : ");
	scanf("%d", &n);
	printf("Enter polynomial in order\n");
	head1 = create(n);
	display(head1);
	
	printf("Enter no of terms in another polynomial : ");
	scanf("%d", &n);
	printf("Enter polynomial in order\n");
	head2 = create(n);
	display(head2);
	
	// CALL ADD
	head3 = addPoly(head1, head2);
	printf("Addition of both polynomials : ");
	display(head3);
}

