#include <iostream>

using std::cout;
using std::endl;

/*
    A Binary Tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. This structure is used in many applications, such as binary search trees, binary heaps, and Huffman coding. To implement this, we will create a class called Node, which will represent each node in the tree. The Node class will have three attributes: a value, a left child, and a right child. We will also create a class called BinaryTree, which will represent the entire tree. The BinaryTree class will have a root attribute, which will point to the root node of the tree. We will implement various methods in the BinaryTree class to perform operations on the tree, such as inserting a node, deleting a node, and traversing the tree in different orders.

    So the steps of the implementation are as follows:
        - Create a Node class with attributes value, left, and right.
        - Create a BinaryTree class with an attribute root.
        - Implement the insert method in the BinaryTree class to insert a node into the tree.
        - Implement the delete method in the BinaryTree class to delete a node from the tree.
        - Implement the inorder, preorder, and postorder traversal methods in the BinaryTree class to traverse the tree in different orders.
        
    Time Complexity:
        - Insertion: O(log n) in the average case, O(n) in the worst case.
        - Deletion: O(log n) in the average case, O(n) in the worst case.
        - Traversal: O(n) for all traversal methods.
*/
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else if (value > node->value) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    Node* deleteRec(Node* root, int key) {
        if (root == nullptr) return root;

        if (key < root->value) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->value) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteRec(root->right, temp->value);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->value << " ";
            inorderRec(root->right);
        }
    }

    void preorderRec(Node* root) {
        if (root != nullptr) {
            cout << root->value << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void postorderRec(Node* root) {
        if (root != nullptr) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->value << " ";
        }
    }
};