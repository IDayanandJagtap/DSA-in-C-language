struct stack{
	int data;
	struct stack *prev;
};

struct stack *top=NULL;


// FUNCTION TO CHECK IF LIST IS EMPTY

int isEmpty(struct stack *top){
	if(top == NULL)
		return 1;
	else
		return 0; 
}


// FUNCTION PEEK
int peek(struct stack *top){
	if(!isEmpty(top))
		return (top->data);
	else 
		return -1;
}


// FUNCTION PUSH
struct stack * push(struct stack * topPtr, int data){
		struct stack * newNode ;
		
		newNode = (struct stack *)malloc(sizeof(struct stack));
		newNode->data = data;
		
		if(topPtr == NULL){
			newNode->prev =NULL;
			topPtr = newNode;
		}
		else{
			newNode->prev = topPtr; 
			topPtr = newNode; 
		
		}
		return topPtr;

}


// FUNCTI0N POP
struct stack *pop(struct stack * top){
	
	if(!isEmpty(top)){
		struct stack *temp; 
		temp = top ; 
		
		top = top->prev;
		printf("\nDeleted value : %d\n", temp->data);
		free(temp);	
	}
	else{
		printf("Empty list !");
	}
	
	return top;
}







