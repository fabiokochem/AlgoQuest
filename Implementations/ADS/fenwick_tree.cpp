#include <vector>
#include <iostream>

/**
Fenwick Tree (also known as Binary Indexed Tree) is a data structure 
that provides efficient methods for cumulative frequency tables or 
prefix sums. 

The Fenwick Tree is implemented as a 1-indexed array where each 
index stores information about a range of elements. The range 
covered by each index is determined by the least significant bit 
(LSB) of the index. The tree is built in such a way that it can 
efficiently compute prefix sums and update individual elements 
without recalculating the entire array.

Common operations:
- Update: Increment or set the value of an element in the array.
- Query: Compute the prefix sum from the start of the array to a 
  given index.

Fenwick Tree is widely used in scenarios where frequent updates 
and prefix sum queries are required, such as in competitive 
programming, range queries, and dynamic cumulative frequency 
tables.

Time Complexity: O(log N) for both update and query operations.
 */

class FenwickTree {
private:
    std::vector<int> tree;
    int size;

    int LSB(int index) {
        return index & -index;
    }

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += LSB(index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= LSB(index);
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    FenwickTree fenwick(10);

    fenwick.update(1, 5);
    fenwick.update(3, 7);
    fenwick.update(4, 6);

    std::cout << "Prefix sum up to index 4: " << fenwick.query(4) << std::endl;

    std::cout << "Range sum [2, 4]: " << fenwick.rangeQuery(2, 4) << std::endl;

    return 0;
}