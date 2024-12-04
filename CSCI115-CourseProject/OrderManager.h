#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H
#include <iostream>
using namespace std;



class OrderManager
{
private: 

	struct Order {

		string orderID;
		int orderPriority;
		string orderDestination;

	};

	static const int MAX_ORDERS = 100;
	Order orders[MAX_ORDERS];
	int orderCount;
	

public:
	OrderManager() : orderCount(0) {}
	bool addOrder(string, int, string);
	void displayOrders() const;
	int linearSearch(string);
	Order& getOrder(int);
	
	



};


#endif ORDERMANAGER_H

