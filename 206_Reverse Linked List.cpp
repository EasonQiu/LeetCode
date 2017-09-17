#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // iterative
public:
  ListNode* reverseList(ListNode* head) {
    // corner cases
    if (!head || !head->next)  return head;
    // reverse linkedlist
    ListNode *pre = NULL, *cur = head, *next = head;
    while (cur) {
      next = cur->next;
      cur->next = pre;
      pre = cur;  cur = next;
    }
    // final result
    return pre;
  }
};

class Solution { // recursion
 public:
  ListNode* reverseList(ListNode* head) {
    return reverse(head, NULL);
  }

  ListNode* reverse(ListNode *curr, ListNode *prev) {
    if (!curr)  return prev;
    ListNode *next = curr->next;
    curr->next = prev;
    return reverse(next, curr);
  }
};

int main() {
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  ListNode* e = new ListNode(5);
  a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
  Solution sol;
  ListNode *head = sol.reverseList(a);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}