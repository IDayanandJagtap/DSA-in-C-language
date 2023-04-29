
typedef struct que{
	int data;
	struct que * next ;
}que;


que *q1, * rear=NULL , * front =NULL;



int isEmpty(que *q){
	if(rear==NULL && front==NULL)
		return 1;
	else 
		return 0;
}


void enqueue(que *q, int data){
	que  *newNode, *temp;
	newNode = (struct que *)malloc(sizeof(struct que));
	newNode->data = data;
	newNode->next = NULL;
	
	if(front == NULL){
		front = newNode;
		rear=newNode;
		temp = newNode;	
	}
	else{
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
		
	}
}

int dequeue(que *q){
	que *temp;
	int val=-1;
	
	if(!isEmpty(q)){
		if(front == rear){
			temp = front;
			front=NULL;
			rear=NULL;
		}else{
			temp = front;
			rear->next = front->next;	
			front=front->next;
		}
		val = temp->data;
		free(temp);	
	}
	else{
		printf("Queue is empty!");
	}
	
	return val;
	
}


int peek(que *q){
	int data=-1;
	if(!isEmpty(q)){
		data = front->data;
		printf("Data at front is : %d\n",data);
	}
	else{
		printf("Queue is empty !\n");
	}
	return data;
}

// Complete
void display(que *q){
	que * temp = front;
	if(!isEmpty(q)){
	printf("\nData elements are : ");
	while(temp != rear){
		printf("\t%d", temp->data);
		temp = temp->next;
	}
	printf("\t%d\n",rear->data);
	}
	else
		printf("Queue is empty!\n");
	
}



