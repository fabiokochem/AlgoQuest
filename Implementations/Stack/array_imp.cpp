#include <iostream>

/*
The array implementation for LIFO stack is a simple and efficient way to implement a stack. In this implementation, we will create a Stack class that uses an array to store the elements of the stack. We will keep track of the top of the stack using an index variable. It will work very similar to the linked list implementation, but instead of using a linked list, we will use an array to store the elements.
*/
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Time complexity: O(1)
    void push(int x) {
        if (isFull()) {
            std::cout << "Stack is empty, cannot pop." << std::endl;
            return;
        }
        arr[++top] = x;
    }

    // Time complexity: O(1)
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty, cannot pop." << std::endl;
            return -1;
        }
        return arr[top--];
    }

    // Time complexity: O(1)
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            exit(EXIT_FAILURE);
        }
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};