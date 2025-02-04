#include <iostream>

/*
A Deque is a double-ended queue. It is a data structure that allows insertion and deletion of elements from both the front and the back of the queue. We can think of a deque as a combination of a stack and a queue. It is also known as a double-ended queue. The deque is a dynamic array that can be resized and shrunk as needed and is a versatile data structure that can be used in many different applications.
*/
class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    // Time Complexity: O(1)
    void insertFront(int key) {
        if (isFull()) {
            std::cout << "Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front = front - 1;
        }

        arr[front] = key;
        size++;
    }

    // Time Complexity: O(1)
    void insertRear(int key) {
        if (isFull()) {
            std::cout << "Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = key;
        size++;
    }

    // Time Complexity: O(1)
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front = front + 1;
        }

        size--;
    }

    // Time Complexity: O(1)
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear = rear - 1;
        }

        size--;
    }

    // Time Complexity: O(1)
    int getFront() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return -1;
        }
        return arr[front];
    }

    // Time Complexity: O(1)
    int getRear() {
        if (isEmpty()) {
            std::cout << "Underflow\n";
            return -1;
        }
        return arr[rear];
    }
};