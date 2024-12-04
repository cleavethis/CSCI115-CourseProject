#include "OrderList.h"


// Construct an empty list
OrderList::OrderList() {
	head = nullptr;
}

// Create and populate a new node, traverse to end and append
void OrderList::appendNode(string orderId, int priority, string destination)
{
	Node* newNode = new Node;
	Node* nodePtr;
	newNode->orderID = orderId;
	newNode->orderPriority = priority;
	newNode->orderDestination = destination;
	newNode->next = nullptr;

	// If list is empty new node becomes head
	if (!head) {
		head = newNode;
	}
	// Traverse and append
	else {
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

void OrderList::displayList() const
{
	Node* nodePtr;
	// Start at head and display node details
	nodePtr = head;

	while (nodePtr) {
		cout << "OrderID: " << nodePtr->orderID << "\n";
		cout << "Order priority: " << nodePtr->orderPriority << "\n";
		cout << "Order destination: " << nodePtr->orderDestination << "\n";
		cout << endl;
		// Move to next node
		nodePtr = nodePtr->next;
	}
}

void OrderList::searchList(string searchID) {
	// Empty list
	if (!head) {
		cout << "List is empty.";
		return;
	}

	Node* nodePtr;
	nodePtr = head;

	while (nodePtr) {
		// Match found
		if (nodePtr->orderID == searchID) {
			cout << "Order found: ";
			printNode(nodePtr);
			return;
		}
		nodePtr = nodePtr->next;
	}
	// No match
	cout << "Order ID " << searchID << " not found." << "\n";

}


void OrderList::printNode(Node* node) {
	if (node) {
		cout << "ID: " << node->orderID
			<< ", Priority: " << node->orderPriority
			<< ", Destination: " << node->orderDestination << endl;
	}
}






