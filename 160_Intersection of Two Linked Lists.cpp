#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *iter1 = headA, *iter2 = headB;
        while (iter1 != NULL && iter2 != NULL) {
            if (iter1 == iter2) return iter1;
            if (iter1->next == NULL && iter2->next == NULL) return NULL;
            
            if (iter1->next == NULL)  iter1 = headB;
            else  iter1 = iter1->next;
            if (iter2->next == NULL)  iter2 = headA;
            else  iter2 = iter2->next;
        }
        return NULL;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* a2 = new ListNode(6);
    ListNode* b2 = new ListNode(7);
    ListNode* c2 = new ListNode(8);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    a2->next = b2;  b2->next = c2;  c2->next = NULL;
    
    Solution s;
    ListNode *pos = s.getIntersectionNode(a,a2);
    
    return 0;
}