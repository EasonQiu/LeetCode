#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)  return true;
            
        // slow move to middle, fast move to end
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast->next != NULL) {
            if (fast->next->next != NULL) {
                fast = fast->next->next;  slow = slow->next;
            }else {
                fast = fast->next;  slow = slow->next;
            }
        }
        // re-link the right part of list nodes
        ListNode *ptr1 = slow, *ptr2 = slow->next, *tmp;
        while (ptr2 != NULL) {
            tmp = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;  ptr2 = tmp;
        }
        slow->next->next = NULL;
        // check if list is palidrome
        ptr1 = head;  ptr2 = fast;
        while (ptr2 != NULL) {
            if (ptr1->val != ptr2->val) {
                return false;
            }else {
                ptr1 = ptr1->next;  ptr2 = ptr2->next;
            }
        }
        return true;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(2);
//    a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = NULL;
    a->next = b;  b->next = NULL;
    
    Solution s;
    std::cout << s.isPalindrome(a);
    
    return 0;
}