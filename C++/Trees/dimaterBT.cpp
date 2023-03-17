#include <iostream>
using namespace std;

// diameter in cirlce -> max distance
// diameter -> longest path between 2 nodes.
// path does not need to path via root.

/*

    1
   / \
  2   3
 / \
4   5

4 -> 2 -> 1 -> 3 = length = 3

Find out -> lh + rh (for most cases), (for special cases) left diameter, right diameter. Answer -> max of three.
*/

// height function (1 + max(lh,rh))

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;                                            // base case.
    return 1 + max(height(root->left), height(root->right)); // standard formula
}

int diameterOfBinaryTree(TreeNode *root)
{
    // base case
    if (root == nullptr)
        return 0; // no node, dist = 0
    // option 1 -> height of left + height of right

    // standard case
    int option1 = height(root->left) + height(root->right);

    // special case option 2 -> diameter of left (using recursion)
    int option2 = diameterOfBinaryTree(root->left);

    // special case option 3 -> diameter of right (using recursion)
    int option3 = diameterOfBinaryTree(root->right);

    // answer -> max(o1,o2,o3)
    return max(option1, max(option2, option3));
}

// return 1 + max(height(root->left), height(root->right));
// Complexity of height -> O(N)

// Complexity of diameter (2 recursive call) height(root->left) + height(root->right)
// O(n * h) depends on height, if balanced tree -> nlogn, if skewed -> n^2
