// All tree traversals take O(N) time and O(N) space

// But Morris Traversal, O(N) time, but O(1) space.
// Uses the concept of threaded binary tree.

/* Inorder -> left root right

      1
     / \
    2  3
   /\
  4  5
      \
       6


Inorder -> 4 2 5 6 1 3
Steps -:
Logic : Once moved on you can't come back hence you make the threaded connections to keep track.
    1) last node points to root.
    Cases
    1) If left == nullptr, print (current) and move to right
    2) Rightmost guy on left ST (6) will be connected to curr(root (1)) and move to left
    3) When you come back to root, do you go left or right? if left != nullptr (already a thread is made by us and we've gone left) delete the thread and move right
       " once left has been visited, cut off link and go right "
    Dry run in notebook.
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root; // current node.
        while (curr != nullptr)
        {
            // first edge case, if curr has a left == nullptr, print curr and move to right
            if (curr->left == nullptr)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {

                // second case, if left exists, go to left ST and connect right most guy to curr (root) and move to left
                TreeNode *prev = curr->left;
                // if right exists and right doesn't point to itself.
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right; // find the rightmost guy (6)
                }
                if (prev->right == nullptr)
                {
                    // create thread and move to left
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // prev->right points to curr, delete thread
                    prev->right = nullptr;
                    // since i've come back, print curr val
                    inorder.push_back(curr->val);
                    curr = curr->right; // since left has been visited, move to right
                }
            }
        }
        return inorder;
    }
};
