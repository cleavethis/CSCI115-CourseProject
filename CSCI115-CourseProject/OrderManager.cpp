#include "OrderManager.h"
#include <cstdlib>
#include <ctime>
#include <string>
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

 void OrderManager::bubbleSort(Order* orders) {
	 // Compare each element to adjacent elements (priority) and swap if needed
	 for (int i = 0; i < orderCount - 1; ++i) {
		 for (int j = 0; j < orderCount - i - 1; ++j) {
			 if (orders[j].orderPriority > orders[j + 1].orderPriority) {
				 // Swap orders[j] and orders[j + 1]
				 Order temp = orders[j];
				 orders[j] = orders[j + 1];
				 orders[j + 1] = temp;
			 }
		 }
	 }
 }
 // Find minimum of entire array then place at minIndex
 void OrderManager::selectionSort(Order* orders) {

	 for (int i = 0; i < orderCount - 1; ++i) {
		 int minIndex = i;
		 for (int j = i + 1; j < orderCount; ++j) {
			 if (orders[j].orderPriority < orders[minIndex].orderPriority) {
				 minIndex = j;
			 }
		 }
		 // Swap orders[i] and orders[minIndex]
		 Order temp = orders[i];
		 orders[i] = orders[minIndex];
		 orders[minIndex] = temp;
	 }
 }

 void OrderManager::merge(Order* orders, int left, int mid, int right) {
	 int n1 = mid - left + 1;
	 int n2 = right - mid;

	 // Create temporary arrays
	 Order* leftArray = new Order[n1];
	 Order* rightArray = new Order[n2];

	 // Copy data to temp arrays
	 for (int i = 0; i < n1; ++i) leftArray[i] = orders[left + i];
	 for (int j = 0; j < n2; ++j) rightArray[j] = orders[mid + 1 + j];

	 int i = 0, j = 0, k = left;

	 // Merge the temp arrays
	 while (i < n1 && j < n2) {
		 if (leftArray[i].orderPriority <= rightArray[j].orderPriority) {
			 orders[k] = leftArray[i];
			 ++i;
		 }
		 else {
			 orders[k] = rightArray[j];
			 ++j;
		 }
		 ++k;
	 }

	 // Copy remaining elements
	 while (i < n1) {
		 orders[k] = leftArray[i];
		 ++i;
		 ++k;
	 }
	 while (j < n2) {
		 orders[k] = rightArray[j];
		 ++j;
		 ++k;
	 }
	 // Free memory
	 delete[] leftArray;
	 delete[] rightArray;
 }
// Helper function to faciliate mergeSort
 void OrderManager::mergeSortUtil(Order* orders, int left, int right) {
	 if (left < right) {
		 int mid = left + (right - left) / 2;

		 mergeSortUtil(orders, left, mid);
		 mergeSortUtil(orders, mid + 1, right);

		 merge(orders, left, mid, right);
	 }
 }

 void OrderManager::mergeSort(Order* orders) {
	 mergeSortUtil(orders, 0, orderCount - 1);
 }

 int OrderManager::partition(Order* orders, int low, int high) {
	 int pivot = orders[high].orderPriority;
	 int i = low - 1;

	 for (int j = low; j < high; ++j) {
		 if (orders[j].orderPriority < pivot) {
			 ++i;
			 // Swap orders[i] and orders[j]
			 Order temp = orders[i];
			 orders[i] = orders[j];
			 orders[j] = temp;
		 }
	 }

	 // Swap orders[i + 1] and orders[high]
	 Order temp = orders[i + 1];
	 orders[i + 1] = orders[high];
	 orders[high] = temp;

	 return i + 1;
 }

 void OrderManager::quickSortUtil(Order* orders, int low, int high) {
	 if (low < high) {
		 int pi = partition(orders, low, high);

		 quickSortUtil(orders, low, pi - 1);
		 quickSortUtil(orders, pi + 1, high);
	 }
 }

 void OrderManager::quickSort(Order* orders) {
	 quickSortUtil(orders, 0, orderCount - 1);
 }



 void OrderManager::populateOrders() {
	 srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

	 const int MAX_LOCATIONS = 26;  // 'A' to 'Z' for locations
	 const int MIN_PRIORITY = 1;   // Minimum priority value
	 const int MAX_PRIORITY = 5;   // Maximum priority value

	 for (int i = 0; i < MAX_ORDERS && i < 10000; ++i) {
		 // Generate orderID: "ORD1", "ORD2", ...
		 orders[i].orderID = "ORD" + to_string(i + 1);

		 // Generate random priority (1 to 5)
		 orders[i].orderPriority = MIN_PRIORITY + rand() % (MAX_PRIORITY - MIN_PRIORITY + 1);

		 // Generate random destination: "Location A", "Location B", ...
		 char locationChar = 'A' + (rand() % MAX_LOCATIONS);  // Random letter 'A' to 'Z'
		 orders[i].orderDestination = "Location " + string(1, locationChar);
	 }

	 orderCount = MAX_ORDERS;  // Set the current order count to MAX_ORDERS
 }



