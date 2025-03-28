#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int val) {
        value = val;
        left = right = parent = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }
    
    Node* search(Node* node, int x) {
        if (node == nullptr || node->value == x)
            return node;
        if (x < node->value)
            return search(node->left, x);
        return search(node->right, x);
    }
    
    void insert(int x) {
        Node* y = new Node(x);
        if (root == nullptr) {
            root = y;
            return;
        }
        Node* parent = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->value == x)
                return;
            parent = curr;
            if (x < curr->value)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (x < parent->value)
            parent->left = y;
        else
            parent->right = y;
        y->parent = parent;
    }
    
    Node* getMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
    
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }
    
    void deleteNode(int x) {
        Node* z = root;
        while (z != nullptr && z->value != x) {
            if (x < z->value)
                z = z->left;
            else
                z = z->right;
        }
        if (z == nullptr)
            return;
        if (z->left == nullptr)
            transplant(z, z->right);
        else if (z->right == nullptr)
            transplant(z, z->left);
        else {
            Node* y = getMin(z->right);
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
};

int main() {
    BinaryTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    cout << "Searching for 40: " << (bst.search(bst.root, 40) != nullptr ? "Found" : "Not Found") << endl;
    
    cout << "Deleting 50..." << endl;
    bst.deleteNode(50);
    
    cout << "Searching for 50: " << (bst.search(bst.root, 50) != nullptr ? "Found" : "Not Found") << endl;
    
    return 0;
}
