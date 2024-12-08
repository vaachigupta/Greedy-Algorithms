#include <limits.h>
#include <stdio.h>
#define max 9


/*void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < max; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}
*/

void dijkstra(int graph[max][max], int src) {
    int distance[max]; 
    int visited[max]; 
    int parent[max]; 
    int i, j, min_distance, next_vertex;

    for (i = 0; i < max; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1; 
    }

    distance[src] = 0; 

    for (i = 0; i < max - 1; i++) {
        min_distance = INT_MAX;
        for (j = 0; j < max; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                next_vertex = j;
            }
        }

        visited[next_vertex] = 1; 

        for (j = 0; j < max; j++) {
            if (!visited[j] && graph[next_vertex][j] != 0 && distance[next_vertex] + graph[next_vertex][j] < distance[j]) {
                distance[j] = distance[next_vertex] + graph[next_vertex][j];
                parent[j] = next_vertex; 
            }
        }
    }

    printf("Vertex\tShortest Path from %d\n", src);
    for (i = 0; i < max; i++) {
        if (i == src) {
            printf("%d \t%d\n", i, i);
        } else {
            printf("%d \t", i);
            int current = i;
            while (current != -1) {
                printf("%d ", current);
                current = parent[current];
            }
            printf("\n");
        }
    }
}


int main()
{
    int graph[max][max]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int src = 0;
    dijkstra(graph, src);
    return 0;
}

