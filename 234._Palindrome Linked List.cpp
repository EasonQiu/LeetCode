// Given a singly linked list, determine if it is a palindrome.

// 解法：找中间节点，然后reverse后半部分链表再比较
// 感想：会写找中间节点，逆转链表的算法。注意中间节点index=(size/2)，注意各种指针最终状态。
// 中间节点算法slow_itr停在中间节点，fast_itr停在最后一个节点
// 逆转链表算法pre_itr停在最后一个节点，cur_itr和next_itr停在NULL

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* curr, ListNode* prev) {
    if (!curr)  return prev;
    ListNode* next = curr->next;
    curr->next = prev;
    return reverse(next, curr);
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (!head || !head->next)  return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head2 = reverse(head2, NULL);
        while (head2) {
            if (head->val != head2->val)  return false;
            head2 = head2->next;
            head = head->next;
        }
        return true;
    }
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
  	// corner cases
  	if (!head || !head->next)  return true;
  	// find the mid node
  	ListNode *slow_itr = head, *fast_itr = head->next;
  	while (fast_itr->next) {
  		slow_itr = slow_itr->next;
  		if (fast_itr->next && fast_itr->next->next) {
  			fast_itr = fast_itr->next->next;
  		} else {
  			fast_itr = fast_itr->next;
  		}
  	}
  	// reverse the right half
  	ListNode *pre_itr = NULL, *cur_itr = slow_itr->next, *next_itr = cur_itr;
  	while (cur_itr) {
  		next_itr = cur_itr->next;
  		cur_itr->next = pre_itr;  
  		pre_itr = cur_itr;
  		cur_itr = next_itr;
  	}
  	slow_itr->next = NULL;
  	// compare two sub strings
  	bool is_palindrome = true;
  	ListNode *left_itr = head, *right_itr = fast_itr;
  	while (right_itr) {
  		if (left_itr->val == right_itr->val) {
  			left_itr = left_itr->next;
  			right_itr = right_itr->next;
  		} else {
  			is_palindrome = false;
  			break;
  		}
  	}
  	// final result
  	return is_palindrome;
  }
};

int main() {
	ListNode *n1 = new ListNode(5);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(5);
	n1->next = n2;  n2->next = n3;  n3->next = n4;  n4->next = n5;

	Solution sol;
	cout << sol.isPalindrome(n1) << endl;

	return 0;
}