#include <bits/stdc++.h>
using namesapce std;

// Problem link -> https://leetcode.com/problems/delete-node-in-a-bst/
/*
---Documentation---

deleting node with 0 children -> simply delete and replace by null

delete node with 1 child :
	left child -> create temp node to store left child and point it to next to next
	basically root->left = root->left->left
	delete root and return temp

	right child -> same procedure.
delete node with 2 children :
	find max in left subtree -> same as below
	find min in right subtree -> replace root with min node of right sub tree and then delete the min node (which contains root value)

*/

class Solution
{
public:
	int find_min_from_right(TreeNode *root)
	{
		while (root->left != nullptr)
		{
			root = root->left;
		}
		return root->val;
	}

	TreeNode *deleteNode(TreeNode *root, int key)
	{
		// base case.
		if (root == nullptr)
			return root;

		if (key < root->val)
		{
			// look in left half
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->val)
		{
			// look in right half
			root->right = deleteNode(root->right, key);
		}

		else
		{
			// root->val = key (found)
			// cases -> 0 children, 1 child (left/right), 2 children.

			// 0 children
			if (root->left == nullptr && root->right == nullptr)
			{
				delete (root);
				return nullptr;
			}

			// 1 child (L/R condition)
			// L
			if (root->left != nullptr && root->right == nullptr)
			{
				TreeNode *temp = root->left; // store (root->left->left)
				delete (root);
				return temp;
			}
			// R
			if (root->right != nullptr && root->left == nullptr)
			{
				TreeNode *temp = root->right;
				delete (root);
				return temp;
			}

			// 2 children
			if (root->left != nullptr && root->right != nullptr)
			{
				// Find either max of left ST or min of right ST.
				root->val = find_min_from_right(root->right);	  // find min
				root->right = deleteNode(root->right, root->val); // replace and delete
				return root;
			}
		}
		return root;
	}
};