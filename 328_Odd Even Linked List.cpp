// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next)  return head;
    ListNode *head_even = head->next;
    ListNode *odd = head;
    ListNode *even = head->next;
    while (even && even->next) {
      odd->next = even->next;
      odd = even->next;
      even->next = odd->next;
      even = odd->next;
    }
    odd->next = head_even;
    return head;
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
    s.oddEvenList(a);
    
    return 0;
}