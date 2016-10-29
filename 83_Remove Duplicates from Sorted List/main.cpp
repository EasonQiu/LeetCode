#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);  dummy->next = head;
        ListNode *iter = dummy, *valPos, *delPos;
        int val;
        while (iter->next != NULL) {
            valPos = iter->next;  val = valPos->val;
            while (valPos->next != NULL && valPos->next->val == val){
                delPos = valPos->next;
                valPos->next = delPos->next;
                delete delPos;
            }
            iter = iter->next;
        }
        head = dummy->next;
        delPos = dummy;  delete delPos;
        return head;
    }
};


int main() {
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(2);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    s.deleteDuplicates(a);
    
    return 0;
}