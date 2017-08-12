/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
Tags: Linked List
Similar Problems: (H) Reverse Nodes in k-Group
*/
#include "I_Struct.h"
class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (NULL == head)
		{
			return NULL;
		}
		ListNode *pFir = head;
		ListNode *pSec = head->next;

		while (pFir != NULL && pSec != NULL)
		{
			int t = pFir->val;
			pFir->val = pSec->val;
			pSec->val = t;

			pFir = pSec->next;
			if (pFir != NULL)
			{
				pSec = pFir->next;
			}
			else
			{
				pSec = NULL;
			}
		}
		return head;
	}
};