/* 
A Segment Tree is a data structure used for storing information about intervals or segments.
It allows querying which segments contain a certain point efficiently, or performing range queries
(e.g., sum, minimum, maximum) and updates over an array in logarithmic time.
It is widely used in competitive programming and scenarios requiring efficient range queries and updates.

The implementation work as follows:
    - The tree is represented as an array, where each node stores information about a range of the array.
    - The root node represents the entire array, and each node has two children representing the left and right halves.
    - The tree is built recursively in a top-down manner, where each node stores the result of its children.
    - The tree is queried recursively in a bottom-up manner, where the result is calculated based on the children's results.
    - The tree is updated recursively in a top-down manner, where the result is updated based on the children's results.

Complexity:
    - Build: O(n)
    - Query: O(log n)
    - Update: O(log n)
*/
#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;
    segTree.update(1, 10);
    cout << "Sum of range [1, 3] after update: " << segTree.query(1, 3) << endl;

    return 0;
}