#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/

/* Problem
Input :
                       12
                     /     \
                   13       10
                          /     \
                       14       15
                      /   \     /  \
                     21   24   22   23
target node = 14

Output :
14
21, 24, 10
15, 12
22, 23, 13

Explanation : First node 14 burns then it gives fire to it's
neighbors(21, 24, 10) and so on. This process continues until
the whole tree burns.

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

*/
/*
---Documentation---

Step 1:
    burn left child, right child, parent
    l,r available, but parent not available so create a map which maps node to it's parent.
    map <node *, node*> mapping
    do this via traversal -> level order traversal
    Example
    12->n
    13->12
    10->12
    14->10
    15->10
    and so on...

Step 2
    find target node. O(height)

Step 3
    Burn and find minimum time.
    Pick a node, burn neighbour node. (Breadth First Traversal)
    2 DS required
    Visited Map (map<node*, bool> visitedOrNot) (12 -> true)
    Traversal from Target Node queue (target = first elem in queue)
    Time = 0
    Left, Right, Parent (options, check if they exists and check for visited)
    Checking if there was any addition in the queue.
        if true -> TIME++ (need to burn this)
        if false -> ignore.

When to stop : If left right null and parent already visited -> ignore
return time.
*/

class Solution
{
public:
    // create mapping. (S1)
    // return target node. (S2)
    Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        // return target node in the end = res
        Node *res = nullptr; // initially
        // Level order traversal
        queue<Node *> q;
        q.push(root);
        nodeToParent[root] == nullptr; // root has no parent.
        while (!q.empty())
        {
            // front node
            Node *front = q.front();
            q.pop();
            // check if front == target
            if (front->data == target)
            {
                // store in result
                res = front;
            }
            // else if front->left exists, put it in the mapping (parent child map)
            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->right); // push in queue (level order traversal)
            }
            // same with right
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    // S3
    int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
    {
        // Visited map
        map<Node *, bool> visited;
        // queue for level order traversal
        queue<Node *> q;
        q.push(root);
        visited[root] = true; // mark

        // Level Order Traversal start
        int ans = 0;
        while (!q.empty())
        {
            // check if addition in queue
            bool flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                // process neighbouring nodes.
                // find front
                Node *front = q.front();
                q.pop();

                // 3 ways -> left, right, parent
                // left
                if (front->left && !visited[front->left])
                {
                    // if true, mark that queue has been modified, push in queue and visited is marked true
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }

                // same for right
                if (front->right && !visited[front->right])
                {
                    // if true, push in queue and visited is marked true
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                // visit parent (by using the mapping)
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if (flag == 1)
            {
                ans++; // time
            }
        }
        return ans;
    }

    int minTime(Node *root, int target)
    {
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, target, nodeToParent);
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};

// Time Complexity -> O(map) O(N) or O(NlogN)
// Space Complexity -> O(N)
