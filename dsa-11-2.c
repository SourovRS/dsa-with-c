#include<stdio.h>
#include<stdlib.h>
    int A [5][5] = {
        {0,1,0,0,1},
        {1,0,1,0,0},
        {0,1,0,0,0},
        {0,0,0,0,1},
        {1,0,0,1,0}
    };

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}
int visited[5] = {0,0,0,0,0};
void DFS(int i){
    printf("%d ", i+1);
    visited[i] = 1;
    for (int j = 0; j < 5; j++)
    {
        if(A[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 

int main(){
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    printf("Root Node is:- 2\n");
    printf("BFS Implementation \n");
    // BFS Implementation 
    int node;
    int visited[5] = {0,0,0,0,0};
    int i = 1;
    printf("%d ", i+1);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 5; j++)
        {
            if(A[node][j] ==1 && visited[j] == 0){
                printf("%d ", j+1);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    printf("\n");
    printf("DFS Implementation \n");
    //DFS Implementation
    DFS(1);
    return 0;
}