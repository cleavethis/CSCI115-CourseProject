#include "OrderSkipList.h"


OrderSkipList::OrderSkipList()
{
	head = new Node("", 0, "", MAX_LEVELS);
	level = 0;
}

void OrderSkipList::insert(string orderID, int orderPriority, string orderDestination) {
	// Start at level 0
	int newLevel = 0;
	// Usre rand() to determine level for newly inserted node
	while (newLevel < MAX_LEVELS && (rand() % 2) == 1) {
		newLevel++;
	}

	// If  newLevel is higher than list level, adjust
	if (level < newLevel) {
		head->next.resize(newLevel + 1, nullptr);

		level = newLevel;
	}

	
	Node* currNode = head;
	// Stores each updated node at each level
	vector<Node*> update(level + 1, nullptr);
	// Traverse list and keep track of nodes to update
	for (int i = level; i >= 0; i--) {

		while (currNode->next[i] != nullptr && currNode->next[i]->orderID < orderID) {
			currNode = currNode->next[i];
		}

		update[i] = currNode; // This is the node to update at current level
	}
	// Drop back down to levle 0 and proceed to next node
	currNode = currNode->next[0];
	// Handles inserting a node into an empty list
	if (currNode == nullptr || currNode->orderID != orderID) {

		Node* newNode = new Node(orderID, orderPriority, orderDestination, level);

		for (int i = 0; i < newLevel; i++) {

			newNode->next[i] = update[i]->next[i];
			update[i]->next[i] = newNode;
		}

		cout << "Order: " << orderID << "\n"
			 << orderPriority << "\n" << orderDestination << "\n" 
			 << "inserted into list.\n\n";
	}

	else {
		cout << "Order with " << orderID << " already exists.\n";
	}

}

bool OrderSkipList::search(string searchID)
{
	// Pointer to start of list
	Node* current = head;

	// Start at highest level and move down
	for (int i = level; i >= 0; i--)
	{
		while (current->next[i] and current->next[i]->orderID < searchID)
		{
			current = current->next[i];

		}
	}

	current = current->next[0];

	if (current != nullptr && current->orderID == searchID)
	{
		cout << "Order: " << current->orderID << current->orderPriority << current->orderDestination;
		return true;
	}
	else  // Order not found
	{
		cout << "Order " << searchID << " not found.\n";
		return false;
	}
}

void OrderSkipList::deleteNode(string orderID) {
	Node* current = head;
	vector<Node*> update(level + 1, nullptr);  // Store the nodes to update at each level

	// Search for the node and store the previous nodes at each level
	for (int i = level; i >= 0; i--) {
		while (current->next[i] != nullptr && current->next[i]->orderID < orderID) {
			current = current->next[i];
		}
		update[i] = current;  
	}

	
	current = current->next[0];

	// If the node exists and matches the orderID, proceed with deletion
	if (current != nullptr && current->orderID == orderID) {
		// Update the next pointers for each level
		for (int i = 0; i <= level; i++) {
			
			if (update[i]->next[i] != nullptr && update[i]->next[i]->orderID == orderID) {
				update[i]->next[i] = current->next[i];  
			}
		}

		// If the node was at the highest level, decrease the level of the skip list
		while (level > 0 && head->next[level] == nullptr) {
			level--;
		}

		cout << "Order: " << orderID << " deleted from the list.\n";
		delete current;  
	}
	else {
		cout << "Order " << orderID << " not found, deletion not performed.\n";
	}
}
// Display all levels and elements
void OrderSkipList::display() {
	cout << "\nDisplaying Skip List:\n";

	for (int i = level; i >= 0; i--) {
		Node* current = head->next[i];
		cout << "Level " << i << ": ";

		
		while (current != nullptr) {
			cout << "[" << current->orderID << ", " << current->orderPriority << ", " << current->orderDestination << "] -> ";
			current = current->next[i];
		}
		cout << "NULL\n";
	}
}
