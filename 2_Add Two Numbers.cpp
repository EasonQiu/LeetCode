#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)  return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        int carry = 0;
        while (node1 && node2) {
            curr->next = new ListNode(node1->val + node2->val + carry);
            node1 = node1->next;
            node2 = node2->next;
            curr = curr->next;
            carry = curr->val / 10;
            curr->val = curr->val % 10;
        }
        if (node1)  curr->next = node1;
        if (node2)  curr->next = node2;
        while (carry == 1 && curr->next) {
            curr = curr->next;
            curr->val += 1;
            carry = curr->val / 10;
            curr->val = curr->val % 10;
        }
        if (carry == 1)  curr->next = new ListNode(1);
        return  dummy->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return nullptr;
        ListNode *sum = new ListNode(-1);
        ListNode *itr1 = l1, *itr2 = l2, *itr = sum;
        int carry = 0;
        while (itr1 && itr2) {
            itr->next = new ListNode(itr1->val + itr2->val + carry);
            itr = itr->next;  itr1 = itr1->next;  itr2 = itr2->next;
            carry = itr->val / 10;  itr->val = itr->val % 10;
        }
        while (itr1) {
            itr->next = new ListNode(itr1->val + carry);
            itr = itr->next;  itr1 = itr1->next;
            carry = itr->val / 10;  itr->val = itr->val % 10;
        }
        while (itr2) {
            itr->next = new ListNode(itr2->val + carry);
            itr = itr->next;  itr2 = itr2->next;
            carry = itr->val / 10;  itr->val = itr->val % 10;
        }
        if (carry > 0)  itr->next = new ListNode(carry);
        itr1 = sum;  sum = sum->next;
        delete itr1;
        return sum;
    }
};

int main() {
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(3);
    ListNode *m1 = new ListNode(5);
    ListNode *m2 = new ListNode(6);
    ListNode *m3 = new ListNode(4);
    ListNode *m4 = new ListNode(1);
    n1->next = n2;  n2->next = n3;
    m1->next = m2;  m2->next = m3;  m3->next = m4;
    
    Solution s;
    ListNode *answer = s.addTwoNumbers(n1, m1);
    
    return 0;
}