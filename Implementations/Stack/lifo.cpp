#include <iostream>

/*
LIFO is a concept in computer science that stands for Last In First Out. It is a data structure that allows you to add elements to the top of the stack and remove elements from the top of the stack. This is similar to a stack of plates where you can only add or remove plates from the top of the stack, or if you prefer to imagine a stack of books where you can only add or remove books from the top of the stack.

In this implementation, we will create a LIFO stack using a linked list. We will create a Node struct that will represent each element in the stack. The Node struct will have a data field to store the value of the element and a next field to point to the next element in the stack.
*/
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Time complexity: O(1)
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Time complexity: O(1) 
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty, cannot pop." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Time complexity: O(1)
    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1; 
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};