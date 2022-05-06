#include <bits/stdc++.h>
using namespace std;

// problem link -> https://leetcode.com/problems/implement-stack-using-queues/

// Just use a queue where you "push to front" by pushing to back and then rotating the queue until the new element is at the front (i.e., size-1 times move the front element to the back).

class Stack 
{
	queue<int> q;
public:
	void push(int x) 
	{
		// add element to queue
		q.push(x);
		// rotate the queue (tail is the head now) -> becomes a stack
		for (int i = 1; i < q.size(); i++)  
		{
			q.push(q.front()); // add to head
			q.pop(); // remove element from tail
		}
	}

	// now it has become like a stack (LIFO), so use normal stack operations.

	void pop() 
	{
		q.pop();
	}

	int top() 
	{
		return q.front();
	}

	bool empty() 
	{
		return q.empty();
	}
};

// Another good solution -> https://leetcode.com/problems/implement-stack-using-queues/discuss/765739/C%2B%2B-oror-100.00(2-Queues)-oror-100.00(1-Queue)-oror-Easy-to-understand
