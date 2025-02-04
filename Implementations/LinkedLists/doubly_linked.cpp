#include <iostream>

/*
Double Linked Lists are a type of data structure that is made up of nodes that are created using self referential structures. Each node contains a value and a pointer to the next node in the list and a pointer to the previous node in the list. Double linked lists contain nodes which have a data part and two address parts, i.e. Next, which points to the next node in the sequence of nodes and Prev, which points to the previous node in the sequence of nodes. The next pointer of the last node will point to NULL. We can look into it as a dynamic array with the ability to resize itself.

Operations of double linked lists are as follows:
    - Insertion: Consists of adding a new node at the beginning, end or after a node in the list.
    - Deletion: Consists of removing a node from the beginning, end or from the middle of the list.
    - Reversal: Consists of reversing the order of the nodes in the list.
*/
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Time Complexity: O(1)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Time Complexity: O(1)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Time Complexity: O(n)
    void insertAfter(int prevValue, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != prevValue) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // Time Complexity: O(n)
    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Time Complexity: O(1)
    void deleteFromEnd() {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Time Complexity: O(n)
    void deleteNode(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Time Complexity: O(n)
    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};