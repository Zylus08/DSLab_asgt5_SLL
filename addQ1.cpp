#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr; // No intersection
}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* intersect = new Node(8);
    intersect->next = new Node(10);

    Node* headA = new Node(3);
    headA->next = new Node(7);
    headA->next->next = intersect;

    Node* headB = new Node(99);
    headB->next = new Node(1);
    headB->next->next = intersect;

    Node* result = getIntersectionNode(headA, headB);
    if (result)
        cout << "Intersection at node with value: " << result->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
