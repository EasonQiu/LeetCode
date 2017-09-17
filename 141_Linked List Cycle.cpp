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
        if (!head)  return false;
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            if (!fast->next || !fast->next->next)  return false;
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        return true;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)  return false;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)  return true;
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