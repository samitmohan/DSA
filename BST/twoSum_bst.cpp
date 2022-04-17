#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

			 5
		   /   \
		  3     6
		 / \     \
		2   4     7

input : root = [5,4,6,2,4,null.7], k = 9.
output = true
*/

// Bruteforce
// Inorder traversal (LNR) -> sorted order. = 2 3 4 5 6 7. (Normal two pointer method, if i + j = sum , if less than i++ if more then j--
// TC -> O(N) + O(N) inorder traversal + two pointer.
// SC -> O(N) // to store inorder traversal
class Solution
{
private:
	vector<int> ans;

public:
	void inorder(TreeNode *root)
	{
		if (root == nullptr)
			return;
		inorder(root->left);
		ans.push_back(root->val);
		inorder(root->right);
	}

	bool findTarget(TreeNode *root, int k)
	{
		inorder(root);
		// two pointer approach
		int low = 0, high = ans.size() - 1;
		while (low < high)
		{
			if (ans[low] + ans[high] == k)
			{
				return true;
			}
			if (ans[low] + ans[high] < k)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return false; // if not found.
	}
};

// Optimised.
// Use a set to remember prevs elements of tree, traverse tree, if k - root->val found then we have two sum, return true. 
// Else insert value into set and keep traversing

class Solution
{
private:
	unordered_set<int> s;
public:
	bool findTarget(TreeNode *root, int k)
	{
		if (root == nullptr) return false;
		if (s.count(k - root->val))
		{
			return true;
		}
		// else
		s.insert(root->val);
		return findTarget(root->left, k) || findTarget(root->right, k);
	}
};