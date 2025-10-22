#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;

    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head; 

    curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        head->next = reverseKGroup(next, k);

    return prev; 
}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 9; ++i) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
