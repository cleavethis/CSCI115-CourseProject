#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;
// Map used to implement Adjacency list to store vertices and edges
using AdjList = unordered_map<string, list<pair<string, int>>>;

class Graph {
private:
    
    AdjList adjList;
    void DFSHelper(const string& node, unordered_set<string>& visited) const;
    unordered_map<string, int> distances; // Stores shortest distances
    unordered_map<string, string> predecessors; // Stores the path

public:
   
    Graph();
    void addEdge(const string&, const string&, int);
    void display() const;
    void DFS(const string&) const;
    void BFS(const string&) const;
    void dijkstra(const string&);
    void printShortestPath(const string&) const;
    
};

#endif GRAPH_H
