#include <iostream>

/*
A Priority Queue is a type of queue in which every element has a priority and the element with the highest priority is served before an element with lower priority. In this implementation, we will create a Priority Queue class that uses an array to store the elements of the queue. We will keep track of the front and rear of the queue using index variables. We will also keep track of the size of the queue and the capacity of the queue. We will use a priority value to determine the order in which elements are served.
*/
class PriorityQueue {
private:
    int* arr;
    int* priority;
    int size;
    int capacity;

public:
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        priority = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] arr;
        delete[] priority;
    }

    // Time complexity: O(n)
    void enqueue(int element, int prio) {
        if (size == capacity) {
            std::cout << "Queue is full\n";
            return;
        }
        int i;
        for (i = size - 1; i >= 0 && priority[i] < prio; i--) {
            arr[i + 1] = arr[i];
            priority[i + 1] = priority[i];
        }
        arr[i + 1] = element;
        priority[i + 1] = prio;
        size++;
    }

    // Time complexity: O(1)
    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty\n";
            return;
        }
        size--;
    }

    // Time complexity: O(1)
    int front() {
        if (size == 0) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};