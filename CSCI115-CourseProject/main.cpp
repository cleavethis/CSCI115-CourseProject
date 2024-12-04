// Rick Richmond
#include "OrderManager.h"
#include "OrderList.h"
#include "OrderSkipList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	OrderManager manager;
	string dest = "New York";

	manager.addOrder("ORD1", 1, dest);
	int foundIndex = manager.linearSearch("ORD1");
	

	if (foundIndex < 0) {
		cout << "order not found!";
	}

	else {
		
		cout << "-----Order details----- \n";
		cout << "Order ID: " << manager.getOrder(foundIndex).orderID << "\n";
		cout << "Order priority: " << manager.getOrder(foundIndex).orderPriority << "\n";
		cout << "Order destination: " << manager.getOrder(foundIndex).orderDestination << "\n";

	}
	

	OrderList list;
	list.appendNode("ORD1", 1, "New York");
	list.appendNode("ORD2", 3, "California");
	list.displayList();

	list.searchList("ORD3");

	
	
	



	

	return 0;
}