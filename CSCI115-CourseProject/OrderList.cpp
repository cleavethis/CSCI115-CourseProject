#include "OrderList.h"


// Construct an empty list
OrderList::OrderList() {
	head = nullptr;
	tail = nullptr;
}

// Create and populate a new node, traverse to end and append
void OrderList::appendNode(string orderId, int priority, string destination)
{
	Node* newNode = new Node;
	newNode->orderID = orderId;
	newNode->orderPriority = priority;
	newNode->orderDestination = destination;
	newNode->next = nullptr;
	

	// If list is empty new node becomes head & tail
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	// Use tail pointer to assign new node
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void OrderList::displayList() const
{
	if (!head) {
		cout << "List is empty";
		return;
	}
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

// Helper function for searchList
void OrderList::printNode(Node* node) {
	if (node) {
		cout << "ID: " << node->orderID
			<< ", Priority: " << node->orderPriority
			<< ", Destination: " << node->orderDestination << endl;
	}
}

void OrderList::removeNode(string removeID)
{
	Node* nodePtr;
	nodePtr = head;

	if (!head) {
		cout << "List is empty, nothing to remove.";
		return;
	}

	while (nodePtr) {
		// Found node to remove
		if (nodePtr->orderID == removeID) {
			// If a previous node exists, update previous.next with current.next
			if (nodePtr->prev)
				nodePtr->prev->next = nodePtr->next;
			// If a next node exists, update next.previous with current.previous
			if (nodePtr->next)
				nodePtr->next->prev = nodePtr->prev;
			// If current is head, update head to be current.next
			if (nodePtr == head)
				head = nodePtr->next;
			if (nodePtr == tail)
				tail = nodePtr->prev;

			delete nodePtr;
			cout << "Order removed: " << removeID << "\n";
			
			return;
		}

		nodePtr = nodePtr->next;

	}
	cout << "No order with ID " << removeID << " found, exiting.";

}

void OrderList::reverseDisplay() const
{
	Node* nodePtr;
	nodePtr = tail;
	cout << "Reverse list: \n";

	while (nodePtr) {
		cout << "Order ID: " << nodePtr->orderID << "\n"
			<< "Order Priority " << nodePtr->orderPriority << "\n"
			<< "Order Destination " << nodePtr->orderDestination << "\n";
		nodePtr = nodePtr->prev;
	}

}

void OrderList::updatePriority(string updateID, int newPriority)
{
	// Empty list
	if (!head) {
		cout << "List is empty.";
		return;
	}

	Node* nodePtr;
	nodePtr = head;

	while (nodePtr) {
		// Update priority and display result to user.
		if (nodePtr->orderID == updateID) {
			cout << "Order " << updateID << " current priority: " << nodePtr->orderPriority
				<< " updated to: " << newPriority << "\n";
			nodePtr->orderPriority = newPriority;
			
			return;
		}
		nodePtr = nodePtr->next;
	}
	// No match
	cout << "Order ID " << updateID << " does not exist, exiting." << "\n";

}








