#include <iostream>

/*
FIFO is a concept in computer science that stands for First In First Out. It is a data structure that allows you to add elements to the back of the queue and remove elements from the front of the queue. This is similar to a line of people waiting for a bus where the first person in line is the first person to get on the bus, or if you prefer to imagine a queue at a grocery store where the first person in line is the first person to check out.

In this implementation, we will create a FIFO queue using a linked list. We will create a Node struct that will represent each element in the queue. The Node struct will have a data field to store the value of the element and a next field to point to the next element in the queue.
*/
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    // Time complexity: O(1)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {
            front = rear;
        }
    }

    // Time complexity: O(1)
    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    }

    // Time complexity: O(1)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot peek.\n";
            return -1;
        }
        return front->data;
    }
};