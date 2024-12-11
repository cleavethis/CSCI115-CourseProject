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


void Graph::DFS(const string& start) const {
    unordered_set<string> visited;
    DFSHelper(start, visited);
}

// Helper function for DFS traversal
void Graph::DFSHelper(const string& node, unordered_set<string>& visited) const {
    // Visit node
    visited.insert(node);
    cout << node << " ";

    // Repeat for adj. nodes
    for (const auto& neighbor : adjList.at(node)) {
        if (visited.find(neighbor.first) == visited.end()) {
            DFSHelper(neighbor.first, visited);
        }
    }
}


void Graph::BFS(const string& start) const {
    // Use a set to store visited nodes, and a queue for BFS
    unordered_set<string> visited;
    queue<string> q;

    // Start with the given node
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        // Get the current node and print it
        string node = q.front();
        q.pop();
        cout << node << " ";

        // Add all unvisited adjacent nodes to the queue
        for (const auto& neighbor : adjList.at(node)) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first);
                q.push(neighbor.first);
            }
        }
    }
}

void Graph::dijkstra(const string& start) {
    // Initialize all distances as infinite and predecessors as empty
    for (const auto& node : adjList) {
        distances[node.first] = INT_MAX;
        predecessors[node.first] = "";
    }
    distances[start] = 0;

    // Priority queue to store nodes with their distances
    priority_queue<pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        // Get the node with the smallest distance
        int dist = pq.top().first;
        string node = pq.top().second;
        pq.pop();

        // If this distance is already worse than the known one, skip it
        if (dist > distances[node]) continue;

        // Explore all neighbors of the current node
        for (const auto& neighbor : adjList[node]) {
            int newDist = dist + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                predecessors[neighbor.first] = node;
                pq.push({ newDist, neighbor.first });
            }
        }
    }
}

// Outputs the shortest path and distance from the start node to a given destination
void Graph::printShortestPath(const string& destination) const {
    if (distances.find(destination) == distances.end() || distances.at(destination) == INT_MAX) {
        cout << "No path to " << destination << " exists." << endl;
        return;
    }

    stack<string> path;
    string current = destination;

    // Reconstruct the path from destination to start
    while (current != "") {
        path.push(current);
        current = predecessors.at(current);
    }

    cout << "Shortest path to " << destination << ": ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    cout << "\nTotal distance: " << distances.at(destination) << endl;
}
