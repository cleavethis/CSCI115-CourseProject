#include "OrderSkipList.h"


OrderSkipList::OrderSkipList()
{
	head = new Node("", 0, "", MAX_LEVELS);
	level = 0;
}

void OrderSkipList::insert(string orderID, int orderPriority, string orderDestination) {
	// start at level 0
	int newLevel = 0;
	// usre rand() to determine level for newly inserted node
	while (newLevel < MAX_LEVELS && (rand() % 2) == 1) {
		newLevel++;
	}

	// if  newLevel is higher than list level, adjust
	if (level < newLevel) {
		head->next.resize(newLevel + 1, nullptr);

		level = newLevel;
	}

	
	Node* currNode = head;
	//stores each updated node at each level
	vector<Node*> update(level + 1, nullptr);
	// traverse list and keep track of nodes to update
	for (int i = level; i >= 0; i--) {

		while (currNode->next[i] != nullptr && currNode->next[i]->orderID < orderID) {
			currNode = currNode->next[i];
		}

		update[i] = currNode; // this is the node to update at current level
	}
	// drop back down to levle 0 and proceed to next node
	currNode = currNode->next[0];
	// handles inserting a node into an empty list
	if (currNode == nullptr || currNode->orderID != orderID) {

		Node* newNode = new Node(orderID, orderPriority, orderDestination, level);

		for (int i = 0; i < newLevel; i++) {

			newNode->next[i] = update[i]->next[i];
			update[i]->next[i] = newNode;
		}

		cout << "Order: " << orderID << "\n"
			 << orderPriority << "\n" << orderDestination << "\n" 
			 << "inserted into list.\n";
	}

	else {
		cout << "Order with " << orderID << " already exists.\n";
	}

}

bool OrderSkipList::search(string searchID)
{
	// pointer to start of list
	Node* current = head;

	// start at highest level and move down
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
