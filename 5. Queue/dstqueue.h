typedef struct queue{
	int data;
	struct queue *next;
}que;

que *q, *front=NULL,*rear=NULL;


int isEmpty(){
	if(rear == NULL)
		return 1;
	else 
		return 0;
}
void display(que *q){
	if(!isEmpty()){
		que *temp = front;
		printf("Data elements are : ");
		while(temp->next != front){
			printf("\t%d",temp->data);
			temp = temp->next;
		}
		printf("\t%d",rear->data);
		printf("\n");
	}
}
void enqueue(que *q, int side , int data){
	que * temp , *newNode;
	newNode = (struct queue *)malloc(sizeof(struct queue));
	newNode->data = data;
	newNode->next = NULL;
	
	if(side == 1){
		if(front == NULL){
			front = rear = newNode;
			rear->next = front;
		}
		else{
			rear->next = newNode;
			newNode->next = front;
			front = newNode;
		}
		
	
	}
	else if(side == 2){
		if(rear != NULL){	
			newNode->next = rear->next;
			rear->next = newNode;
			rear = newNode;
		}
		else{
			front = rear=newNode;
			rear->next = front;
		}
	}
	display(q);
		
}

int getData(que *q, int side){
	int data = -1;
	if(!isEmpty()){
		if(side == 1)
			data = front->data;
		else if(side == 2)
			data = rear->data;
		
	}
	
	return data;
}

int dequeue(que *q, int side){
	int del = -1;
	que *temp, *prev;
	if(!isEmpty()){
		temp = front;
		if(rear->next == rear){
			temp = rear;
			rear = NULL;front=NULL;
		}
		else{
			if(side == 1){
				rear->next = front->next;
				front = front->next;
			}
			else if(side == 2){
				while(temp->next != front){
					prev = temp;
					temp = temp->next;
				}
				prev->next = front;
				rear = prev;
			}
			del = temp->data;
		}
		free(temp);
		
	}
	return del;
}



