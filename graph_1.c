// BFS traversal of graph .

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_vert 50

typedef struct node
{
    int v; // indicates maximum vertices;
    bool adj[max_vert][max_vert];

} graph;

graph *create_graph(int nodes)
{
    graph *g;
    g = (graph *)malloc(sizeof(graph));
    g->v = nodes;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void add_edge(graph *g, int u, int v)
{
    g->adj[u][v] = true;
    g->adj[v][u] = true; // this makes the graph to be undirected.
}

void bfs(graph *g, int s)
{
    // creating a visited array to mark the visited vertices in the graph.
    int visited[max_vert], i;
    for (i = 0; i < max_vert; i++)
    {
        visited[i] = false;
    }
    // creating a queue for bfs traversal.
    int queue[max_vert];
    // enqueing the start vertices.
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    // creating a loop for bfs traversal of remaining nodes.
    while (front != rear)
    {
        // dequeing the value.
        int val = queue[front++];
        printf("%d ", val);
        for (int adjacent = 0; adjacent < g->v; adjacent++)
        {
            if (g->adj[val][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

void dfs(graph *g, int val)
{
    // creating a boolean visited array for checking the status of the node.
    int visited[max_vert], i;
    for (i = 0; i < max_vert; i++)
    {
        visited[i] = false;
    }
    // creating a stack.
    int stack[max_vert], top = 0;
    // push the start node into the stack.
    stack[top] = val;
    visited[val]=true;
    while (top >= 0)
    {
        val=stack[top--];
        printf("%d ",val);
        for (int adjacent = 0; adjacent < g->v; adjacent++)
        {
            if (g->adj[val][adjacent] && !visited[adjacent])
            {
                stack[++top] = adjacent;
                visited[adjacent] = true;
            }
        }
        
    }
}
int main()
{
    graph *g;
    printf("enter number of nodes : ");
    int nodes;
    scanf("%d", &nodes);
    g = create_graph(nodes);
    printf("enter the total number of edges :");
    int num_edges;
    scanf("%d", &num_edges);
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        printf("enter the nodes that forms an edge seprated by spaces :");
        scanf("%d %d", &u, &v);
        add_edge(g, u, v);
    }

    printf("the adjacency matrix is :\n");
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }

    printf("enter the node to start the bfs traversal from that node : ");
    int st_node;
    scanf("%d", &st_node);
    bfs(g, st_node);
    printf("\n");

    printf("enter the node to start the dfs travversal from that node : ");
    scanf("%d", &st_node);
    dfs(g, st_node);
    printf("\n");
    return 0;
}