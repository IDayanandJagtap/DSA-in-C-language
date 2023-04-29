// Static Queue :
#define MAXSIZE 50

typedef struct queue{
    int data[MAXSIZE];
    int front, rear;
}que;


void init(que * q){
    q->front = q->rear = -1;
}

int isEmpty(que *q){
    if(q->rear == q->front)
        return 1;
    return 0;
}

int isFull(que *q){
    if(q->rear == MAXSIZE-1)
        return 1;
    return 0;
}


int enqueue (que *q, int data){
    if(!isFull(q)){
        q->data[++q->rear] = data;
        return q->rear;
    }
    return -1;
}

int dequeue (que *q){
    if(!isEmpty(q)){
        return q->data[++q->front];
    }
    return -1;
}

