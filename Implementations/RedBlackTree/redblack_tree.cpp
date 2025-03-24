#include <iostream>
using namespace std;

/*
The Red-Black tree is a balanced binary search tree. It is a self-balancing binary search tree. It is a binary search tree with one extra bit of storage per node. The extra bit is used to represent the color of the node. If the color is red, then the extra bit is 1 and if the color is black, then the extra bit is 0. The rules for any Red-Black tree are as follows:
    - Every node is either red or black.
    - The root is black.
    - Every leaf (NIL) is black.
    - If a red node has children, then the children are black.
    - Every path from a node to its descendant NIL nodes contains the same number of black nodes.
    - Every node is either red or black.
    - The root is black.
    - Every leaf (NIL) is black.
    - If a red node has children, then the children are black.
    - Every path from a node to its descendant NIL nodes contains the same number of black nodes.

The insertion and deletion operations are performed in the same way as in a binary search tree. After performing these operations, the tree may become unbalanced. To balance the tree, we perform rotations and recoloring operations. The rotations are performed to maintain the balance of the tree. The recoloring operations are performed to maintain the properties of the Red-Black tree. The recoloring operations are performed in such a way that the properties of the Red-Black tree are maintained.

Time Complexity: 
    - Insertion: O(log n)
    - Deletion: O(log n)
    - Searching: O(log n)
    - Traversal: O(n)
*/

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&root, Node *&pt) {
        Node *pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != nullptr)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node *&root, Node *&pt) {
        Node *pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != nullptr)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == nullptr)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(Node *&root, Node *&pt) {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) &&
               (pt->parent->color == RED)) {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left) {
                Node *uncle_pt = grand_parent_pt->right;

                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            } else {
                Node *uncle_pt = grand_parent_pt->left;

                if ((uncle_pt != nullptr) && (uncle_pt->color == RED)) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

public:
    RedBlackTree() { root = nullptr; }

    void insert(const int &data) {
        Node *pt = new Node(data);

        root = BSTInsert(root, pt);

        fixViolation(root, pt);
    }

    Node *BSTInsert(Node *root, Node *pt) {
        if (root == nullptr)
            return pt;

        if (pt->data < root->data) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        } else if (pt->data > root->data) {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    void inorder() { inorderHelper(root); }

    void inorderHelper(Node *root) {
        if (root == nullptr)
            return;

        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();

    return 0;
}