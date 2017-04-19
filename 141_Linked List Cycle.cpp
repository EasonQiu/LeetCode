#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *mark = new ListNode(0);
        ListNode *iter1 = head, *tmp;
        while (iter1->next != NULL) {
            if (iter1->next == mark)  return true;
            tmp = iter1->next;
            iter1->next = mark;
            iter1 = tmp;
        }
        return false;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(2);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = a;
    
    Solution s;
    bool flag = s.hasCycle(a);
    std::cout << flag;
    
    return 0;
}