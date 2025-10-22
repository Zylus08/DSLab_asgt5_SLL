#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
    Node(int c, int p) : coeff(c), power(p), next(nullptr) {}
};

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* dummy = new Node(0, 0);
    Node* tail = dummy;

    while (poly1 && poly2) {
        if (poly1->power == poly2->power) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                tail->next = new Node(sumCoeff, poly1->power);
                tail = tail->next;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->power > poly2->power) {
            tail->next = new Node(poly1->coeff, poly1->power);
            tail = tail->next;
            poly1 = poly1->next;
        } else {
            tail->next = new Node(poly2->coeff, poly2->power);
            tail = tail->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        tail->next = new Node(poly1->coeff, poly1->power);
        tail = tail->next;
        poly1 = poly1->next;
    }
    while (poly2) {
        tail->next = new Node(poly2->coeff, poly2->power);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return dummy->next;
}

void printPolynomial(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = new Node(5, 3);
    poly1->next = new Node(4, 2);
    poly1->next->next = new Node(2, 0);

    Node* poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPolynomial(result);

    return 0;
}
