#include<stdio.h>
#include<stdlib.h>

//Definition of AdjListNode structure
typedef struct AdjListNode {
    int vertex;                     //The vertex number
    struct AdjListNode* next;
} AdjListNode;


//Definition of Graph structure
typedef struct Graph {
    int numVertices;                //The number of vertices in the graph
    AdjListNode** adjLists;         //Array of adjacency lists
} Graph;

//Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (AdjListNode**)malloc(vertices * sizeof(AdjListNode*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

//Function to create a new adjacency list node
AdjListNode* createNode(int vertex) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    //Add edge from src to dest
    AdjListNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

//Recursive algorithm inside DFS
void dfs(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    AdjListNode* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfs(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

//DFS function with initialization
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    dfs(graph, startVertex, visited);
    free(visited);
}

void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        AdjListNode* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(queue);
}

int main() {
    int vertices = 10;
    Graph* graph = createGraph(vertices);

    // 20 directed edges for a 10-vertex graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 4, 5);
    addEdge(graph, 7, 2);
    addEdge(graph, 9, 0);
    addEdge(graph, 2, 4);
    addEdge(graph, 6, 1);

    printf("Depth First Search (starting from vertex 0):\n");
    DFS(graph, 0);
    printf("\n");

    printf("Breadth First Search (starting from vertex 0):\n");
    BFS(graph, 0);
    printf("\n");

    return 0;
}