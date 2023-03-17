// Problem link -> https://leetcode.com/problems/kth-largest-element-in-a-stream/

/*
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
*/

// Every time you add a number, you have to show which is the kth largest
// Brute force -> sort array, remove smallest/largest element -> O(1) time in array.
// Adding element to array and shifting to keep it sorted -> O(N) time.

// Use heap / priority queue (max or min, using a max heap we'll get the kth largest number in our heap, using min heap we'll get smallest of the k numbers (which is the kth largest number))

// Just keep removing the smallest element from nums until nums.length == k.

// Use a priority queue to store elements in ascending fashion and keep removing elements (i = 0) until i == k.
// Once i reaches k, return the top element (answer)
// add function, add it to pq. 

// Use a min heap (smallest element) and keep the heap at size = k.
// Smallest element in the heap = Kth largest element.
// In the end smallest element in the heap = Answer.

// Add element to heap
// If size is disturbed (more than k elements) pop an element
// Return the minimum of the k largest numbers in our heap (the kth largest one)


class KthLargest
{
private:
	int size = 0;
	// min heap
	priority_queue<int, vector<int>, greater<int>> pq;

public:
	KthLargest(int k, vector<int> &nums)
	// this function converts array to min heap in O(N) time.
	{
		size = k; // 3 according to example case
		for (auto x : nums)
		{
			pq.push(x); // adds all numbers to heap
			if (pq.size() > size)
			{
				pq.pop(); // keep popping until pq.size() == 3 (then the top element of pq is our answer)
			}
		}
	}

	int add(int val)
	// this function adds new numbers to heap
	{
		pq.push(val); // insert new values into heap
		// do the same (keep popping until new pq.size() = k (size))
		if (pq.size() > size)
		{
			pq.pop();
		}
		// Top element of pq = answer for that val addition. Do this for every value you add (according to answer format in question)
		return pq.top();
	}
};

// Time Complexity
// Length of array = N
// Priority queue will add numbers to it in O(logN) and look up time -> O(1)
// Convert nums (array) into a heap of size k -> O(N) time
// Remove from heap until there are only k elements left, removing (N - k) elements -> O(logN (for 1 operation)) for N operations.
// O(N + Nlog(N)) -> O(NlogN)