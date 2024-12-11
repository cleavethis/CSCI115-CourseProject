#include "OrderBST.h"

OrderBST::OrderBST() : root(nullptr) {}


void OrderBST::insert(string id, int priority, string destination) {
    insert(root, id, priority, destination);
}

void OrderBST::insert(Node*& node, string id, int priority, string destination) {
    if (!node) {
        node = new Node(id, priority, destination);
        return;
    }

    if (id < node->orderID) {
        insert(node->left, id, priority, destination);
    }
    else if (id > node->orderID) {
        insert(node->right, id, priority, destination);
    }
    else {
        cout << "Duplicate order ID (" << id << ") is not allowed.\n";
        return;
    }

    // Update height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Rebalance the tree
    node = rebalance(node, id);
}



void OrderBST::displayInOrder() const {
    inOrderTraversal(root);
}


void OrderBST::inOrderTraversal(Node* node) const {
    // Traverse tree such that lower values are displayed first, displaying tree in ascending order
    if (node) {
        inOrderTraversal(node->left);
        cout << "Order ID: " << node->orderID
            << ", Priority: " << node->orderPriority
            << ", Destination: " << node->orderDestination << endl;
        inOrderTraversal(node->right);
    }
}


OrderBST::Node* OrderBST::search(const string& id) const {
    return search(root, id);
}


OrderBST::Node* OrderBST::search(Node* node, const string& id) const {
    // If no node exists, or order found, return
    if (!node || node->orderID == id) {
        return node;
    }
    // Recrusively search left subtree if id is less than current id
    if (id < node->orderID) {
        return search(node->left, id);
    }
    // Otherwise search right subtree if id is greater or equal
    else {
        return search(node->right, id);
    }
}


void OrderBST::deleteNode(const string& id) {
    root = deleteNode(root, id);
}
OrderBST::Node* OrderBST::deleteNode(Node* node, const string& id) {
    // Empty tree, so return 
    if (!node) return nullptr;

    // Search for the node to delete
    if (id < node->orderID) {
        node->left = deleteNode(node->left, id);
    }
    else if (id > node->orderID) {
        node->right = deleteNode(node->right, id);
    }
    else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor
        Node* temp = findMin(node->right);

        // Copy the inorder successor's data to this node
        node->orderID = temp->orderID;
        node->orderPriority = temp->orderPriority;
        node->orderDestination = temp->orderDestination;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->orderID);
    }

    // Update height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Get balance factor
    int balance = getBalanceFactor(node);

    // Rebalance the tree if necessary

    // Left-heavy
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }

    // Left-right case
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-heavy
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }

    // Right-left case
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotations needed
    return node;
}

// Used in delete function to find successor 
OrderBST::Node* OrderBST::findMin(Node* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

int OrderBST::getHeight(Node* node) const {
    return node ? node->height : 0;
}

int OrderBST::getBalanceFactor(Node* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

OrderBST::Node* OrderBST::leftRotate(Node* z) {
    // Assign right child
    Node* y = z->right;
    // Assign left subtree 
    Node* T2 = y->left;

    // Perform rotation
    y->left = z;
    z->right = T2;

    // Update heights
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; 
}

OrderBST::Node* OrderBST::rightRotate(Node* z) {
    // Assign left child
    Node* y = z->left;
    // Assign right subtree
    Node* T3 = y->right;

    // Perform rotation
    y->right = z;
    z->left = T3;

    // Update heights
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

OrderBST::Node* OrderBST::rebalance(Node* node, const string& id) {
    int balanceFactor = getBalanceFactor(node);

    // Left-heavy
    if (balanceFactor > 1 && id < node->left->orderID) {
        return rightRotate(node);
    }

    // Right-heavy
    if (balanceFactor < -1 && id > node->right->orderID) {
        return leftRotate(node);
    }

    // Left-right case
    if (balanceFactor > 1 && id > node->left->orderID) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-left case
    if (balanceFactor < -1 && id < node->right->orderID) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotations needed
    return node; 
}

