#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0); dummy->next = head;
        ListNode *pair1, *pair2, *tmp, *tail = dummy;
        while (tail->next != NULL && tail->next->next != NULL) {
            pair1 = tail->next;  pair2 = tail->next->next;
            tmp = pair2->next;
            tail->next = pair2;  pair2->next = pair1;  pair1->next = tmp;
            tail = pair1;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(2);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    s.swapPairs(a);
    
    return 0;
}