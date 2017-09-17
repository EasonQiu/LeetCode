// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// custom priority queue
// 如果想把lhs放在heap后面，就return true
class comparator {
 public:
  bool operator() (const ListNode *lhs, const ListNode *rhs) {
    return lhs->val > rhs->val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty())  return NULL;
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    // input the first element in each list
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i])  pq.push(lists[i]);
    }
    // get nodes from priority queue
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy, *top;
    while (!pq.empty()) {
      top = pq.top();  pq.pop();
      curr->next = top;  curr = curr->next;
      if (top->next)  pq.push(top->next);
    }
    // final result
    return dummy->next;
  }
};

// merge two lists, O(nlog(k))
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty())  return NULL;
    int k = lists.size();
    while (k > 1) {
        int mid = (k - 1) / 2;
        for (int i = 0; i <= mid; ++i) {
            lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
        }
        k = mid + 1;
    }
    return lists[0];
  }

  ListNode* mergeTwoLists(ListNode *head1, ListNode *head2) {
    if (head1 == head2)  return head1;
    ListNode *dummy = new ListNode(0);
    ListNode *node1 = head1, *node2 = head2, *curr = dummy;
    while (node1 && node2) {
        if (node1->val <= node2->val) {
            curr->next = node1;
            node1 = node1->next;  curr = curr->next;
        } else {
            curr->next = node2;
            node2 = node2->next;  curr = curr->next;
        }
    }
    if (node1)  curr->next = node1;  
    if (node2)  curr->next = node2;
    return dummy->next;
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