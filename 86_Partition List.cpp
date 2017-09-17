// Given a linked list and a value x, partition it such that all nodes less than 
// x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the 
// two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

// 解法：每次找到比x小的node，把它插入到前面小于x的链表的末尾
// 解法二：建两个链表，一个放<3，一个放>=3
// 感想：要考虑不同变量指向同一个节点，会影响操作。节点正好在之前链表的末尾，就不需要操作。


#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
  	if (!head || !head->next)  return head;
  	ListNode *dummy = new ListNode(0);  dummy->next = head;
  	ListNode *left_tail = dummy, *pre = dummy, *cur = head;
  	while (cur) {
  		if (cur->val < x) {
  			if (left_tail == pre) {
  				// don't need to insert the current node
  				cur = cur->next;  pre = pre->next;  left_tail = left_tail->next;
  				continue;
  			} else {
  				// need to insert the current node after the left_tail node
  				pre->next = cur->next;
  				cur->next = left_tail->next;  left_tail->next = cur;
  				left_tail = left_tail->next;
  				cur = pre->next;
  			}
  		} else {
  			cur = cur->next;  pre = pre->next;
  		}
  	}
  	// final result
  	return dummy->next;
  }
};

int main() {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(4);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(2);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(2);
  n1->next = n2;  n2->next = n3;  n3->next = n4;  
  n4->next = n5;  n5->next = n6;
  
  Solution s;
  ListNode *head = s.partition(n1, 3);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  
  return 0;
}