#include <iostream>
#include <vector>
#include <algorithm>

/*
The B+ Tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. The B+ Tree is a variation of the B-Tree in which the data is stored in the leaf nodes. The internal nodes act as the index to the leaf nodes. The B+ Tree is widely used in database and file systems.

The B+ Tree is a multi-level index, where each node contains a set of keys and a set of pointers to the child nodes. The B+ Tree has the following properties:
    - All the keys in the node are sorted.
    - The keys in the internal nodes act as the index to the child nodes.
    - The keys in the leaf nodes are sorted and linked together.
    - The leaf nodes contain the actual data.
    - The leaf nodes are linked together to allow sequential access.
    - The B+ Tree is self-balancing, which means that the height of the tree is always logarithmic.
    - The B+ Tree is a balanced tree, which means that all the leaf nodes are at the same level.

The B+ Tree supports the following operations:
    - Search: Search for a key in the B+ Tree.
    - Insert: Insert a key into the B+ Tree.
    - Delete: Delete a key from the B+ Tree.

Time Complexity:
    - Search: O(log n)
    - Insert: O(log n)
    - Delete: O(log n)
*/

const int DEGREE = 3;

struct Node {
    bool isLeaf;
    std::vector<int> keys;
    std::vector<Node*> children;
    Node* next;

    Node(bool leaf) : isLeaf(leaf), next(nullptr) {}
};

class BPlusTree {
private:
    Node* root;

    void insertInternal(int key, Node* current, Node* child) {
        if (current->keys.size() < DEGREE - 1) {
            auto it = std::upper_bound(current->keys.begin(), current->keys.end(), key);
            current->keys.insert(it, key);

            current->children.insert(current->children.begin() + (it - current->keys.begin()), child);
        } else {
            Node* newInternal = new Node(false);
            std::vector<int> tempKeys = current->keys;
            std::vector<Node*> tempChildren = current->children;

            auto it = std::upper_bound(tempKeys.begin(), tempKeys.end(), key);
            tempKeys.insert(it, key);
            tempChildren.insert(tempChildren.begin() + (it - tempKeys.begin()), child);

            int midIndex = tempKeys.size() / 2;
            int midKey = tempKeys[midIndex];

            current->keys.assign(tempKeys.begin(), tempKeys.begin() + midIndex);
            current->children.assign(tempChildren.begin(), tempChildren.begin() + midIndex + 1);

            newInternal->keys.assign(tempKeys.begin() + midIndex + 1, tempKeys.end());
            newInternal->children.assign(tempChildren.begin() + midIndex + 1, tempChildren.end());

            if (current == root) {
                Node* newRoot = new Node(false);
                newRoot->keys.push_back(midKey);
                newRoot->children.push_back(current);
                newRoot->children.push_back(newInternal);
                root = newRoot;
            } else {
                insertInternal(midKey, findParent(root, current), newInternal);
            }
        }
    }

    Node* findParent(Node* current, Node* child) {
        if (current->isLeaf || current->children[0]->isLeaf) {
            return nullptr;
        }

        for (Node* c : current->children) {
            if (c == child) {
                return current;
            } else {
                Node* parent = findParent(c, child);
                if (parent) return parent;
            }
        }
        return nullptr;
    }

public:
    BPlusTree() : root(new Node(true)) {}

    void insert(int key) {
        Node* current = root;

        if (current->keys.size() == DEGREE - 1) {
            Node* newRoot = new Node(false);
            Node* newLeaf = new Node(true);

            newRoot->children.push_back(current);
            root = newRoot;

            insertInternal(key, newRoot, newLeaf);
        } else {
            while (!current->isLeaf) {
                auto it = std::upper_bound(current->keys.begin(), current->keys.end(), key);
                current = current->children[it - current->keys.begin()];
            }

            if (current->keys.size() < DEGREE - 1) {
                auto it = std::upper_bound(current->keys.begin(), current->keys.end(), key);
                current->keys.insert(it, key);
            } else {
                Node* newLeaf = new Node(true);
                std::vector<int> tempKeys = current->keys;

                auto it = std::upper_bound(tempKeys.begin(), tempKeys.end(), key);
                tempKeys.insert(it, key);

                int midIndex = tempKeys.size() / 2;

                current->keys.assign(tempKeys.begin(), tempKeys.begin() + midIndex);
                newLeaf->keys.assign(tempKeys.begin() + midIndex, tempKeys.end());

                newLeaf->next = current->next;
                current->next = newLeaf;

                if (current == root) {
                    Node* newRoot = new Node(false);
                    newRoot->keys.push_back(newLeaf->keys[0]);
                    newRoot->children.push_back(current);
                    newRoot->children.push_back(newLeaf);
                    root = newRoot;
                } else {
                    insertInternal(newLeaf->keys[0], findParent(root, current), newLeaf);
                }
            }
        }
    }

    bool search(int key) {
        Node* current = root;

        while (!current->isLeaf) {
            auto it = std::upper_bound(current->keys.begin(), current->keys.end(), key);
            current = current->children[it - current->keys.begin()];
        }

        return std::binary_search(current->keys.begin(), current->keys.end(), key);
    }

    void print() {
        Node* current = root;
        while (!current->isLeaf) {
            current = current->children[0];
        }

        while (current) {
            for (int key : current->keys) {
                std::cout << key << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    BPlusTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    tree.print();

    std::cout << "Search 6: " << (tree.search(6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 15: " << (tree.search(15) ? "Found" : "Not Found") << std::endl;

    return 0;
}
