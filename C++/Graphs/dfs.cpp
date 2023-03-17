// https://takeuforward.org/data-structure/depth-first-search-dfs-traversal-graph/
/*
It starts traversal through any one of its neighbour nodes and explores the farthest possible node in each path/branch and then starts Back-tracking.

Backtracking happens when DFS reaches a particular node that has no neighbours to visit further, it'll backtrack to it's previous node
and from this node, algorithm will start searching for unvisited neighbour nodes.
*/

/*
---Approach---
1) Start with a random node from graph
2) Make array to keep track of visited nodes, once visited mark that node as visited.
3) Print this current node
4) Get neighbour nodes and perform above steps recursively for each node if node is unvisited

Time complexity : O(N + E), Where N is the time taken for visiting N nodes and E is for travelling through adjacent nodes.
Space Complexity : O(N + E) + O(N) + O(N), space for -> adjacency list, array, auxiliary space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs_algo(int node, vector<int> &visited, vector<int> adj[], vector<int> &storedfs)
    {
        storedfs.push_back(node);
        visited[node] = 1;
        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                dfs_algo(x, visited, adj, storedfs);
            }
        }
    }

public:
    vector<int> dfs(int v, vector<int> adj[])
    {
        vector<int> storedfs;
        vector<int> visited(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                dfs_algo(i, visited, adj, storedfs);
            }
        }
        return storedfs;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6]; // for 5 elements
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 2);
    addEdge(adj, 5, 1);
    Solution obj;
    vector<int> ans;
    ans = obj.dfs(5, adj);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
