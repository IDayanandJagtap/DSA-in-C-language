// CONVERT TO POSTFIX
#include<stdio.h>


typedef struct stack {
	char data[50];
	int top;
}stack;

stack *s1;


int isFull(struct stack *s){
	if(s->top == 49)
		return 1;
	else 
		return 0;
	
}
int isEmpty(struct stack *s){
	if(s->top == -1)
		return 1;
	else 
		return 0;
}


void push(struct stack *s, char data){
	if(!isFull(s)){
		s->top++;
		s->data[s->top] = data;
	}
	else 
		printf("Stack is Full !");
}

char pop(struct stack *s){
	char temp;
	if(!isEmpty(s)){
		temp = s->data[s->top];
		s->top--;
	}
	else
		temp = '\0';
		
	return temp;
}

int priority(char c){
	if(c=='+'|| c=='-')
		return 1;
	else if(c=='*'||c=='/'||c=='%')
		return 2;
	return 0;
}


void postfix(char *ptr ){
	stack s1;
	s1.top = -1;
	char res[50], c;
	int j=0;
	
	while(*ptr != '\0'){
		if(isalnum(*ptr))
			res[j++] = *ptr;
		else if( *ptr == '(')
			push(&s1, *ptr);
		else if(*ptr == ')'){
			while((c=pop(&s1)) != '(')
				res[j++] = c;
		}
		else {
			if(priority(s1.data[s1.top]) >= priority(*ptr))
				res[j++] = pop(&s1);
			push(&s1,*ptr);
		}
		ptr++;
	}	
	
	while(!isEmpty(&s1))
		res[j++] = pop(&s1);
		
	res[j] = '\0';
	
	printf("Postfix notation : %s\n", res);
	
}


void main(){
	char str[50];
	char *ptr = str;
	
	printf("Enter an expression : ");
	scanf("%s", str);
	
	//printf("String is : %s", str);
	
	postfix(ptr);
	
}


