#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int priority;
    int data;
    struct node* next;
} Node;

Node* createNode(int priority, int data){
    Node* pq = (Node*)malloc(sizeof(Node));
    pq->priority = priority;
    pq->data = data;
    pq->next = NULL;

    return pq;
}

void push(Node** pq_head, int priority, int data){
    Node* tmp = createNode(priority, data);
    Node* head = (*pq_head);

    // New node has higher priority, pq is now the head
    // priority = 0, most important
    if((*pq_head)->priority > priority){
        tmp->next = *pq_head;
        (*pq_head) = tmp;
    }
    else{
        // Traverse the list to find a position
        // ex: priority=2, head->next->priority=3, stop here
        // ex: priority=5, head->next->priority=3, inside while
        while((*pq_head)->next != NULL
                && priority > (*pq_head)->next->priority){
                (*pq_head) = (*pq_head)->next;
        }

        // Insert new node
        // Example:
        // 0: head
        // 12: tmp
        // 19: head->next
        tmp->next = (*pq_head)->next;
        (*pq_head)->next = tmp;
    }
}

void printQueue(Node* pq){
    if(!pq) return;
    while(pq){
        printf("Node priority %u, data %u \n", pq->priority, pq->data);
        pq = pq->next;
    }
}

int main()
{
    Node* priority_queue = createNode(8,12);

    push(&priority_queue, 19, 3);
    push(&priority_queue, 9, 2);
    push(&priority_queue, 1, 2);
    push(&priority_queue, 0, 77);

    printQueue(priority_queue);

    return 0;
}
