#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        int len = lists.size();
        while (len > 1) {
            int num = len / 2;
            len = (len + 1) / 2;
            for (int i = 0; i < num; ++i) {
                MergeList(lists[i], lists[i + len]);
            }
        }
        return lists[0];
    }
    
    void MergeList(ListNode* &head1, ListNode* &head2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1)  cur->next = head1;
        else if (head2)  cur->next = head2;
        
        cur = dummy;  head1 = dummy->next;
        delete cur;
    }
};

int main() {
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(4);
    ListNode *k1 = new ListNode(3);
    ListNode *k2 = new ListNode(5);
    ListNode *m1 = new ListNode(1);
    ListNode *m2 = new ListNode(4);
    ListNode *m3 = new ListNode(6);
    n1->next = n2;  k1->next = k2;
    m1->next = m2;  m2->next = m3;
    
    vector<ListNode*> lists = {n1, k1, m1};
    Solution s;
    ListNode *answer = s.mergeKLists(lists);
    
    return 0;
}