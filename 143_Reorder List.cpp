// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next)  return;
		ListNode *dummy = new ListNode(0);  dummy->next = head;
		// find the middle node
		ListNode *slow = head, *fast = head->next;
		while (fast->next) {
			slow = slow->next;
			fast = fast->next->next ? fast->next->next : fast->next;
		}
		// reverse the second half list
		ListNode *prev = NULL, *curr = slow->next, *next = curr;
		while (curr) {
			next = curr->next;  curr->next = prev;
			prev = curr;  curr = next;
		}
		slow->next = NULL;
		// insert the second half list into left part
		ListNode *left = head, *right = prev;
		while (right) {
			next = right->next;  right->next = left->next;  left->next = right;
			left = right->next;  right = next;
		}
		return;
	}
};

int main() {
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = b;  b->next = c;  c->next = d;  d->next = e;
    
	Solution s;
	s.reorderList(a);

	while (a) {
		cout << a->val << " ";
		a = a->next;
	}
	cout << endl;

	return 0;
}
