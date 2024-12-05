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

	static const int MAX_ORDERS = 10000;
	Order orders[MAX_ORDERS];
	int orderCount;


public:
	OrderManager() : orderCount(0) {}
	void populateOrders();
	bool addOrder(string, int, string);
	void displayOrders() const;
	int linearSearch(string);
	Order& getOrder(int);
	void bubbleSort(Order*);
	void selectionSort(Order*);
	void merge(Order*, int, int, int);
	void mergeSortUtil(Order*, int, int);
	void mergeSort(Order*);
	int partition(Order*, int, int);
	void quickSortUtil(Order*, int, int);
	void quickSort(Order*);





};


#endif ORDERMANAGER_H

