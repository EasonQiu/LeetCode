#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }else if (head->next == NULL) {
            return head;
        }else if (head->next->next == NULL) {
            return head;
        }
    
        ListNode* oddhead  = head;
        ListNode* evenhead = head->next;
        ListNode* odditr  = head;
        ListNode* evenitr = head->next;
        ListNode* tmpptr  = head->next->next;
        
        while (tmpptr != NULL){
            odditr->next = tmpptr;  odditr = odditr->next;
            
            if (tmpptr->next == NULL) {
                odditr->next = evenhead;  evenitr->next = NULL;
                break;
            }else {
                tmpptr = tmpptr->next;
                evenitr->next = tmpptr;  evenitr = evenitr->next;
            }
            
            if (tmpptr->next == NULL) {
                odditr->next = evenhead;  evenitr->next = NULL;
                break;
            }else {
                tmpptr = tmpptr->next;
            }
        }
        
//        tmpptr = head;
//        while (tmpptr != NULL) {
//            std::cout << tmpptr->val << " ";
//            tmpptr = tmpptr->next;
//        }
        
        return oddhead;
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
    s.oddEvenList(a);
    
    return 0;
}