// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// 每次取node->next->next都要先检验node->next是否可能会null
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
  	if (!head)  return NULL;
  	RandomListNode *old = head, *copy;
  	// copy the old node immediately after itself
  	while (old) {
  		copy = new RandomListNode(old->label);
  		copy->next = old->next;  old->next = copy;
  		old = copy->next;
  	}
  	// set the random node
  	old = head;
  	while (old) {
  		copy = old->next;
  		if (old->random)  copy->random = old->random->next; // corner case
  		old = copy->next;
  	}
  	// restore the list
  	RandomListNode *head2 = head->next;
  	old = head;
  	while (old) {
  		copy = old->next;
  		old->next = copy->next;  
  		if (copy->next) copy->next = copy->next->next; // corner case
  		old = old->next;
  	}
  	return head2;
  }
};