/*
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
Tags: Linked List Two Pointers
Similar Problems: (M) Linked List Cycle II
*/
#include "I_Struct.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	bool hasCycle(ListNode *head) 
	{
		if (!head)
		{
			return false;
		}
		ListNode *pF = head;
		ListNode *pS = head;
		while (pS->next)
		{
			pS = pS->next;
			if (pS == pF)
			{
				return true;
			}
			pS = pS->next;
			if (!pS)
			{
				return false;
			}
			pF = pF->next;
		}
		return false;
	}
};