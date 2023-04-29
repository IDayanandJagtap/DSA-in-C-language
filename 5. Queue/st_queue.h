#define MAX 10

typedef struct queue{
	int data[MAX];
	int front, rear;
}que;


void init_que(que *q){
	q->front = q->rear = -1;
}

int isEmpty(que *q){
	if(q->front == q->rear)
		return 1;
	else 
		return 0;
}

int isFull(que *q){
	if(q->rear == MAX -1)
		return 1;
	else 
		return 0;
}


int enqueue(que *q, int data){
	
	if(!isFull(q)){
		if(q->rear == -1){
			q->front++;
			q->rear++;
			q->data[q->rear] = data;
		}
		else{
			q->data[++q->rear] =data;
		}
		return 1;
	}
	else{ 
		printf("Queue overflow!\n");
		return 0;
	}
}

int dequeue(que *q){
	int temp = -1;
	if(!isEmpty(q)){
		if(q->front==MAX-1){
			q->front = -1;
		}
		else if(q->front == q->rear){
			temp = q->data[q->front];
			q->front = q->rear = -1;
		}
		else{
			temp = q->data[q->front];
			q->front++;
		}
	}	
	else
		printf("Queue is empty !\n");
		
	return temp;
}

int peek(que *q){
	int temp;
	if(!isEmpty(q)){
		temp = q->data[q->front];
		printf("Value at front is : %d\n", temp);
		return temp;
	}
	else{
		printf("Queue is empty!\n");
		return -1;
	}
}

void display(que q){
	int i;
	printf("Data elements in queue : ");
	for(i=q.front ; i<=q.rear; i++){
		printf("\t%d", q.data[i]);
	}
	printf("\n");
}


