// Given a binary tree, determine if it is height-balanced.

#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=nHMQ33LZ6oA&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner&ab_channel=CodeHelp-byBabbar
// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

// balanced BT = for every node, height(left) - height(right) <= 1

/*
 3
/ \
9  20
  /  \
  15  7
*/

// inp = root = [3, 9, 20, null, null, 15, 7]
// op = true

// naive solution (figure out left height, right height, find diff, compare with 1)

class Solution
{
private:
	// height function = pre-req
	int height(TreeNode *root)
	{
		// if empty tree, height = 0
		if (root == nullptr)
		{
			return 0;
		}
		// else return maximum of left node / right node + 1 (for including the root node)
		return max(height(root->left), height(root->right)) + 1;
	}

public:
	bool isBalanced(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		// answer from left and right
		bool left = isBalanced(root->left);
		bool right = isBalanced(root->right);
		// difference
		bool diff = abs(height(root->left) - height(root->right)) <= 1;

		// if all true -> answer found!
		if (left && right && diff)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

// TC -> O(N) (traversal) * O(N) (find left/right height) [worst case skew tree] = O(N^2)

// Convert N^2 -> N

// Reduce time to find height of both left and right tree, basically do it without using height function
// Use pair<bool, int> (true false, height) (first = is it balanced?, second = height)

class Solution
{
public:
	// function to check whether BT is balanced or not without using height function
	pair<bool, int> isBalancedFast(node *root)
	{
		if (root == nullptr)
		{
			pair<bool, int> p = make_pair(true, 0);
			return p;
		}

		pair<int, int> left = isBalancedFast(root->left);
		pair<int, int> right = isBalancedFast(root->right);
		// find if it's balanced from left and right
		bool leftAns = left.first;
		bool rightAns = right.first;
		// height = .second
		// difference
		bool diff = abs(left.second - right.second) <= 1;

		// answer (set height and bool val true false)
		pair<bool, int> ans;
		ans.second = max(left.second, right.second) + 1; // height
		if (leftAns && rightAns && diff)
		{
			ans.first = true;
		}
		else
		{
			ans.first = false;
		}
		return ans; // final answer with true/false and height!
	}

	bool isBalanced(node *root)
	{
		return isBalancedFast(root).first; // answer
	}
};
