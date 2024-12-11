#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class Graph {
public:
   
    using AdjList = unordered_map<string, list<pair<string, int>>>;

    Graph() = default;
    void addEdge(const string&, const string&, int);
    void display() const;

private:
    AdjList adjList;  
};

#endif // GRAPH_H
