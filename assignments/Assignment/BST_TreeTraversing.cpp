#include <iostream>

using namespace std;

template <class T>
class BinaryTree {
    private:
        class Node {
            public:
                T _data;
                Node* _left;
                Node* _right;

                Node(const T& value) : _data(value), _left(nullptr), _right(nullptr) {}
        };

        Node* _root;

        // Function to find the index of a value in an array
        int findIndex(T arr[], int start, int end, T value) {
            for (int i = start; i <= end; i++) {
                if (arr[i] == value) return i;
            }
            return -1; // Should never reach here if input is valid
        }

        // Helper function to construct the tree
        Node* buildTree(T preorder[], T inorder[], int& preIndex, int inStart, int inEnd) {
            if (inStart > inEnd) return nullptr;

            T rootValue = preorder[preIndex++];
            Node* root = new Node(rootValue);

            if (inStart == inEnd) return root; // Leaf node case

            int inIndex = findIndex(inorder, inStart, inEnd, rootValue);

            root->_left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
            root->_right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

            return root;
        }

        // Helper functions for traversals
        void preorder(Node* node) {
            if (!node) return;
            cout << node->_data << " ";
            preorder(node->_left);
            preorder(node->_right);
        }

        void inorder(Node* node) {
            if (!node) return;
            inorder(node->_left);
            cout << node->_data << " ";
            inorder(node->_right);
        }

        void postorder(Node* node) {
            if (!node) return;
            postorder(node->_left);
            postorder(node->_right);
            cout << node->_data << " ";
        }

    public:
        // Constructor using preorder and inorder sequences
        BinaryTree(T preorder[], T inorder[], int length) {
            int preIndex = 0;
            _root = buildTree(preorder, inorder, preIndex, 0, length - 1);
        }

        void printPreorder() {
            preorder(_root);
            cout << endl;
        }

        void printInorder() {
            inorder(_root);
            cout << endl;
        }

        void printPostorder() {
            postorder(_root);
            cout << endl;
        }
};

int main() {
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};
    int length = sizeof(preorder) / sizeof(preorder[0]);

    BinaryTree<char> tree(preorder, inorder, length);

    cout << "Preorder: ";
    tree.printPreorder();

    cout << "Inorder: ";
    tree.printInorder();

    cout << "Postorder: ";
    tree.printPostorder();

    return 0;
}
