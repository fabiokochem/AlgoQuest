#include <iostream>
#include <vector>
#include <algorithm>

/*
The B Tree is a self-balancing search tree that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.
It is commonly used in databases and file systems due to its ability to store large amounts of data on disk and efficiently perform operations.

A B Tree of order m satisfies the following properties:
    - Every node has at most m children.
    - Every node (except root) has at least m/2 children.
    - All leaves are at the same level.
    - Every node contains k-1 keys where m/2 <= k <= m.
    - Keys in each node are sorted in ascending order.

The B Tree operations are as follows:
    - Search: Traverse the tree to find a key.
    - Insert: Add a key to the tree while maintaining the properties.
    - Delete: Remove a key from the tree while maintaining the properties.

Time Complexity:
    - Search: O(log n)
    - Insert: O(log n)
    - Delete: O(log n)
*/

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
    bool isLeaf;
    int t;

    BTreeNode(int t, bool isLeaf);
    void traverse();
    BTreeNode* search(int key);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void remove(int key);
    int findKey(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
};

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t);
    void traverse();
    BTreeNode* search(int key);
    void insert(int key);
    void remove(int key);
};

BTreeNode::BTreeNode(int t, bool isLeaf) : t(t), isLeaf(isLeaf) {}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf) {
            children[i]->traverse();
        }
        std::cout << keys[i] << " ";
    }
    if (!isLeaf) {
        children[i]->traverse();
    }
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i]) {
        i++;
    }
    if (i < keys.size() && keys[i] == key) {
        return this;
    }
    if (isLeaf) {
        return nullptr;
    }
    return children[i]->search(key);
}

BTree::BTree(int t) : t(t), root(nullptr) {}

void BTree::traverse() {
    if (root != nullptr) {
        root->traverse();
    }
}

BTreeNode* BTree::search(int key) {
    return (root == nullptr) ? nullptr : root->search(key);
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = (s->keys[0] < key) ? 1 : 0;
            s->children[i]->insertNonFull(key);
            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;
    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);
    z->keys.assign(y->keys.begin() + t, y->keys.end());
    y->keys.resize(t - 1);
    if (!y->isLeaf) {
        z->children.assign(y->children.begin() + t, y->children.end());
        y->children.resize(t);
    }
    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

void BTree::remove(int key) {
    if (!root) {
        std::cout << "The tree is empty\n";
        return;
    }
    root->remove(key);
    if (root->keys.empty()) {
        BTreeNode* tmp = root;
        root = (root->isLeaf) ? nullptr : root->children[0];
        delete tmp;
    }
}

void BTreeNode::remove(int key) {
    int idx = findKey(key);
    if (idx < keys.size() && keys[idx] == key) {
        if (isLeaf) {
            removeFromLeaf(idx);
        } else {
            removeFromNonLeaf(idx);
        }
    } else {
        if (isLeaf) {
            std::cout << "The key " << key << " is not in the tree\n";
            return;
        }
        bool flag = (idx == keys.size());
        if (children[idx]->keys.size() < t) {
            fill(idx);
        }
        if (flag && idx > keys.size()) {
            children[idx - 1]->remove(key);
        } else {
            children[idx]->remove(key);
        }
    }
}

int BTreeNode::findKey(int key) {
    int idx = 0;
    while (idx < keys.size() && keys[idx] < key) {
        idx++;
    }
    return idx;
}

void BTreeNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];
    if (children[idx]->keys.size() >= t) {
        int pred = getPredecessor(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->keys.size() >= t) {
        int succ = getSuccessor(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(key);
    }
}

int BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->isLeaf) {
        cur = cur->children.back();
    }
    return cur->keys.back();
}

int BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->isLeaf) {
        cur = cur->children.front();
    }
    return cur->keys.front();
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t) {
        borrowFromPrev(idx);
    } else if (idx != keys.size() && children[idx + 1]->keys.size() >= t) {
        borrowFromNext(idx);
    } else {
        if (idx != keys.size()) {
            merge(idx);
        } else {
            merge(idx - 1);
        }
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];
    child->keys.insert(child->keys.begin(), keys[idx - 1]);
    if (!child->isLeaf) {
        child->children.insert(child->children.begin(), sibling->children.back());
        sibling->children.pop_back();
    }
    keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);
    if (!child->isLeaf) {
        child->children.push_back(sibling->children.front());
        sibling->children.erase(sibling->children.begin());
    }
    keys[idx] = sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
    if (!child->isLeaf) {
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
    }
    keys.erase(keys.begin() + idx);
    children.erase(children.begin() + idx + 1);
    delete sibling;
}

int main() {
    BTree t(3); 
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Traversal of the constructed tree is:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(6);
    std::cout << "Traversal after removing 6:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(13);
    std::cout << "Traversal after removing 13:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(7);
    std::cout << "Traversal after removing 7:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(4);
    std::cout << "Traversal after removing 4:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(2);
    std::cout << "Traversal after removing 2:\n";
    t.traverse();
    std::cout << "\n";

    t.remove(16);
    std::cout << "Traversal after removing 16:\n";
    t.traverse();
    std::cout << "\n";

    return 0;
}
