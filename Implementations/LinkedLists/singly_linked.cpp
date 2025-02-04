#include <iostream>

/*
Singly Linked Lists are a type of data structure that is made up of nodes that are created using self referential structures. Each node contains a value and a pointer to the next node in the list. Singly linked lists contain nodes which have a data part and an address part, i.e. Next, which points to the next node in the sequence of nodes. The next pointer of the last node will point to NULL. We can look into it as a dynamic array with the ability to resize itself.

Operations of singly linked lists are as follows:
    - Insertion: Consists of adding a new node at the beginning, end or after a node in the list.
    - Deletion: Consists of removing a node from the beginning, end or from the middle of the list.
    - Reversal: Consists of reversing the order of the nodes in the list.
*/
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Time Complexity: O(n)
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Time Complexity: O(1)
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Time Complexity: O(n)
    void insertAfter(int prevValue, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != prevValue) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Time Complexity: O(n)
    void deleteFromEnd() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = nullptr;
        delete toDelete;
    }

    // Time Complexity: O(1)
    void deleteFromBeginning() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Time Complexity: O(n)
    void deleteNode(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Time Complexity: O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~SinglyLinkedList() {
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};