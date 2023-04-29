#define MAX 50

typedef struct stack{
	int data[MAX];
	int top;
}stack;

// Initialize the stack
void init_stack(stack *s){
	s->top = -1;
}


// Check if the stack is empty
int isEmpty(stack *s){
	if(s->top == -1)
		return 1;
	return 0;
}

// Check if the stack is full
int isFull(stack *s){
	if(s->top == MAX-1)
		return 1;
	return 0;
}

// Push into stack 
int push(stack *s, int data){
	if(!isFull(s)){
		s->data[++s->top] = data;
		return 1;
	}
	else{
		printf("Stack is Full !\n");
		return 0;
	}
}

// Pop from stack
int pop(stack *s){
	if(!isEmpty(s)){
		return s->data[--s->top] ;
	}
	else{
		printf("Stack is Empty !\n");
		return -1;
	}
}

// Peek 
int peek(stack *s){
	if(!isEmpty(s)){
		return s->data[s->top];
	}
	else{
		printf("Stack is Empty !\n");
		return -1;
	}
}