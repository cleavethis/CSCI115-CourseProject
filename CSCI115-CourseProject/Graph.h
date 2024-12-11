#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <string>
using namespace std;
using AdjList = unordered_map<string, list<pair<string, int>>>;

class Graph {
private:
    
    AdjList adjList;

public:
   
    Graph();
    void addEdge(const string&, const string&, int);
    void display() const;
    
};

#endif // GRAPH_H
