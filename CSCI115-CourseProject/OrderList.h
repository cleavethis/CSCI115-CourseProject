#ifndef ORDERLIST_H
#define ORDERLIST_H
#include <iostream>
using namespace std;

class OrderList
{
private:

	struct Node {
		string orderID;
		int orderPriority;
		string orderDestination;
		Node* next;
		// Previous pointer for double linked list
		Node* prev;

	};

	Node* head;
	Node* tail;

public:

	OrderList();
	void appendNode(string, int, string);
	void displayList() const;
	void searchList(string);
	void printNode(Node*);
	void removeNode(string);
	void reverseDisplay() const;
	void updatePriority(string,int);




};
#endif ORDERLIST_H

