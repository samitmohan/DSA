// Problem link -> https://www.codingninjas.com/codestudio/problems/

/*
You are given two balanced binary search trees of integers having ‘N’ and ‘M’ nodes. You have to merge the two BSTs into a balanced binary search tree and return the root node to that balanced BST.
A binary search tree (BST) is a binary tree data structure with the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
*/

// i/p -> BST1, BST2
// step 1 -> store inorder traversals of both BST 1 and BST 2 in vectors
// step 2 -> merge the 2 sorted arrays (v3)
// step 3 -> convert inorder v3 to BST.

void inorder(TreeNode<int> *root, vector<int> &in)
{
	if (root == nullptr) return;
	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2)
{
	vector<int> ans(arr1.size() + arr2.size());
	// two pointer method
	int i = 0, j = 0;
	int k = 0;
	while (i < arr1.size() && j < arr2.size())	
	{
		if (arr1[i] < arr2[j])
		{
			ans[k++] = arr1[i];
			i++;
		}
		else
		{
			ans[k++] = arr2[j];
			j++;
		}
	}

	// check if both arrays complete
	while (i < arr1.size()) 
	{
		ans[k++] = arr1[i];
		i++;
	}
	while (j < arr2.size()) 
	{
		ans[k++] = arr2[j];
		j++;
	}
	return ans;
}

// inorder to bst
TreeNode<int> *inorderToBST(int start, int end, vector<int> &in)
{
	if (start > end) return nullptr;
	int mid = (start + end) / 2;
	TreeNode<int> *root = new TreeNode<int>(in[mid]);
	root->left = inorderToBST(start, mid - 1, in);
	root->right = inorderToBST(mid + 1, end, in);
	return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
	// store inorder
	vector<int> bst1, bst2;
	inorder(root1, bst1);
	inorder(root2, bst2);

	// merge two arrays
	vector<int> mergeArray = mergeArrays(bst1, bst2);

	// inorder to bst.
	int start = 0, end = mergeArray.size() - 1;
	return inorderToBST(start, end, mergeArray);

}