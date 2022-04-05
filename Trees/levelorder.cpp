// Problem Link -> https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC -> O(N) (traverse for all 7 nodes)
// SC -> O(N) stores all nodes in queue

// example
//     1
//    / \
//   2    3
//  / \  / \
// 4   5 6  7

// ans = [[1],[2,3],[4,5,6,7]] (vector<vector>)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
    	// data structure that stores level order traversal (vvi)
    	vector<vector<int>> ans;
    	// if null, return ans
    	if (root == NULL) return ans;
    	// queue for storing elements (of the nodes (not queue<int>))
    	queue<TreeNode*> q;
    	q.push(root); // insert root element
    	// logic -> while queue is not empty, check for left and right nodes
    	// if left child exists, push in queue, if right child exists push in queue
    	// once exploration of one level is over, put that level in ans (push_back)
    	while(!q.empty()) 
    	{
    		// size = 1 initially, 2,3 second iteration, 4,5,6,7 third iteration
    		int size = q.size(); // each iteration will have diff size of queue
    		vector<int> level;
    		for (int i = 0; i < size; i++) {
    			// taking node and popping it ([1] [2,3] so on)
    			TreeNode *node = q.front(); // front element
    			q.pop();
    			if (node->left != NULL)
    			{
    				q.push(node->left);
    			}
    			if (node->right != NULL)
    			{
    				q.push(node->right);
    			}
    			level.push_back(node->val);
    		}
    		ans.push_back(level);
    	}
    	return ans;
    }
};