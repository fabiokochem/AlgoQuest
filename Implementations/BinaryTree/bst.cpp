#include <iostream>

using std::cout;
using std::endl;

/*
    Binary Search Tree (BST's) follow the property that for each node, all nodes in the left subtree have a value less than the node and all nodes in the right subtree have a value greater than the node. This property allows for efficient searching, insertion, and deletion of nodes in the tree. So, since you know what is a Binary Tree, you need to understand the properties as follows to implement a BST:

    1. The left subtree of a node contains only nodes with keys less than the node's key.
    2. The right subtree of a node contains only nodes with keys greater than the node's key.   
    3. The left and right subtree each must also be a binary search tree.
    4. There must be no duplicate nodes.
    
    Time Complexity: O(h) where h is the height of the tree.
*/
struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    bool search(int key) {
        return searchRec(root, key);
    }

private:
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }

        return node;
    }

    bool searchRec(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }

        if (node->key == key) {
            return true;
        } else if (key < node->key) {
            return searchRec(node->left, key);
        } else {
            return searchRec(node->right, key);
        }
    }
};