// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next)  return head;
		ListNode *dummy = new ListNode(0);  dummy->next = head;
		int len = 0;
		// find the length of list, update the k
		ListNode *right_tail = dummy;
		while (right_tail->next) {
			right_tail = right_tail->next;
			++len;
		}
		k = k % len;
		// find the last k(th) node
		ListNode *left_tail = dummy;
		for (int i = 0; i < len - k; ++i)  left_tail = left_tail->next;
		// relink the list
		right_tail->next = dummy->next;
		dummy->next = left_tail->next;
		left_tail->next = NULL;
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
  n1->next = n2;  n2->next = n3;  
  n3->next = n4;  n4->next = n5;
  
  Solution s;
  ListNode *head = s.rotateRight(n1, 2);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  
  return 0;
}