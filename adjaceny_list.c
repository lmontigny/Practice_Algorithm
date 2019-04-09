#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int nb_vertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->next = NULL;

    return node;
}

struct Graph* createGraph(int nb_vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->nb_vertices = nb_vertices;
    graph->adjLists = (struct Node**)malloc(sizeof(struct Node*)*nb_vertices);

    int i;
    for (i = 0; i < nb_vertices; i++)
        graph->adjLists[i] = NULL;


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

int main()
{

    struct Graph* graph = createGraph(2);
    addNode(graph, 0, 1);
    addNode(graph, 0, 2);
    printGraph(graph);

    return 0;
}
