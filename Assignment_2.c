/*

    @Ranjeetkumbhar01
    Assignment_2

***************************/
#include <stdio.h>
struct edge
{
    int src;
    int dest;
    int wt;
};

// global variable for storing number of vertex and edges
int V, E;
// bellman For Algorithm Implementation
void BellmanFord(struct edge *Edge, int source)
{
    int Infinity = 100000, u, v, w; // Defining the infinity value and some useful variable
    int distance[V];                // Array to store the distance of  each vertex from source

    // making all the distance as Infinity
    for (int i = 0; i < V; i++)
        distance[i] = Infinity;

    // making source as the zero
    distance[source] = 0;

    // printing initial distance array

    // V-1 Iteration for calculating the Distance from Source
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = Edge[j].src;
            v = Edge[j].dest;
            w = Edge[j].wt;

            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    // Checking whether given graph form **negative cycle** or not
    for (int j = 0; j < E; j++)
    {
        u = Edge[j].src;
        v = Edge[j].dest;
        w = Edge[j].wt;
        if (distance[v] > distance[u] + w)
        {
            printf("\n Graph is generated the Negative Cycle\n bellman ford algorithm does not work when the graph contains the negative weight cycle.");
            return;
        }
    }

    // printing the calculated minimum distance of each vertex from Source
    printf("\n\t Final Distance\n\n");
    printf("\nVertex\t:\tDistance");
    for (int i = 0; i < V; i++)
        printf("\n%d\t:\t%d", i, distance[i]);
    printf("\n===============================================");
}
void main()
{

    // taking Number of Vertex
    printf("Enter the Number of Vertex : ");
    scanf("%d", &V);

    // taking number of Edge
    printf("Enter the Number of Edge : ");
    scanf("%d", &E);

    struct edge Edge[E]; // defining the array of structure

    // taking each edge
    printf("Enter the Each Edge (give name 1st vertex as 0)");
    printf("\n     Source\tDestination\tWeight\n\n");
    for (int i = 0; i < E; i++)
    {

        printf("Edge %d   ", i + 1);
        // printf("\n\t Source:");
        scanf("%d", &Edge[i].src);
        // printf("\n\t Destination:");
        scanf("%d", &Edge[i].dest);
        // printf("\n\t Weight:");
        scanf("%d", &Edge[i].wt);
    }
    printf("\n------------------------------------------------------------------------");
    // calling the Function
    BellmanFord(Edge, 0);
}

/* OUTPUT

Enter the Number of Vertex : 6
Enter the Number of Edge : 9
Enter the Each Edge (give name 1st vertex as 0)
     Source     Destination     Weight

Edge 1   0 1 6
Edge 2   0 2 4
Edge 3   0 3 5
Edge 4   1 4 -1
Edge 5   2 4 3
Edge 6   2 1 -2
Edge 7   3 2 -2
Edge 8   3 5 -1
Edge 9   4 5 3

------------------------------------------------------------------------
         Final Distance

Vertex  :       Distance
0       :       0
1       :       1
2       :       3
3       :       5
4       :       0
5       :       3
===============================================*/

/* OUTPUT : Negative Cycle
Enter the Number of Vertex : 4
Enter the Number of Edge : 5
Enter the Each Edge (give name 1st vertex as 0)
     Source     Destination     Weight

Edge 1   0 1 4
Edge 2   0 2 5
Edge 3   2 1 7
Edge 4   1 3 7
Edge 5    3 2 -15

------------------------------------------------------------------------
 Graph is generated the Negative Cycle
 bellman ford algorithm does not work when the graph contains the negative weight cycle.
 */
