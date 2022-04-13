// Problem Link -> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
            1
           /  \
          2    5
         / \   / \
        3   4     6
                 /
                7

        1
         \
          2
           \
            3
             \
              4 so on...
*/

// Difficult part -> you can't create a new node, you have to re arrange the Tree such that it points to right and creates a LL.

/*
    Recursive soln: Right Left Root (arrange 7 then arrange left then arrange 1)
    (Reverse post order)
    Attach 7->6, 4->5 so on

    pseudocode.
    prev = null
    flatten(node) { // start with root
        // base case
        if (node == x) return;
        // go right
        flatten(node->right) (keep going right until null)
        // then go left
        flatten(node->left);
        // when left and right both are null.
        node->right = prev; // basically null in the start
        node->left = null;
        prev = node; // prev = 7 now.
    }
    next iteration 6 will be connected to 7 (node->right = prev)
    and 6's left (which was 7 before) is null now (deleted that link)
    now 6->7 (connected) do the same for all recursively!
    Taking question's example, 1st iteration, prev = 7 and is connected to 6's right
    next iteration -> 6's right = prev (7) and 6's left = null (link break)
    6
        \
        7
*/

// TC + SC = O(N)
class Solution
{
    TreeNode *prev = nullptr;

public:
    void flatten(TreeNode *root)
    {
        // base case
        if (root == nullptr)
            return;
        // else go right
        flatten(root->right); // keep going right until null found
        // then go left
        flatten(root->left); // keep going left until null found
        // at this point both left and right = nullptr, leaf node.
        // main logic, connect node's left to null and node's right to prev (do dry run)
        root->right = prev;
        root->left = nullptr;
        // and make prev new root for next iteration
        prev = root;
    }
};