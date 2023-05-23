// This program demonstrates Prim's algorithm for finding the Minimum Spanning Tree (MST) of a graph.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value among the vertices not yet included in MST
int findMinKey(vector<int> &key, vector<bool> &mst_set, int V)
{
    int minimum_key = INT_MAX;
    int mininum_index = -1;

    // Iterate through all vertices to find the minimum key value
    for (int i = 0; i < V; ++i)
    {
        if (!mst_set[i] && key[i] < minimum_key)
        {
            minimum_key = key[i];
            mininum_index = i;
        }
    }

    return mininum_index;
}

// Function to print the MST
void printMST(const vector<int> &parent, const vector<vector<int>> &graph, int V)
{
    cout << "Edge \tWeight\n";
    // Iterate through all vertices (excluding the root) to print the MST edges and their weights
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Function to calculate and print the MST using Prim's algorithm
void primMST(const vector<vector<int>> &graph, int V)
{
    // Vector to store the parent of each vertex in the MST
    vector<int> parent(V);
    // Vector to store the key values used to pick minimum weight edge
    vector<int> key(V, INT_MAX);

    // Vector to keep track of vertices included in MST
    vector<bool> mst_set(V, false);

    // Set the key value of the root vertex as 0 and mark it as included in MST
    key[0] = 0;
    parent[0] = -1;

    // Find and include V-1 edges in the MST
    for (int count = 0; count < V - 1; ++count)
    {
        // Find the vertex with the minimum key value from the set of vertices not yet included in MST
        int u = findMinKey(key, mst_set, V);

        // Mark the selected vertex as included in MST
        mst_set[u] = true;

        // Update the key values and parent pointers of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; ++v)
        {
            // Update the key value and parent only if the vertex is not yet included in MST,
            // there is an edge between u and v, and the weight of the edge is less than the current key value of v
            if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph, V);
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    // Create a 2D vector to represent the graph as an adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";

    // Input the adjacency matrix from the user
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    // Calculate and print the MST using Prim's algorithm
    primMST(graph, V);

    return 0;
}