#include <bits/stdc++.h>
using namespace std;

// Adjaceny Matrix

int main()
{
    // nodes and edges
    int n, m;
    cin >> n >> m;

    // declare adj matrix
    int adj[n + 1][n + 1]; // graph will be stored here

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        // every line has edge
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

// SC -> O(N^2)

// Better way -> Adjacent List
// vector<int> adj[6] for 5 nodes (1 based indexing) -> creates array 0 1 2 3 4 5 (indexes)

/*
0 -> vector
1 -> vector
2 -> vector
3 -> vector
4 -> vector
5 -> vector

(1-2), 1 is adj of 2 and 2 is adj of 1 then store it

1 -> 2
2 -> 1
(1-3), 1 is adj of 3 and 3 is adj of 1
1->2->3
2->1
3->1

so on...
*/

// SC -> (N + 2E)
// adj[u].push_back(v)  for undirected 
// adj[v].push_back(u)
// if graph is weighted -> convert vector<int> to pair<int, int> (first -> adj node, second -> weight of that edge)
// adj[u].push_back({v,w}

int main() 
{
    int n, m;
    cin >> n >> n;
    vector<int> adj[n + 1];
    // vector<pair<int, int>> adj[n + 1]  (for weighted)

    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v; // >> wt;
        adj[u].push_back(v); // {v, wt};
        adj[v].push_back(u); // {u, wt};

    }
    return 0;
}

/*
Visited array, set all to 0 at first
 for (int i = 1; i <= nodes; i++) {
    if (!visited[i] {
        dfs/bfs (traverse)
    }
}
*/
