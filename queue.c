#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10

struct Queue
{
    int item[QUEUE_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* q, int val)
{
    if(q->rear == QUEUE_SIZE-1)
        exit(0); // queue full
    else{
        if(q->front == -1)
            q->front = 0;

        q->rear++;
        q->item[q->rear] = val;
    }
}

int dequeue(struct Queue* q)
{
    int val;
    if(q->front == -1)
        return -1; // queue empty
    else{
        val = q->item[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
        return val;
    }
    return -1;
}

void printQueue(struct Queue* q)
{
    int i;
    for(i=q->front; i<q->rear+1; i++){
        printf("val %d \n", q->item[i]);
    }
}

int main()
{
    // Init queue
    struct Queue* q = malloc(sizeof(*q));
    q->front = -1;
    q->rear = -1;

    enqueue(q, 4);
    enqueue(q, 9);
    enqueue(q, 12);
    printQueue(q);

    int v = dequeue(q);
    v = dequeue(q);
    printf("dequeue val %d \n", v);

    return 0;
}
