// Given a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.
// Note: Do not modify the linked list.

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
  	if (!head || !head->next)  return NULL;
  	// find the node where two nodes meet
  	ListNode *slow = head;
  	ListNode *fast = head;
  	do {
  		if (!fast->next || !fast->next->next)  return NULL;
  		fast = fast->next->next;
  		slow = slow->next;
  	} while (slow != fast);
  	// find the starting node of circle
  	slow = head;
  	while (slow != fast) {
  		fast = fast->next;
  		slow = slow->next;
  	}
  	return slow;
  }
};

int main() {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;  n2->next = n3;  
  n3->next = n4;  n4->next = n5;
  n5->next = n2;
  
  Solution s;
  ListNode *head = s.detectCycle(n1);
  cout << head->val << endl;
  
  return 0;
}