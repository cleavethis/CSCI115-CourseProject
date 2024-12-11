#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {

    addEdge("a", "b", 10);
    addEdge("a", "c", 15);
    addEdge("b", "i", 11);
    addEdge("b", "d", 12);
    addEdge("c", "e", 10);
    addEdge("d", "h", 14);
    addEdge("e", "g", 4);
    addEdge("e", "f", 5);
    addEdge("f", "g", 3);
    addEdge("g", "h", 8);
    addEdge("h", "i", 7);
    addEdge("i", "j", 6);
    addEdge("j", "a", 6);
}

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
