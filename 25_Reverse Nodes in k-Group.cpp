// Given a linked list, reverse the nodes of a linked list k at a time and 
// return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes in the end should 
// remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next || k == 1)  return head;
		int size = 1;
		// count the size of list
		ListNode *crawl = head;
		while (crawl->next) {
			crawl = crawl->next;  ++size;
		}
		// reverse the list
		ListNode *dummy = new ListNode(0);  dummy->next = head;
		ListNode *prev_tail = dummy, *prev = NULL, *curr = head, *next, *curr_tail;
		for (int i = 0; i < size / k; ++i) {
			prev = NULL;  curr_tail = prev_tail->next;
			for (int j = 0; j < k; ++j) {
				next = curr->next;  curr->next = prev;
				prev = curr;  curr = next;
			}
			prev_tail->next = prev;  curr_tail->next = curr;
			prev_tail = curr_tail;
		}
		return dummy->next;
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
	ListNode *head = s.reverseKGroup(a, 2);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
