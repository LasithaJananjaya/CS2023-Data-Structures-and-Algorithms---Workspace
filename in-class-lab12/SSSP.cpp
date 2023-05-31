#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define vertices 6

// Function to find the vertex with the minimum distance value
int min_distance(int distance[], bool shortest_path_tree_set[])
{

    // Define minimum value
    int minimum = INT_MAX, minimum_index;

    // Find the vertex with the minimum distance value
    for (int i = 0; i < vertices; i++)
    {
        if (shortest_path_tree_set[i] == false && distance[i] <= minimum)
        {
            minimum = distance[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}

// Function to print the shortest time between source and all vertices
void print_solution(int distance[], int source)
{
    for (int i = 0; i < vertices; i++)
    {
        printf("The shortest time between %d and %d is: %d \n", source, i, distance[i]);
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[vertices][vertices], int source)
{
    int distance[vertices];
    bool shortest_path_tree_set[vertices];

    // Initialize distance values and shortest_path_tree_set flags
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        shortest_path_tree_set[i] = false;
    }

    distance[source] = 0; // Set the distance of source vertex to 0

    // Find the shortest paths for all vertices
    for (int count = 0; count < vertices - 1; count++)
    {
        int min_vertex = min_distance(distance, shortest_path_tree_set); // Select the vertex with minimum distance

        shortest_path_tree_set[min_vertex] = true; // Mark the selected vertex as processed

        // Update distance values of the adjacent vertices of the selected vertex
        for (int vertex = 0; vertex < vertices; vertex++)
        {
            if (!shortest_path_tree_set[vertex] && graph[min_vertex][vertex] && distance[min_vertex] != INT_MAX && distance[min_vertex] + graph[min_vertex][vertex] < distance[vertex])
            {
                distance[vertex] = distance[min_vertex] + graph[min_vertex][vertex];
            }
        }
    }
    print_solution(distance, source); // Print the solution
}

int main()
{
    int graph[vertices][vertices] = {{0, 10, 0, 0, 15, 5},
                                     {10, 0, 10, 30, 0, 0},
                                     {0, 10, 0, 12, 5, 0},
                                     {0, 30, 12, 0, 0, 20},
                                     {15, 0, 5, 0, 0, 0},
                                     {5, 0, 0, 20, 0, 0}};

    dijkstra(graph, 0); // Run Dijkstra's algorithm starting from vertex 5

    return 0;
}
