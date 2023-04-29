#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}NODE;


void displayAdjacencyList(NODE *vertices[10], int n){
    int i;
    NODE * temp;

    for(i=0; i<n; i++){
        temp = vertices[i];
        printf("%d = ", i+1);
        while(temp){
            printf("%d --> ", temp->data);
            temp =temp->next;
        }
        printf(" NULL \n");
    }
}



void main(){
    int i,j,n, isEdge=0;
    NODE *last=NULL, *newNode, *vertices[10];
    printf("Enter the no of vertices : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Is there an edge bet V%d and V%d : ", i+1, j+1);
            scanf("%d", &isEdge);

            if(isEdge){
                newNode = (NODE *) malloc(sizeof(NODE));
                newNode->data = j+1;
                newNode->next = NULL;
                if(last == NULL)
                    vertices[i] = last = newNode;
                else{
                    last->next = newNode;
                    last = newNode;
                }
            }

        }
    }
    displayAdjacencyList(vertices, n);
}