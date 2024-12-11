#include "Graph.h"
#include <iostream>
using namespace std;

// Adds an edge from 'from' node to 'to' node with the given weight
void Graph::addEdge(const string& from, const string& to, int weight) {
    adjList[from].emplace_back(to, weight);
}

// Displays the graph in the adjacency list format
void Graph::display() const {
    for (const auto& node : adjList) {
        cout << node.first << ": ";
        for (const auto& edge : node.second) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}
