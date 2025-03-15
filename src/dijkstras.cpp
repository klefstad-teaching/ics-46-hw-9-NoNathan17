#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.size();  // Number of vertices in the graph
    vector<int> distances(n, INF);  // Initialize distances as infinity
    vector<bool> visited(n, false);  // Visited vertices

    // Min-priority queue to store the vertex with its current shortest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance to the source is 0
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;  // Vertex with the current shortest distance
        pq.pop();

        // Skip if the vertex has already been visited
        if (visited[u]) continue;

        visited[u] = true;

        // Explore all the neighbors of the current vertex
        for (const Edge& e : G[u]) {
            int v = e.dst;  
            int weight = e.weight; 

            // update the distance if a shorter path is found
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;  // Record the previous vertex in the path
                pq.push({distances[v], v});  // Push the updated distance to the priority queue
            }
        }
    }

    return distances;  // Return the array of distances from the source to each vertex
}

// Function to extract the shortest path from the source to the destination
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int v = destination; v != 0; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Function to print the shortest path and its total distance
void print_path(const vector<int>& path, int total) {
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size()) cout << " "; 
    }

    cout << "\n";
    cout << "Total cost is " << total << endl;
}
