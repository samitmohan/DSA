#include <bits/stdc++.h>
using namespace std;
// Problem link -> https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/#
/*
Input:
        3
      /   \
     2     1
Output:
3 1 2

Input:
           7
        /     \
       9       7
     /  \     /
    8    8   6
   /  \
  10   9
Output:
7 7 9 8 8 6 9 10

---- Approach ----

observation : level order traversal is happening in some sort.
Go L-R then R-L then L-R and so on...
queue, with root node data. flag -> L_R, if L_R true then you went L-R, if false then you went R-L
pop and insert it's child into it in the opposite direction (if L-R previously, child -> R-L)

*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;
        // base case
        if (root == nullptr)
            return result;

        // level order
        queue<Node *> q;
        q.push(root);
        // flag
        // first time you go left to right and then chan alternate time
        bool leftToRight = true;

        while (!q.empty())
        {
            // number of elements in the level
            int size = q.size();
            // temp array ans
            vector<int> ans(size);

            // process every level, after that change the direction (l-r then r-l and so on)
            for (int i = 0; i < size; i++)
            {
                // front nodes.
                Node *frontNode = q.front();
                q.pop();
                // temp array directions -> L-R or R-L
                // if index L-R then index is curr element (normal flow) if false then insert in reverse order (size - i - 1)
                // normal insert or reverse insert.
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                // if front_node left is not null then push front_node left, similarily for right
                if (frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if (frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }
            // change direction for next level
            leftToRight = !leftToRight;
            // insert all elements of temp array ans into the final result
            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};