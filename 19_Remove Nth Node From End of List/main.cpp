#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);   dummy->next = head;
        // find the (N+1)th node from End of list
        ListNode *slow = dummy, *fast = dummy;
        while (n-- >= 1){
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;  slow = slow->next;
        }
        // delete Nth node from End of list
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        // delete dummy node
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
    ListNode* e = new ListNode(5);
    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    
    Solution s;
    s.removeNthFromEnd(a,5);
    
    return 0;
}