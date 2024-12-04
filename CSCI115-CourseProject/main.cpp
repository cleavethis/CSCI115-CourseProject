// Rick Richmond
#include "OrderManager.h"
#include "OrderList.h"
#include "OrderSkipList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	OrderManager manager;

	manager.addOrder("ORD1", 1, "Location A");
	manager.addOrder("ORD2", 2, "Location B");
	manager.addOrder("ORD3", 3, "Location C");

	int foundIndex1 = manager.linearSearch("ORD1");
	int foundIndex2 = manager.linearSearch("ORD2");
	int foundIndex3 = manager.linearSearch("ORD3");

	string orderIDs[] = { "ORD1", "ORD2", "ORD3" };
	
	for (int i = 0; i < 3; i++) {
		int foundIndex = manager.linearSearch(orderIDs[i]);

		if (foundIndex < 0) {
			cout << "Order " << orderIDs[i] << " not found!" << endl;
		}
		else {
			cout << "-----Order details for " << orderIDs[i] << "----- \n";
			cout << "Order ID: " << manager.getOrder(foundIndex).orderID << "\n";
			cout << "Order priority: " << manager.getOrder(foundIndex).orderPriority << "\n";
			cout << "Order destination: " << manager.getOrder(foundIndex).orderDestination << "\n";
		}
	}

	manager.displayOrders();


	

	OrderList list;
	list.appendNode("ORD1", 1, "New York");
	list.appendNode("ORD2", 3, "California");
	list.displayList();

	list.searchList("ORD3");

	
	
	



	

	return 0;
}