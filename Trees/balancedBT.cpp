// Given a binary tree, determine if it is height-balanced.

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

bool check(node)
{
	if node == nullptr;
		return true; // if empty (height = 0 < 1)

	left_height = find_height_left(node->left);
	right_height = find_height_right(node->right);

	if (abs(right_height - left_height) > 1)
	{
		return false;
	} 
	else // check for remaining nodes if above is true
	{
		bool left = check(node->left);
		bool right = check(node->right);
	}

	// if anyone from left right is false -> whole answer is false.

	if (!left || !right) 
	{
		return false;
	}

	return true; // otherwise
}

// TC -> O(N) (traversal) * O(N) (find left/right height) [worst case skew tree] = O(N^2)

// Convert N^2 -> N

// reduce time to find left and right half (line 27, 28) -> O(N) complexity.

// pre-req -> max height question
// how to find height of tree in O(N)? -> lh = check(node->left) rh = check(node->right), return max(lh, rh) + 1

int check(node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int lh = check(node->left);
	int rh = check(node->right);
	return max(lh, rh) + 1;
}

// Answer

class Solution
{
public:
	bool ans;
	int check(TreeNode* root)
	{
		if (root == nullptr) 
		{
			return 0;
		}
		int lh = check(root->left);
		int rh = check(root->right);

		// check condition for Balanced BT
		if (abs(lh - rh) > 1) 
		{
			ans = false;
		}
		// else if true, return height of tree
		return max(lh, rh) + 1;
	}

	bool isBalanced(TreeNode* root)
	{
		ans = true; // default
		int temp = check(root);
		return ans;
	}
};
