#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr != nullptr) {
        Node* nextNode = curr->next; // store next node
        curr->next = prev;           // reverse the link
        prev = curr;                 // move prev forward
        curr = nextNode;             // move curr forward
    }
    
    return prev; 
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Original List: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed List: ";
    printList(head);
    
    return 0;
}
