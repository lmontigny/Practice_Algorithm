#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

struct Queue
{
    int item[QUEUE_SIZE];
    int front;
    int rear;
};

bool isFull(struct Queue *q)
{
    return ((q->front == q->rear+1) || (q->front == 0 && q->rear == QUEUE_SIZE-1));
}

bool isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

void enqueue(struct Queue* q, int val)
{
    if(isFull(q)){
        printf("Queue full \n");
        return;
    }
    else{
        // circular queue: only if front -1 put 0
        // otherwise dont touch it, let front where it is
        if(q->front == -1) {
            q->front = 0;
        }

        q->rear = (q->rear + 1)%QUEUE_SIZE;
        q->item[q->rear] = val;
    }
}

int dequeue(struct Queue* q)
{
    int val;
    if(isEmpty(q)){
        printf("Queue empty \n");
        return -1;
    }
    else{
        val = q->item[q->front];

        // front reached the last element at rear
        // can be [...rear...front...] in a circular queue
        // just front == rear, no more element in the queue
        if(q->front == q->rear){
            q->front = q->rear = -1;
        }
        // loop over the circular queue
        else{
            q->front = (q->front + 1)%QUEUE_SIZE;
        }
    }

    return val;
}

void printQueue(struct Queue* q)
{
    if(isEmpty(q)){
        printf("Queue empty \n");
        return;
    }
    /* else{ */
    /*     int i; */
    /*     for(i=q->front; i != q->rear; i=(i+1)%QUEUE_SIZE){ */
    /*     /1* for(i=0; i<QUEUE_SIZE; i++){ *1/ */
    /*         printf("%d %d \n", q->item[i], i); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    int i;
    printf("\n");
    if (q->front > q->rear)
    {
        for (i = q->front; i < QUEUE_SIZE; i++)
        {
            printf("%d ", q->item[i]);
        }
        for (i = 0; i <= q->rear; i++)
            printf("%d ", q->item[i]);
    }
    // Normal (non circular) printf
    else
    {
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->item[i]);
    }
}

int main()
{
    struct Queue* q = malloc(sizeof(*q));
    q->front = -1;
    q->rear = -1;

    enqueue(q, 4);
    enqueue(q, 9);
    enqueue(q, 12);
    enqueue(q, 2);
    enqueue(q, 8);

    printQueue(q);

    enqueue(q, 111);

    int v;
    v = dequeue(q);
    v = dequeue(q);

    printQueue(q);

    enqueue(q, 111);

    printQueue(q);
    /* printf("%d \n", v); */

    return 0;
}
