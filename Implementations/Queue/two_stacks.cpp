#include <iostream>

/*
A Queue Implementation using two stacks is a simple and efficient way to implement a queue. In this implementation, we will create a Queue class that uses two stacks to store the elements of the queue. We will keep track of the front and rear of the queue using two stacks. We will use one stack to store the elements in the order they are enqueued and another stack to store the elements in the order they are dequeued. When the dequeue operation is called, we will pop all the elements from the enqueue stack and push them onto the dequeue stack. This will reverse the order of the elements and allow us to dequeue the elements in the correct order.
*/
#include <stack>

class Queue {
private:
    std::stack<int> stack1, stack2;

    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    // Time complexity: O(n)
    void dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty\n";
                return;
            }
            transfer();
        }
        stack2.pop();
    }

    // Time complexity: O(n)
    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty\n";
                return -1;
            }
            transfer();
        }
        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};
