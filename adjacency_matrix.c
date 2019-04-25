#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 4

// Directed graph
// Undirected graph A[i][j] = A[j][i]
void addNode(int** adjMatrix, int src, int dest){
    adjMatrix[src][dest] = 1;
}

void printMatrix(int** adjMatrix){
    int i, j;
    for(i = 0; i<M; i++){
        for(j = 0; j<N; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void initMatrix(int** adjMatrix){
    int i, j;
    for(i = 0; i<M; i++){
        for(j = 0; j<N; j++){
            adjMatrix[i][j] = 0;
        }
    }
}

int main(){
    int **adjMatrix = (int**)malloc(sizeof(int**)*M);
    int i;
    for(i = 0; i<M; i++){
        adjMatrix[i] = (int*)malloc(sizeof(int*)*N);
    }

    initMatrix(adjMatrix);
    addNode(adjMatrix, 0,1);
    printMatrix(adjMatrix);

    return 0;
}
