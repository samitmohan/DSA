//  Problem Link -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (p->val < q->val)
		{
			return solve(root, p, q);
		}
		else
		{
			return solve(root, q, p);
		}
	}

	TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		while (root != nullptr) // keep traversing
		{
			if (p->val < root->val && q->val < root->val)
			{
				// both lie on the left side then no need to check in the right
				root = root->left;
			}
			else if (p->val > root->val && q->val > root->val)
			{
				// both lie on the right side then no need to check in the left
				root = root->right;
			}
			else
			{
				break; // answer found. (both have a common ancestor which is lowest.)
			}
		}
		return root;
	}
};
