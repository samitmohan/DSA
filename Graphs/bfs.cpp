// https://www.youtube.com/watch?v=pcKY4hjDrxk&ab_channel=AbdulBari
// https://takeuforward.org/data-structure/breadth-first-searchbfs-level-order-traversal/

// Level order traversal.
/*
---Approach---
1) Capture a node, after capturing this node, put this node's value into answer vector and mark its visited value as true.
    Now this node will have some adjacent nodes connected to it.
2) Push all adjacent ndoes which are not visited into the queue data structure.
    If we encounter any visited adj nodes, they won't be considered bcs we don't want to consider them twice.
3) Cover all nodes breadth wise.

    1) Queue DS
    2) Visited array -> An array with all val initialised as 0.
    -> We will push the 1st node into the queue data structure and mark it as visited.
    Find its adjacent nodes. If we get some unvisited node, we will simply push this adjacent node into the queue data structure.
    -> Now since work of 1st node is done, pop out from queue, and the process goes on until queue is not empty.

Time Complexity : O(N+E)
    N = Nodes , E = travelling through adjacent nodes
Space Complexity : O(N+E) + O(N) + O(N)
    Space for adjacency list, visited array, queue data structure
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(int v, vector<int> adj[])
    {
        vector<int> bfs;       // answer vector
        vector<int> vis(v, 0); // all nodes initialised with 0.
        queue<int> q;
        q.push(0); // at first.
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // finding adj nodes
            for (auto x : adj[node])
            {
                if (!vis[x])
                {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    Solution obj;
    vector<int> ans = obj.bfs(5, adj);
    print(ans);
    cout << endl;
    return 0;
}
