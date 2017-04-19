#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        ListNode *iter1 = l1, *iter2 = l2;
        while (iter1 != NULL && iter2 != NULL){
            if (iter1->val <= iter2->val){
                tail->next = iter1;
                iter1 = iter1->next;  tail = tail->next;
            }else {
                tail->next = iter2;
                iter2 = iter2->next;  tail = tail->next;
            }
        }
        if (iter1 != NULL)  tail->next = iter1;
        if (iter2 != NULL)  tail->next = iter2;
        
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(5);
    ListNode* d = new ListNode(7);
    ListNode* e = new ListNode(9);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    ListNode* a2 = new ListNode(2);
    ListNode* b2 = new ListNode(6);
    ListNode* c2 = new ListNode(8);
    ListNode* d2 = new ListNode(12);
    ListNode* e2 = new ListNode(16);
    a2->next = b2;  b2->next = c2;  c2->next = d2;  d2->next = e2;  e2->next = NULL;
    
    Solution s;
    s.mergeTwoLists(a,a2);
    
    return 0;
}