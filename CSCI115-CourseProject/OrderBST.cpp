#include "OrderBST.h"

// Constructor adds provided data into tree
OrderBST::OrderBST() : root(nullptr) {
    insert("ORD1", 1, "Location A");
    insert("ORD2", 2, "Location B");
    insert("ORD3", 3, "Location C");
    insert("ORD4", 4, "Location D");
    insert("ORD5", 5, "Location E");
    insert("ORD6", 1, "Location F");
    insert("ORD7", 2, "Location G");
    insert("ORD8", 3, "Location H");
    insert("ORD9", 4, "Location I");
    insert("ORD10", 5, "Location J");
    insert("ORD11", 1, "Location K");
    insert("ORD12", 2, "Location L");
    insert("ORD13", 3, "Location M");
    insert("ORD14", 4, "Location N");
    insert("ORD15", 5, "Location O");
    insert("ORD16", 1, "Location P");
    insert("ORD17", 2, "Location Q");
    insert("ORD18", 3, "Location R");
    insert("ORD19", 4, "Location S");
    insert("ORD20", 5, "Location T");
    insert("ORD21", 1, "Location U");
    insert("ORD22", 2, "Location V");
    insert("ORD23", 3, "Location W");
    insert("ORD24", 4, "Location X");
    insert("ORD25", 5, "Location Y");
    insert("ORD26", 1, "Location Z");
    insert("ORD27", 2, "Location A");
    insert("ORD28", 3, "Location B");
    insert("ORD29", 4, "Location C");
    insert("ORD30", 5, "Location D");
    insert("ORD31", 1, "Location E");
    insert("ORD32", 2, "Location F");
    insert("ORD33", 3, "Location G");
    insert("ORD34", 4, "Location H");
    insert("ORD35", 5, "Location I");
    insert("ORD36", 1, "Location J");
    insert("ORD37", 2, "Location K");
    insert("ORD38", 3, "Location L");
    insert("ORD39", 4, "Location M");
    insert("ORD40", 5, "Location N");
    insert("ORD41", 1, "Location O");
    insert("ORD42", 2, "Location P");
    insert("ORD43", 3, "Location Q");
    insert("ORD44", 4, "Location R");
    insert("ORD45", 5, "Location S");
    insert("ORD46", 1, "Location T");
    insert("ORD47", 2, "Location U");
    insert("ORD48", 3, "Location V");
    insert("ORD49", 4, "Location W");
    insert("ORD50", 5, "Location X");
}


void OrderBST::insert(string id, int priority, string destination) {
    insert(root, id, priority, destination);
}

// Overloaded function helper

void OrderBST::insert(Node*& node, string id, int priority, string destination) {
    // If root doesnt exist, new node is root
    if (!node) {
        node = new Node(id, priority, destination);
        return;
    }
    // Insert left if new ID is less than root
    if (id < node->orderID) {
        insert(node->left, id, priority, destination);
    }
    // Insert right if new ID is greather than root
    else if (id > node->orderID) {
        insert(node->right, id, priority, destination);
    }
    // If neither case, output duplicate ID statement
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

