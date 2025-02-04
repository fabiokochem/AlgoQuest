#include <iostream>

/*
A Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’, because it works like a buffer, where the data can be written and read simultaneously. The main advantage of a circular queue over a simple queue is better memory utilization. If the last position is full and the first position is empty, we can insert an element in the first position. This action is not possible in a simple queue. In a simple queue, once an element is dequeued from the front, the space it occupied is wasted.
*/
class CircularQueue {
private:
    int *queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    // Time Complexity: O(1)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    // Time Complexity: O(1)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Time Complexity: O(1)
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    // Time Complexity: O(1)
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return queue[rear];
    }
};