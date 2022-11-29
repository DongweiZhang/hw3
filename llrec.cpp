#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot2(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    if (head->val <= pivot) {
        if (smaller == nullptr) {
            smaller = head;
        } else {
            smaller->next = head;
            smaller = smaller->next;
        }

        head = head->next;
        smaller->next = nullptr;
        llpivot(head, smaller->next, larger, pivot);
    } else {
        if (larger == nullptr) {
            larger = head;
        } else {
            larger->next = head;
            larger = larger->next;
        }

        head = head->next;
        larger->next = nullptr;
        llpivot(head, smaller, larger->next, pivot);
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    } else {
        smaller = nullptr;
        larger = nullptr;
        llpivot2(head, smaller, larger, pivot);
    }
}