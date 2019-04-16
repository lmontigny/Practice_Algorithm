#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct Stack
{
    int item[SIZE];
    int front;
};

void push(struct Stack* stack, int val){
    if(stack->front == SIZE-1) // check if full
        return;

    stack->front++;
    stack->item[stack->front] = val;
}

void pop(struct Stack* stack){
    if(stack->front == -1) // check if empty
        return;

    /* stack->item[stack->front] = 0; */
    stack->front--;
}

void initStack(struct Stack* stack){
    stack->front = -1;
}

void printStack(struct Stack* stack){
    if(stack->front == -1)
        return;

    int i;
    for(i=stack->front;i>=0; i--){
        printf("%d ", stack->item[i]);
    }
    printf("\n ");
}

int main()
{
    struct Stack* stack = malloc(sizeof(*stack));
    initStack(stack);

    push(stack, 2);
    push(stack, 11);
    push(stack, 9);
    push(stack, 13);
    pop(stack);
    printStack(stack);

    return 0;
}
