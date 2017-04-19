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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)  return head;
        // find the node in the middle
        // slow points to (left + right) / 2 + 1 node
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
        	prev = slow;
        	slow = slow->next;  fast = fast->next->next;
        }
        prev->next = NULL;
        // sort two half lists
        ListNode *l1 = sortList(head);  
        ListNode *l2 = sortList(slow);
        // merge two half lists
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
    	ListNode *dummy = new ListNode(-1), *p = dummy;
    	while (l1 && l2) {
    		if (l1->val <= l2->val) {
    			p->next = l1;  l1 = l1->next;
    		} else {
    			p->next = l2;  l2 = l2->next;
    		}
    		p = p->next;
    	}
    	if (l1)  p->next = l1;
    	if (l2)  p->next = l2;
    	return dummy->next;
    }
};

int main() {
	ListNode *n1 = new ListNode(5), *n2 = new ListNode(2), *n3 = new ListNode(6), *n4 = new ListNode(1);
	n1->next = n2;  n2->next = n3;  n3->next = n4;

	Solution s;
	ListNode* head = s.sortList(n1);
	while (head) {
		cout << head->val << " ";  head = head->next;
	}

	return 0;
}