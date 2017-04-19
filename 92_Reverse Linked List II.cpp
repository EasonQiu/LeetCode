#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);  dummy->next = head;
        ListNode *left = dummy, *tmp1, *tmp2, *tmp3, *tail;
        // find the previous node of m(th) node
        for (int i = 1; i < m; ++i)  left = left->next;
        // relink the node between m(th) and n(th) nodes
        tail = left->next;
        tmp1 = left->next;  tmp2 = tmp1->next;
        for (int i = m; i < n; ++i) {
            tmp3 = tmp2->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;  tmp2 = tmp3;
        }
        left->next = tmp1;  tail->next = tmp2;
        // delete dummy node & return
        head = dummy->next;
        delete dummy;  dummy = nullptr;
        return head;
    }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
//    n1->next = n2;
//    n2->next = n3;  n3->next = n4;  n4->next = n5;
    n3->next = n5;
    
    Solution s;
    s.reverseBetween(n3, 1, 2);
    
    return 0;
}