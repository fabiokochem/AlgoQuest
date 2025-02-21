#include <iostream>

using std::cout;
using std::endl;

/*  
    I decided to talk about traversals in a separate file because they are the most important part of a binary tree, in my opinion. Traversals are the way we can access the data in the tree. There are three types of traversals: Inorder, Preorder, and Postorder. The description of each one is as follows:
        - Inorder: In this traversal, we first visit the left child, then the root, and finally the right child.
        - Preorder: In this traversal, we first visit the root, then the left child, and finally the right child.
        - Postorder: In this traversal, we first visit the left child, then the right child, and finally the root.

    Time Complexity of traversals: O(n)
*/
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}