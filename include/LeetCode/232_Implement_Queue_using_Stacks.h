/*
232. Implement Queue using Stacks
Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
Tags: Stack Design
Similar Problems: (E) Implement Stack using Queues
*/
#include "I_Struct.h"
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		tFir.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (tSec.empty())
		{
			if (tFir.empty())
			{
				return;
			}
			while (!tFir.empty())
			{
				tSec.push(tFir.top());
				tFir.pop();
			}
			tSec.pop();
			return;
		}
		tSec.pop();

	}

	// Get the front element.
	int peek(void) {
		if (tSec.empty())
		{
			if (tFir.empty())
			{
				return 0;
			}
			while (!tFir.empty())
			{
				tSec.push(tFir.top());
				tFir.pop();
			}
		}
		return tSec.top();

	}

	// Return whether the queue is empty.
	bool empty(void) {
		if (tSec.empty() && tFir.empty())
		{
			return true;
		} 
		return false;
	}
private:
	stack<int> tFir;
	stack<int> tSec;
};