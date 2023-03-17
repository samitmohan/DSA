#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=FRP5l83XoZo&ab_channel=AlgorithmsMadeEasy
// Problem link -> https://leetcode.com/problems/house-robber-iii/submissions/

class Solution
{
public:
	int rob(TreeNode *root)
	{
		if (root == nullptr)
			return 0;

		int sum = root->val;
		// logic : skip the level and go to next level.

		// just for left
		if (root->left != nullptr)
		{
			// left exists. (add all the values starting from left and also add alt values)
			sum += rob(root->left->left);  // alt levels (vertical posns)
			sum += rob(root->left->right); // same levels alt horizontal posns
		}

		// just for right
		if (root->right != nullptr)
		{
			sum += rob(root->right->left);
			sum += rob(root->right->right);
		}

		// wrt this root, alt sum = rob(root->left) and rob(root->right)

		int next_sum = rob(root->left) + rob(root->right);
		// now max(sum, next_sum) will be our answer.
		int res = max(sum, next_sum);

		return res;
	}
};

// This works but time complexity -> shit. (We are calculating the sum again)
// In order to fix this -> use DP.
