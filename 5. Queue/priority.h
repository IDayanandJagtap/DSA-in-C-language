#define MAX 100
typedef struct queue{
	int data[MAX];
	int rear, front;
}que;

void init_que(que *q1){
	q->front = q->rear = -1;
}


int isFull(que *q1){
	if(q1->rear == MAX-1)
		return 1;
	else 
		return 0;
}

int isEmpty(que *q1){
	if(q1->rear == -1)
		return 1;
	else 
		return 0;
}

// Find the position of the element to be inserted (ascending order according to this function) ie. lowest -> highest priority
int pos(que *q1, int d){
	int i=0;
	if(!isEmpty(q1)){
		if(q1->rear == 0){
			if(d<=q1->data[0])
				i= 0;
			else 
				i = 1;
		}
		else{
			while(i<=(q1->rear+1) && d>=q1->data[i])
				++i;
		
		}
		return i;
	}
	return -1;
}

// Once the appropriate position of an element is found shift the array and empty that position.
void move(que *q, int pos){
	int i=q->rear;
	if(pos == 0 && q->rear<=1){
		q->data[i+1] = q->data[i];
	}
	else{
		for(i=q->rear; i>=pos; i--){
			q->data[i+1] = q->data[i];
		}
	}
}

// Insert the element at its appropriate location(position)
void enqueue(que *q1, int d){
	int p;
	if(!isFull(q1)){
		if(q1->rear == -1){
			q1->rear++; q1->front++;
			q1->data[q1->rear] = d;
		}
		else{
			p = pos(q1,d);
			move(q1,p);
			q1->data[p] = d;
			q1->rear++;
		}
	}
	else 
		printf("Queue is Full !\n");
	
}

// Delete an element from queue
int dequeue(que *q1){
	int temp=-1;
	if(!isEmpty(q1)){
		if(q1->front == MAX-1){
			temp = q1->data[q1->front];
			q1->front = -1;
			q1->rear = -1; 
		}
		else if(q1->front==q1->rear){
			temp = q1->data[q1->front];
			q1->front=-1;
			q1->rear=-1;
		}
		else{
			temp = q1->data[q1->front];
			q1->front++;
		
		}
	}
	else 
		printf("Queue is empty!\n");
	
	return temp;
}


// Display queue
void display(que *q){
	int i;
	if(!isEmpty(q)){
		printf("Data elements : ");
		if(q->front == q->rear)
			printf("\t%d", q->data[q->rear]);
			
		else{
			for(i=q->front; i<=q->rear; i++)
				printf("\t%d", q->data[i]);
		}
		printf("\n");
	}
	else 
		printf("Queue is empty !\n");
	
}
