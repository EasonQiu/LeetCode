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
        // find the mid node
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;  
            slow = slow->next;
        }
        fast = slow->next;  slow->next = NULL;
        // sort half lists seperately
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        // merge two sorted lists
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;  l1 = l1->next;  tail = tail->next;
            } else {
                tail->next = l2;  l2 = l2->next;  tail = tail->next;
            }
        }
        if (l1)  tail->next = l1;
        if (l2)  tail->next = l2;
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