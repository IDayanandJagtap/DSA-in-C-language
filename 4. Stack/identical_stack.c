// check whether the contents of two stacks are identical.
// Neither stack should be changed

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct stack{
	int data[MAX];
	int top;
}stack;


int isFull(stack * s){
	if(s->top == MAX-1)
		return 1;
	else 
		return 0;
} 


int isEmpty(stack s){
	if(s.top == -1)
		return 1;
	else
		return 0;
}


int push(stack *s , int n){
	int i,d;
	
	if(isFull(s)){
		printf("\nStack is full !");
		return -1;
	}
	else{
		for(i=0; i<n; i++){
			printf("Enter value : ");
			scanf("%d", &d);
			s->top++;
			s->data[s->top] = d;
		}
		return 1;	
	}


}


void display(stack s){
	int i;
	if(isEmpty(s)){
		printf("\nStack is empty !");
	}
	else{
		printf("\nContents of stack are : "); 
		for(i=s.top ; i>=0; i--){
			printf("\t%d", s.data[i]);
		}
		printf("\n");
	}
} 


int isIdentical(stack s1, stack s2){
	int i, flag = 0; 
	if(!isEmpty(s1) && !isEmpty(s2)){
		if(s1.top == s2.top){
			for(i=s1.top; i>=0; i--){
				if(s1.data[i] == s2.data[i])
					flag = 1;
				else{
					flag=0;
					break;
				}
			}
		}
		else
			flag = 0;
	}
	else{
		flag = 0;
	}
	
	if(flag)
		printf("\nStacks are identical !\n");
	else 
		printf("\nStacks are not identical !\n");
	return flag;
}




void main(){
	int ch,data, n; 
	stack s1,s2;
	s1.top=s2.top = -1;
	
	
	printf("Enter number of data elements in 1st stack : ");
	scanf("%d", &n);
	push(&s1,n);
	
	printf("Enter number of data elements in 2st stack : ");
	scanf("%d", &n);
	push(&s2,n);
	
	display(s1);
	display(s2);
	
	isIdentical(s1,s2);
	
	
	

}
