#ifndef ORDERSKIPLIST_H
#define ORDERSKIPLIST_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "OrderManager.h"
using namespace std;

const int MAX_LEVELS = 5;

class Node {
public:
	string orderID;
	int orderPriority;
	string orderDestination;

	vector<Node*> next;
	Node(string orderID, int orderPriority, string orderDestination, int level) : orderID(orderID), 
		orderPriority(orderPriority), orderDestination(orderDestination), next(level + 1, nullptr) {}
};

class OrderSkipList
{
private:
	Node* head;
	int level;
public:
	OrderSkipList();
	void insert(string, int, string);
	bool search(string);
	void deleteNode(string);

};
#endif  ORDERSKIPLIST_H


