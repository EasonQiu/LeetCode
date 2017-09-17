// Given a sorted linked list, delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

// 感想：每次试图获取node->next的时候一定要先确保node非NULL

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)  return head;
		ListNode *dummy = new ListNode(0);  dummy->next = head;
		ListNode *prev_tail = dummy, *curr = head, *next;
		int val;
		while (curr && curr->next) {
			val = curr->val;  next = curr->next;
			if (next->val == val) { // have duplicates
				while (curr && curr->val == val) {
					delete(curr);  curr = next;  
					if (curr) next = curr->next;
				}
				prev_tail->next = curr;
			} else { // no duplicates
				prev_tail = curr;
				curr = curr->next;
			}
		}
		return dummy->next;
	}
};

int main() {
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(1);
	// ListNode* c = new ListNode(2);
	// ListNode* d = new ListNode(4);
	// ListNode* e = new ListNode(5);
	a->next = b;  
	// b->next = c;  c->next = d;  d->next = e;
    
	Solution s;
	ListNode *head = s.deleteDuplicates(a);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
