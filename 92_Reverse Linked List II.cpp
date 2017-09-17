// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// return 1->4->3->2->5->NULL.

// 解法：找第m个节点之前的那个节点，然后reverse中间部分，最后链接一下


#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || !head->next)  return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    // find the previous node of m(th) node
    ListNode *left = dummy;
    for (unsigned int i = 1; i < m; ++i) {
      left = left->next;
    }
    // reverse nodes from m to n
    ListNode *mid_tail = left->next;
    ListNode *pre = NULL, *cur = left->next, *next = left->next;
    for (unsigned int i = m; i <= n; ++i) {
      next = cur->next;
      cur->next = pre;
      pre = cur;  cur = next;
    }
    // relink other parts
    left->next = pre;  mid_tail->next = cur;
    // final result
    return dummy->next;
  }
};

int main() {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;
  n2->next = n3;  n3->next = n4;  n4->next = n5;
  
  Solution s;
  ListNode *head = s.reverseBetween(n1, 2, 4);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  
  return 0;
}