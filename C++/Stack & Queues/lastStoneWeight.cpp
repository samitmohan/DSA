#include <bits/stdc++.h>
using namespace std;
// Problem Link -> https://leetcode.com/problems/last-stone-weight/

/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

Pick 2 heaviest stones, smash them together.
if x == y, discard, if x < y or y > x, push abs(x-y) to the answer.

At the end, one stone remains, print that.

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Logic -> use a priority queue (max heap -> max of 2 numbers (biggest hint))
Since max elements will be at top, pop() the first 2 elements and compare them
if equal -> ignore, if difference is there : push(abs(x-y)) to the pq
at the end return pq.top() -> 1 element remains at most.
*/

int lastStoneWeight(vector<int> &stones)
{
	priority_queue pq(stones.begin(), stones.end()); // fill pq with elements
	while (pq.size() > 1)
	{
		int m1 = pq.top();
		pq.pop(); // remove element 1 (heaviest)
		int m2 = pq.top(); // next greatest number
		pq.pop();

		// if m1 == m2, just pop (we have already done that.)
		if (m1 != m2)
		{
			// return abs difference
			pq.push(abs(m1 - m2));
		}
	}

	// answer -> if 0 elements remain, return 0, if any element remains, return that element
	if (pq.empty())
	{
		return 0;
	}
	else
	{
		return pq.top();
	}
	// or return pq.empty() ? 0 : pq.top();
}

int main()
{
	vector<int> stones = {2, 7, 4, 1, 8, 1};
	cout << lastStoneWeight(stones); // 1 

}
