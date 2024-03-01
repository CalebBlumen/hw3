#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) {
    larger = nullptr;
    smaller = nullptr;
    return;
  }
  if (head->val > pivot) {
    Node* temp = head->next;
    larger = head;
    head = nullptr;
    llpivot(temp, smaller, larger->next, pivot);
  }
  else {
    Node* temp = head->next;
    smaller = head;
    head = nullptr;
    llpivot(temp, smaller->next, larger, pivot);
  }
}
