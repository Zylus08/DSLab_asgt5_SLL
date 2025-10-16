#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int deleteOccurrences(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

int main() {
    Node* head = nullptr;

    int values[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : values)
        insert(head, val);

    int key = 1;
    cout << "Original Linked List: ";
    display(head);

    int count = deleteOccurrences(head, key);
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}