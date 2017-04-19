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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head, *p, *prev;
        while (cur) {
        	for (p = dummy; p->next != cur; p = p->next) {
        		if (p->next->val >= cur->val)  break;
        	}
        	if (p->next == cur) { // cur should put at last
        		cur = cur->next;
        	} else { // cur should insert in the previous list
        		for (prev = p; prev->next != cur; prev = prev->next) {}
        		prev->next = cur->next;
        		cur->next = p->next;  p->next = cur;
        		cur = prev->next;
        	}
        }
        return dummy->next;
    }
};

int main() {
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(5);
    ListNode* e = new ListNode(1);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    ListNode* head = s.insertionSortList(a);

    while (head) {
    	cout << head->val << " ";
    	head = head->next;
    }
    
    return 0;
}