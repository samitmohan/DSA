// Problem link -> https://www.codingninjas.com/codestudio/problems/ceil-from-bst

/*
Given a binary search tree and an integer. Now he is given a particular key in the tree and returns its ceil value.
Ceil of an integer is the closest integer greater than or equal to a given number.
For example:
arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
The closest integer greater than 3 in the given array is 5. So, its ceil value in the given array is 5.

     8
    / \
   3   10

x = 2, ceil = 3.
*/

int findCeil(BinaryTreeNode<int> *root, int key)
{

    int ceil = -1; // initially.
    while (root)
    {
        // traverse tree
        if (root->data == key)
        {
            // perfect answer found
            ceil = root->data;
            return ceil;
        }

        if (key > root->data)
        {
            // move to right
            root = root->right;
        }
        else
        {
            // root less than ceil.
            // make this the current ceil and move left.
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Floor (similar)

/*
You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.
Note :‘X’ is not smaller than the smallest node of BST .

        10
       /  \
      5    15
     / \
    2   6

In the above example, For the given BST  and X = 7, the greatest value node of the BST  which is smaller than or equal to 7 is 6.
*/
int floorInBST(TreeNode<int> *root, int key)
{
    int floor = -1;
    while (root)
    {

        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }

        if (key > root->val)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}
