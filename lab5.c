/* Name - Amey Shinde
   Student ID - 1001844387
   Command for Compilation - "gcc lab5.c"
   Command for output using the file given by Proffessor - "a.out lab5.a.dat"
   I was able to create graph, add edges , assign direction but had trouble with rigidity.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int);

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph
{
    int numVertices;
    struct node **Lists;
    int *visited;
};

struct Graph *createGraph(int vertices) //creates the graph
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->Lists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->Lists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int npebbles[]) //creates and adds the edges.
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->Lists[src];
    graph->Lists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->Lists[dest];
    graph->Lists[dest] = newNode;
}

int createEdge(int nVertices, int nEdges, int edgeFrom[], int edgeTo[], int npebbles[]) //edges initialisation
{
    struct Graph *graph = createGraph(nVertices);
    int i;
    for (i = 0; i < nVertices; i++)
    {
        addEdge(graph, edgeFrom[i], edgeTo[i], npebbles);
    }

    for (i = 0; i < nEdges; i++)
    {
        printf("%d ", edgeFrom[i]);
        printf("%d\n", edgeTo[i]);
    }

    return 0;
}

int takeInput(FILE *fp)
{
    int nVertices;
    int i, j;
    fscanf(fp, "%d", &nVertices);
    int nEdges = (2 * nVertices - 3);
    int edgeFrom[nEdges]; // This does not represent direction
    int edgeTo[nEdges];   // This does not represent direction
    int npebbles[nVertices];
    for (i = 0; i < nVertices; i++)
    {
        npebbles[i] = 2; // assign two pebbles to each vertice.
    }

    for (i = 0; i < nEdges; i++, j++)
    {
        fscanf(fp, "%d", &edgeFrom[i]);
        fscanf(fp, "%d", &edgeTo[i]);
    }

    createEdge(nVertices, nEdges, edgeFrom, edgeTo, npebbles);

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    takeInput(fp);

    return 0;
}
