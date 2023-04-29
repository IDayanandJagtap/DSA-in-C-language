typedef struct que { 
    NODE * node ; 
    struct que * next ;
}queue ;


queue * enqueue(queue * rear, NODE * node){
    queue *newNode ; 

    newNode = (queue* ) malloc (sizeof(queue));
    newNode->node = node; 
    newNode->next = NULL;

    if(rear == NULL){
        newNode->next = newNode;
        rear = newNode;
    }
    else{
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    return rear;

}


int isQueueEmpty(queue *rear){
    if(rear == NULL)
        return 1;
    else    
        return 0;
}

NODE  * dequeue(queue *rear){
    queue *temp ; 
    NODE *temp2 = NULL;
    if(!isQueueEmpty(rear)){
        if(rear->next == rear){
            temp = rear;
            rear == NULL ;
        }
        else{
            temp = rear->next;
            rear->next = temp->next;
        }
        // printf("Deleted data : %d\n", temp->data);
        temp2 = temp->node;
        free(temp);
        return temp2;

    }
}

int getSize (queue *rear){
    int size = 1;
    queue * temp = rear->next;
    while(temp != rear){
        size++;
        temp = temp->next;
    }

    return size;
}