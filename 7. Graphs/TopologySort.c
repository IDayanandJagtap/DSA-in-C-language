#include<stdio.h>
#define MAXSIZE 50
typedef struct node {
    int data[MAXSIZE];
    int top;
}stack;

void init(stack * s){
    s->top = -1;
}
int isEmpty(stack *s){
    return s->top==-1 ? 1 : 0;
}
int isFull(stack *s){
    return s->top==(MAXSIZE-1) ? 1 : 0;
}
int push(stack *s, int data){
    if(!isFull(s)){
        s->data[++s->top] = data;
    }
    return s->top;
}
int pop(stack *s){
    if(!isEmpty(s)){
        return s->data[s->top--];
    }
}

void tsort(int A[10][10], int n){
    int vis[10] = {0}, inDeg[10] = {0};
    int i,j,data;

    stack s;
    init(&s);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            inDeg[i] += A[j][i];
        }
    }

    while(1){
        for(i=0; i<n; i++){
            if(inDeg[i]==0 && vis[i]==0){
                printf("%d\t", i+1);
                vis[i] = 1;
                push(&s, i);
            }
        }
            if(isEmpty(&s))
                break;

            data = pop(&s);

            for(j=0; j<n; j++){
                if(A[data][j]==1)
                    inDeg[j] -= 1;
            }
    }
    
}


/*void tsort(int A[10][10], int n){
    int vis[10] = {0}, inDeg[10] = {0};
    int i,j,data;

    stack s;
    init(&s);

    for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            inDeg[j] += A[i][j];
        }
    }

    while(1){
        int zeroIndegree = 0;
        for(i=0; i<n; i++){
            if(inDeg[i]==0 && vis[i]==0){
                printf("%d\t", i+1);
                vis[i] = 1;
                push(&s, i);
                zeroIndegree = 1;
            }
        }

        if(!zeroIndegree)
            break;

        data = pop(&s);

        for(j=0; j<n; j++){
            if(A[data][j]==1){
                inDeg[j] -= 1;
            }
        }
    }
}
*/


void main() { 
    // int A[10][10] = {{0, 1, 1, 0, 0},
    //                  {0, 0, 1, 1, 0},
    //                  {0, 0, 0, 1, 1},
    //                  {0, 0, 0, 0, 1},
    //                  {0, 0, 0, 0, 0}};
    int A[10][10] = {0};
    int i,j,n=5;

    printf("Enter no of vertices : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Is there an edge between V%d and V%d : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    tsort(A, n);

}