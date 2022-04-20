// Problem link -> https://leetcode.com/problems/binary-search-tree-iterator/

// Solution -> https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)

class BSTIterator
{
public:
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root) 
    {
        partialInorder(root);
    }

    void partialInorder(TreeNode *root)
    {
        while(root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next() 
    {
        TreeNode *top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};