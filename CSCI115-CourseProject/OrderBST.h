#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>
using namespace std;

class OrderBST {
private:

    struct Node {
        string orderID;
        int orderPriority;
        string orderDestination;
        Node* left;
        Node* right;
        int height;

        Node(string id, int priority, string destination)
            : orderID(id), orderPriority(priority), orderDestination(destination), left(nullptr), right(nullptr) {
        }
    };

    Node* root;

    void insert(Node*&, string, int, string);
    void inOrderTraversal(Node*) const;
    Node* search(Node*, const string&) const;
    Node* deleteNode(Node*, const string&);
    // AVL Functions
    int getHeight(Node*) const;
    int getBalanceFactor(Node*) const;
    Node* leftRotate(Node*);
    Node* rightRotate(Node*);
    Node* rebalance(Node*, const string&);
  

public:
    OrderBST();
    void insert(string, int, string);
    void displayInOrder() const;
    Node* search(const string&) const;
    void deleteNode(const string&);
    Node* findMin(Node*) const;
};

#endif
