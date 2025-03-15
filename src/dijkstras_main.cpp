#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "dijkstras.h"
#include "dijkstras.cpp"

using namespace std;

int main() {
    string filename = "src/largest.txt";
    
    Graph G;

    try {
        file_to_graph(filename, G);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    if (source < 0 || source >= G.numVertices || destination < 0 || destination >= G.numVertices) {
        cerr << "Error: Invalid vertex number." << endl;
        return 1;
    }

    // Vector to store the previous vertex for path reconstruction
    vector<int> previous(G.numVertices, -1);

    // Find the shortest paths from the source using Dijkstra's algorithm
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    // Extract the shortest path from source to destination
    vector<int> path = extract_shortest_path(distances, previous, destination);

    // Get the total distance to the destination
    int total_distance = distances[destination];

    // Print the result
    if (total_distance == INT_MAX) {
        cout << "No path found from " << source << " to " << destination << "." << endl;
    } else {
        print_path(path, total_distance);
    }

    return 0;
}
