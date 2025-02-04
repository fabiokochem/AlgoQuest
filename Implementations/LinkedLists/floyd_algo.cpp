#include <iostream>

/*
The Floyd's Cycle Detection Algorithm is a pointer algorithm that uses only two pointers, which move through the sequence at different speeds. It is used to detect a cycle in a linked list. The algorithm is also known as the "Tortoise and the Hare" algorithm, alluding to Aesop's fable of The Tortoise and the Hare. The algorithm is named after Robert W. Floyd, who is credited with its invention.

The steps of the algorithm are as follows:
    - Initialize two pointers, slow and fast, to the head of the linked list.
    - Move the slow pointer one step and the fast pointer two steps.
    - If the slow pointer and the fast pointer meet at some point, there is a cycle in the linked list.
    - If the fast pointer reaches the end of the linked list, there is no cycle.

Time Complexity: O(n)
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    if (hasCycle(head)) {
        std::cout << "Cycle detected." << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}