/*
206. Reverse Linked List
Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
Tags£º Linked List
Similar Problems£º (M) Reverse Linked List II (M) Binary Tree Upside Down (E) Palindrome Linked List
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "I_Struct.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head)
	{
		if (NULL == head)
		{
			return head;
		}
		ListNode *pt = NULL;
		while (NULL != head)
		{
			ListNode *pTemp = head;
			head = head->next;
			pTemp->next = pt;
			pt = pTemp;
		}
		return pt;        
    }
};