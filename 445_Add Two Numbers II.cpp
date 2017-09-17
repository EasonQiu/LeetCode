// You are given two non-empty linked lists representing two non-negative integers. 
// The most significant digit comes first and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {  // beats 97.45%
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// corner cases
		if (!l1 && !l2)  return NULL;
		else if (l1 && !l2)  return l1;
		else if (!l1 && l2)  return l2;
		// count the length of two lists
		int size1 = 1, size2 = 1;
		ListNode *ptr1 = l1, *ptr2 = l2;
		while (ptr1->next) {
			ptr1 = ptr1->next;  ++size1;
		}
		while (ptr2->next) {
			ptr2 = ptr2->next;  ++size2;
		}
		// recursively add number
		int carry;
		if (size1 >= size2)  carry = helper(l1, size1, l2, size2);
		else carry = helper(l2, size2, l1, size1);
		ListNode *l3 = size1 >= size2 ? l1 : l2;
		// solve the carry case
		if (carry > 0) {
			ListNode *head = new ListNode(1);  head->next = l3;
			return head;
		}
		return l3;
	}

	int helper(ListNode *l1, int size1, ListNode *l2, int size2) {
		// base cases
		if (size1 == 0 || size2 == 0)  return 0;
		// regular cases
		if (size1 != size2) {
			l1->val += helper(l1->next, size1 - 1, l2, size2);
		} else {
			l1->val += l2->val + helper(l1->next, size1 - 1, l2->next, size2 - 1);
		}
		// return the carry
		if (l1->val >= 10) {
			l1->val = l1->val - 10;
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {
	ListNode* a = new ListNode(7);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(4);
	ListNode* d = new ListNode(3);
	a->next = b;  b->next = c;  c->next = d; 
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(6);
	ListNode* g = new ListNode(4);
	ListNode* h = new ListNode(9);
	e->next = f;  f->next = g;  g->next = h;
    
	Solution s;
	ListNode *head = s.addTwoNumbers(a, e);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
