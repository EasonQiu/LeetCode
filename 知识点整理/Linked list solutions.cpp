// Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        ListNode *iter1 = l1, *iter2 = l2;
        while (iter1 != NULL && iter2 != NULL){
            if (iter1->val <= iter2->val){
                tail->next = iter1;
                iter1 = iter1->next;  tail = tail->next;
            }else {
                tail->next = iter2;
                iter2 = iter2->next;  tail = tail->next;
            }
        }
        if (iter1 != NULL)  tail->next = iter1;
        if (iter2 != NULL)  tail->next = iter2;
        
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};

// Delete the (N+1)th node from End of list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;

        ListNode *dummy = new ListNode(0);   dummy->next = head;
        // find the (N+1)th node from End of list
        ListNode *slow = dummy, *fast = dummy;
        for (int i = 1; i <= n; i++){
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;  slow = slow->next;
        }
        // delete Nth node from End of list
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        // delete dummy node
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};

// reverse a linked list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next, *tmp;
        slow->next = NULL;
        while (fast != NULL) {
            tmp = fast->next;  fast->next = slow;
            slow = fast;  fast = tmp;
        }
        return slow;
    }
};

// remove linked list elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);  dummy->next = head;
        ListNode *iter = dummy, *tmp, *delPos;
        while (iter->next != NULL) {
            if (iter->next->val == val) {
                // Don't need to move iter at last here.
                tmp = iter->next->next;
                delPos = iter->next;  delete delPos;
                iter->next = tmp;
            }else {
                iter = iter->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// delete duplicates in a linked list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);  dummy->next = head;
        ListNode *iter = dummy, *valPos, *delPos;
        int val;
        while (iter->next != NULL) {
            valPos = iter->next;  val = valPos->val;
            while (valPos->next != NULL && valPos->next->val == val){
                delPos = valPos->next;
                valPos->next = delPos->next;
                delete delPos;
            }
            iter = iter->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// swap pairs in linked list
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0); dummy->next = head;
        ListNode *pair1, *pair2, *tmp, *tail = dummy;
        while (tail->next != NULL && tail->next->next != NULL) {
            pair1 = tail->next;  pair2 = tail->next->next;
            tmp = pair2->next;
            tail->next = pair2;  pair2->next = pair1;  pair1->next = tmp;
            tail = pair1;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// check whether has a circle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *mark = new ListNode(0);
        ListNode *iter1 = head, *tmp;
        while (iter1->next != NULL) {
            if (iter1->next == mark)  return true;
            tmp = iter1->next;
            iter1->next = mark;
            iter1 = tmp;
        }
        return false;
    }
};

//  get intersection node
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *iter1 = headA, *iter2 = headB;
        while (iter1 != NULL && iter2 != NULL) {
            if (iter1 == iter2) return iter1;
            if (iter1->next == NULL && iter2->next == NULL) return NULL;
            
            if (iter1->next == NULL)  iter1 = headB;
            else  iter1 = iter1->next;
            if (iter2->next == NULL)  iter2 = headA;
            else  iter2 = iter2->next;
        }
        return NULL;
    }
};

//  check if it is a palindrome
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

