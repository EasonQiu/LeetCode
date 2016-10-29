#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);  dummy->next = head;
        ListNode *iter = dummy, *tmp, *delPos;
        while (iter->next != NULL) {
            if (iter->next->val == val) {
                // Don't need to move iter at last here.
                tmp = iter->next->next;
                delPos = iter->next;  delete delPos;
                iter->next = tmp;
            }else {
                iter = iter->next;
            }
        }
        head = dummy->next;
        delPos = dummy;  delete delPos;
        return head;
    }
};


int main() {
    ListNode* a = new ListNode(6);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(5);
    ListNode* e = new ListNode(6);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    s.removeElements(a,6);
    
    return 0;
}