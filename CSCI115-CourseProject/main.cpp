// Rick Richmond
#include "OrderManager.h"
#include "OrderList.h"
#include "OrderSkipList.h"
#include "OrderBST.h"
#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Part 1 array, see OrderManager.cpp/OrderManager.h
	OrderManager manager;

	manager.addOrder("ORD2", 2, "Location B");
	manager.addOrder("ORD3", 3, "Location C");
	manager.addOrder("ORD1", 1, "Location A");

	int foundIndex1 = manager.linearSearch("ORD1");
	int foundIndex2 = manager.linearSearch("ORD2");
	int foundIndex3 = manager.linearSearch("ORD3");

	string orderIDs[] = { "ORD1", "ORD2", "ORD3" };
	
	cout << "---Searching order list---\n\n";
	for (int i = 0; i < 3; i++) {
		int foundIndex = manager.linearSearch(orderIDs[i]);

		if (foundIndex < 0) {
			cout << "Order " << orderIDs[i] << " not found!" << endl;
		}
		else {
			cout << "-----Order details for " << orderIDs[i] << "----- \n";
			cout << "Order ID: " << manager.getOrder(foundIndex).orderID << "\n";
			cout << "Order priority: " << manager.getOrder(foundIndex).orderPriority << "\n";
			cout << "Order destination: " << manager.getOrder(foundIndex).orderDestination << "\n\n";
		}
	}

	cout << "***Displaying orders in array*** \n\n";
	manager.displayOrders();
	cout << "------End of order array------\n\n";


	
	// Part 1 linked list/doubly linked list, see OrderList.cpp/OrderList.h
	OrderList list;
	list.appendNode("ORD4", 4, "Location D");
	list.appendNode("ORD5", 5, "Location E");
	list.appendNode("ORD6", 1, "Location F");
	cout << "***Displaying orders in linked list***\n\n";
	list.displayList();
	cout << "------End of order linked list------\n\n";
	cout << "Searching for ORD4\n\n";
	list.searchList("ORD4");
	cout << endl;

	// Part 1 skip list, see OrderSkipList.cpp/OrderSkipList.h

	OrderSkipList skipList;
	skipList.insert("ORD7", 2, "Location G");
	skipList.insert("ORD8", 3, "Location H");
	skipList.insert("ORD9", 4, "Location I");

	skipList.deleteNode("ORD8");
	skipList.search("ORD6");
	skipList.display();

	// Part 2: sorting the array from part 1:
	// Generates an array of 100 order elements
	manager.populateOrders();

	// Show unsorted array
	cout << "*****Unsorted Array*****\n\n";
	manager.displayOrders();
	// Sort in O(n^2) time
	manager.bubbleSort(manager.getOrders());
	cout << "Sorted orders:\n\n";
	manager.displayOrders();
	cout << "*****End of bubble sort*****\n\n";

	// Prepare for selection sort
	manager.scrambleOrders();
	cout << "*****Unsorted Array*****\n\n";
	manager.displayOrders();
	// Sort in O(n^2) time
	manager.selectionSort(manager.getOrders());
	cout << "Sorted orders:\n\n";
	manager.displayOrders();
	cout << "*****End of selection sort*****\n\n";

	// Prepare for merge sort
	manager.scrambleOrders();
	cout << "*****Unsorted Array*****\n\n";
	manager.displayOrders();
	manager.mergeSort(manager.getOrders());
	cout << "Sorted orders: \n\n";
	manager.displayOrders();
	cout << "*****End of merge sort*****\n\n";

	// Prepare for quick sort
	manager.scrambleOrders();
	cout << "*****Unsorted Array*****\n\n";
	manager.displayOrders();
	manager.quickSort(manager.getOrders());
	cout << "Sorted orders: \n\n";
	manager.displayOrders();
	cout << "*****End of quick sort*****\n\n";
	cout << "-----AVL Tree implementation-----\n\n";
	// Create new ALV tree and populate with data (see OrderBST.cpp constructor)
	OrderBST newTree;
	cout << "Searching for ORD32\n";
	newTree.search("ORD32");
	cout << "\nSearching for ORD20\n";
	newTree.search("ORD20");
	cout << "\nSearching for ORD49\n";
	newTree.search("ORD49");
	cout << "\nSearching for ORD51\n";
	newTree.search("ORD51");
	cout << "\nSearching for ORD56\n";
	newTree.search("ORD56");
	cout << "\nSearching for ORD71\n";
	newTree.search("ORD71");
	

	cout << "\n-----Graph implmentation-----";
	// Create the graph
	Graph g;
	cout << "\n\nGraph adjacency list: \n";
	g.display();
	cout << "\nBreadth first traversal from A: \n\n";
	g.BFS("a");
	cout << "\n\n";
	cout << "Depth first traversal from A: \n\n";
	g.DFS("a");
	cout << "\n\n";
	cout << "-----Using Dijkstra's to find shortest path-----\n\n";
	g.dijkstra("a");
	g.printShortestPath("e");
	cout << endl;
	g.printShortestPath("h");
	cout << endl;
	g.printShortestPath("f");

	return 0;
}