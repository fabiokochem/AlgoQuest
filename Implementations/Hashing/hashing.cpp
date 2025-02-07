#include <iostream>
#include <list>

using namespace std;

/*
A hash function is a function that maps keys to indices in a hash table.
To handle collisions, we use two approaches:
    - Chaining: Each index stores a linked list of elements that hash to the same index.
    - Open Addressing: Linear probing is used to find the next available slot.

Time Complexity:
    - insert(): O(1)
    - search(): O(1)
    - delete(): O(1) 
*/

// Hash Table using Chaining
class HashTableChaining {
    int bucketCount;
    list<int> *table;

public:
    HashTableChaining(int size);
    void insert(int key);
    bool search(int key);
    void remove(int key);
    int hashFunction(int key) { return key % bucketCount; }
    void display();
};

HashTableChaining::HashTableChaining(int size) {
    bucketCount = size;
    table = new list<int>[bucketCount];
}

void HashTableChaining::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

bool HashTableChaining::search(int key) {
    int index = hashFunction(key);
    for (int i : table[index]) {
        if (i == key)
            return true;
    }
    return false;
}

void HashTableChaining::remove(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
}

void HashTableChaining::display() {
    for (int i = 0; i < bucketCount; i++) {
        cout << i << ": ";
        for (int x : table[i])
            cout << x << " -> ";
        cout << "NULL\n";
    }
}

// Hash Table using Open Addressing (Linear Probing)
class HashTableOpenAddressing {
    int *table;
    int size;
    int capacity;
    
public:
    HashTableOpenAddressing(int cap);
    int hashFunction(int key) { return key % capacity; }
    void insert(int key);
    bool search(int key);
    void remove(int key);
    void display();
};

HashTableOpenAddressing::HashTableOpenAddressing(int cap) {
    capacity = cap;
    size = 0;
    table = new int[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = -1;
}

void HashTableOpenAddressing::insert(int key) {
    if (size == capacity) {
        cout << "Table Full!" << endl;
        return;
    }
    int index = hashFunction(key);
    while (table[index] != -1 && table[index] != -2) {
        index = (index + 1) % capacity;
    }
    table[index] = key;
    size++;
}

bool HashTableOpenAddressing::search(int key) {
    int index = hashFunction(key);
    int start = index;
    while (table[index] != -1) {
        if (table[index] == key)
            return true;
        index = (index + 1) % capacity;
        if (index == start)
            return false;
    }
    return false;
}

void HashTableOpenAddressing::remove(int key) {
    int index = hashFunction(key);
    int start = index;
    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -2;
            size--;
            return;
        }
        index = (index + 1) % capacity;
        if (index == start)
            return;
    }
}

void HashTableOpenAddressing::display() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != -1 && table[i] != -2)
            cout << i << ": " << table[i] << endl;
        else
            cout << i << ": NULL" << endl;
    }
}

int main() {
    HashTableChaining ht1(7);
    ht1.insert(10);
    ht1.insert(20);
    ht1.insert(15);
    ht1.insert(7);
    ht1.display();

    cout << "Searching 15: " << ht1.search(15) << endl;
    ht1.remove(15);
    cout << "Searching 15 after deletion: " << ht1.search(15) << endl;

    HashTableOpenAddressing ht2(7);
    ht2.insert(10);
    ht2.insert(20);
    ht2.insert(15);
    ht2.insert(7);
    ht2.display();

    cout << "Searching 15: " << ht2.search(15) << endl;
    ht2.remove(15);
    cout << "Searching 15 after deletion: " << ht2.search(15) << endl;
    
    return 0;
}
