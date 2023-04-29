#include<stdio.h>
#include"st_queue.h"

// Display matrix: 
void displayAdjacencyMatrix(int A[10][10], int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

// Count in,out and total degree of each vertex
void countDegree(int A[10][10], int n){
    int i,j,inDeg,outDeg;
    for(i=0; i<n; i++){
        outDeg = inDeg = 0;
        for(j=0; j<n; j++){
            if(A[i][j] == 1)
                outDeg++;
            if(A[j][i] == 1)
                inDeg++;
        }
        printf("Indegree of vertex V%d is : %d\n", i+1, inDeg);
        printf("Outdegree of vertex V%d is : %d\n", i+1, outDeg);
        printf("Total degree of vertex V%d is : %d\n\n", i+1, outDeg + inDeg);
    }
}

// Traversal: 
// 1. BFS 
int visBfs[10] = {0};
void BFS(int A[10][10], int n, int start){
    que q;
    init(&q);
    int i;

    visBfs[start] = 1;
    printf("%d\t", start);
    enqueue(&q, start);

    while(!isEmpty(&q)){
        start = dequeue(&q);
                printf("%d\t", start);

        for(i=0; i<n; i++){
            if(A[start][i] == 1 && visBfs[i] == 0){
                visBfs[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

// 2. DFS
int visDfs[10] = {0} ;    // Change the size according to the no of vertices 
void DFS(int A[10][10], int n, int ver){
    int i;
    visDfs[ver] = 1;
    printf("V%d\t", ver+1);

    for(i=0;i<n; i++){
        if(A[ver][i] == 1 && visDfs[i] == 0){
            DFS(A,n,i);
        }
    }
}

void main(){
    int A[10][10], i,j,n;
    printf("Enter no of vertices : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Is there any edge between V%d and V%d (1/0) : ", i+1,j+1);
            scanf("%d", &A[i][j]);
        }
    }

    displayAdjacencyMatrix(A,n);
    printf("\n");
    // countDegree(A,n);
    printf("\n");
    // DFS(A,n,0);
    printf("\nBFS\n");
    BFS(A,n,0);
}