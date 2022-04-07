#include <bits/stdc++.h>
using namespace std;

// Video link -> https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23&ab_channel=takeUforward

class Solution
{
public:
	// Function to return a list of nodes visible from top view.
	// From L -> R in BT.

	// Approach -> similar to vertical view, we use a level order traversal and the vertical line technique.
	// Node, Level/Line. Move left -> line - 1, Move right -> line + 1.
	// Data structures -> vector<int> ans to store final ans (in ascending order)
	// Since we need in ascending order, map<int, int> to store node data and line (no duplicates)
	// queue<pair<data, line> q; for level order traversal.

	void topView(Node *root) 
	{
		vector<int> ans;
		if (root == nullptr)  // base condition
		{
			return ans;
		}
		map<int, int> mp;
		queue<pair<Node*, int>> q;
		q.push({root, 0}) // initially. (draw diagram and check in notebook)
		while (!q.empty()) 
		{
			auto element = q.front();
			q.pop();
			// assigning node's data and line number to the pair
			Node *node = element.first;
			int line = element.second;
			// mp[line] = node->data (for bottom view) (no need to find line in map)
			if (mp.find(line) == mp.end()) 
			{
				// put in map
				mp[line] = node->data;
			}
			if (node->left != nullptr)
			{
				// push left node in the queue. (level order)
				q.push({node->left, line - 1});
			}
			if (node->right != nullptr)
			{
				q.push({node->right, line + 1});
			}
		}

		// now place all elements of map in vector and return ans
		for (auto element : mp)
		{
			ans.push_back(element.second);
		}
		return ans;
	}
};