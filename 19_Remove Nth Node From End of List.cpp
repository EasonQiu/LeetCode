#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n == 0) {
      return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast->next) {
      if (fast->next->next) {
        fast = fast->next->next;
        slow = slow->next->next;
      } else {
        fast = fast->next;
        slow = slow->next;
      }
    }
    slow->next = slow->next->next;
    return dummy->next;
  }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    s.removeNthFromEnd(a,5);
    
    return 0;
}