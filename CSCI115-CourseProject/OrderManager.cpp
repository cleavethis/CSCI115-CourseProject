#include "OrderManager.h"
using namespace std;


bool OrderManager::addOrder(string orderID, int orderPriority, string orderDestination)
{
	if (orderCount >= MAX_ORDERS) {
		cout << "Order list full, can't add a new order.";
		return false;
	}

	orders[orderCount++] = { orderID, orderPriority, orderDestination };
	return true;
}

void OrderManager::displayOrders() const
{
	for (int i = 0; i < orderCount; i++) {
		cout << "Order id: " << orders[i].orderID << "\n";
		cout << "Order priority: " << orders[i].orderPriority << "\n";
		cout << "Order destination: " << orders[i].orderDestination << "\n";
		cout << endl;
	}
}

 int OrderManager::linearSearch(string searchID)
{
	for (int i = 0; i < orderCount; i++) {
		if (searchID == orders[i].orderID) {
		 
			return i;
		}
	}
	return -1;
}

 OrderManager::Order& OrderManager::getOrder(int index) {
	 return orders[index];
}