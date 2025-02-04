#include <iostream>

/*
Circular linked lists are a type of linked list where the last node points back to the first node. Similar to singly linked lists, circular linked lists are used to implement advanced data structures like stacks, queues, and graphs. They are also used in applications where data is constantly being added and removed from the list. So basically the only difference from singly linked list is that the last node points to the first node.

Operations of circular linked lists are as follows:
    - Insertion: Consists of adding a new node at the beginning, end or after a node in the list.
    - Deletion: Consists of removing a node from the beginning, end or from the middle of the list.
    - Traversal: Consists of visiting each node in the list exactly once.
*/
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Time Complexity: O(1)
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Time Complexity: O(1)
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Time Complexity: O(n)
    void insertAfter(int prevData, int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            do {
                if (temp->data == prevData) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            } while (temp != head);
            std::cout << "Node with value " << prevData << " not found." << std::endl;
        }
    }

    // Time Complexity: O(1)
    void deleteFromBeginning() {
        if (!head) return;

        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
            delete temp;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }
    
    // Time Complexity: O(n)
    void deleteFromEnd() {
        if (!head) return;

        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
            delete temp;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            temp = last;
            last = last->next;
        }
        temp->next = head;
        delete last;
    }

    // Time Complexity: O(1)
    void deleteNode(int key) {
        if (!head) return;

        Node *temp = head, *prev = nullptr;
        while (temp->data != key) {
            if (temp->next == head) {
                std::cout << "Node with value " << key << " not found." << std::endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        if (temp == head && temp->next == head) {
            head = nullptr;
            delete temp;
            return;
        }

        if (temp == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = temp->next;
            prev->next = head;
            delete temp;
        } else if (temp->next == head) {
            prev->next = head;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};