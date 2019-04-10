/*
 Pseudo code:
 https://www.hackerearth.com/fr/practice/algorithms/graphs/breadth-first-search/tutorial/

 BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE_QUEUE 100

struct Queue
{
    int arr[SIZE_QUEUE];
    int front;
    int rear;
};

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int nb_vertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int vertex)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->next = NULL;

    return node;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(*q));
    q->front = -1;
    q->rear = -1;
    return q;
}

struct Graph* createGraph(int nb_vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(*graph));
    graph->nb_vertices = nb_vertices;
    graph->adjLists = (struct Node**)malloc(sizeof(struct Node*)*nb_vertices);
    graph->visited = (int*)malloc(sizeof(int*)*nb_vertices);

    int i;
    for (i = 0; i < nb_vertices; i++)
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;


    return graph;
}

void addNode(struct Graph* graph, int src, int dest)
{
    // Create edge src->dest
    // Link it to the node src using the adjency list
    // Update the adjency list
    struct Node* node = createNode(dest);
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;
    // 0,1: adjLists[0] = node(1) and node(1)->next=NULL
    // 0,2: adjLists[0] = node(2) and node(2)->next=node(1)

    // Create edge dest->src
    node = createNode(src);
    node->next = graph->adjLists[dest];
    graph->adjLists[dest] = node;
}

void printGraph(struct Graph* graph)
{
    int i;
    for(i=0; i<graph->nb_vertices; i++){
        struct Node* tmp = graph->adjLists[i];
        printf("Adjacency list of vertex %d\n ", i);
        while (tmp)
        {
            printf("%d -> ", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
    }

}

void enqueue(struct Queue* queue, int vertex)
{
    if(queue->rear == SIZE_QUEUE - 1) return; // full

    // Just change the front to 0
    // Fill with the rear counter
    if(queue->front == -1){
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}

int dequeue(struct Queue* queue)
{
    int item;
    if(queue->rear == -1) return -1;

    // Dequeue with the front counter
    // Front counter was only switched to 0 in the enqueue
    item = queue->arr[queue->front];
    queue->front++;
    if(queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return item;
}

void printQueue(struct Queue* queue)
{
    int i;
    if(queue->rear == -1) printf("empty");

    for(i=queue->front; i<queue->rear+1; i++){
        printf("Queue: %d ", queue->arr[i]);
    }
    printf("\n");
}

void bfs(struct Graph* graph, int vertex)
{
    struct Queue* queue = createQueue();
    graph->visited[vertex] = 1;
    enqueue(queue, vertex);

    int i = 0;
    while(queue->rear != -1){
        printQueue(queue);
        int v = dequeue(queue);
        struct Node* neighboors = graph->adjLists[v];

        while(neighboors){
            if(!graph->visited[neighboors->vertex]){
                graph->visited[neighboors->vertex] = 1;
                enqueue(queue, neighboors->vertex);
            }
            neighboors = neighboors->next;
        }
    }
}

int main()
{
    int nb_vertex = 4;
    struct Graph* graph = createGraph(nb_vertex);

    addNode(graph, 0, 1);
    addNode(graph, 0, 2);
    addNode(graph, 1, 3);
    printGraph(graph);

    bfs(graph, 2);

    int i;
    for(i=0; i<graph->nb_vertices; i++){
        int item = graph->visited[i];
        printf("Visited %d %d \n", i, item );
    }

    return 0;
}
