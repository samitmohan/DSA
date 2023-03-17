// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

/*
--- Problem Statement ---
Give node v and integer k, find kth ancestor of v
Ancestor -> everything from that part to root.

--- Answer ---
Bruteforce
v = 9, find third ancestor (k = 3)

repeat k times:
    v = parent[v]

Complexity -> Worst case O(N)

Try to do it in O(logN) -> Binary Lifting.
How to get logN -> 2 ways, binary search, divide and conqueur
                           powers of two. (binary lifting / sparse tables / segment trees)

n = 100
available powers of 2
1 2 4 8 ... 64
logN^

if k is power of 2, you can very quickly answer that.
(v, 64) -> directly jump

          0
     /     \    \
    1       3    5
  /  \          /
2     4        6
       \
        7
       / \
     11   8
           \

             \
              10

v = 10, k = 6.
Blackbox = tells the ancestor of only powers of 2

Blackbox -> tells the 4th ancestor
Quickly jump to 4th ancestor
Ask the blackbox to give the 2nd acestor
Quickly jump to 2nd ancestor
2 steps -> 6th ancestor.

Any k can be represented as sum of powers of 2.
K = 19 = 10011 = 16 + 2 + 1 (3 jumps)

Preprocessing
Pseudocode.

We know parent of 10 -> 9 but how do we know the parent of parent (grandparent)

int up[N][LOG]
uo[v[][j] -- 2^j-th ancestor of v.
for v = 0 .. N - 1:
    up[v][0] = parent[v] // parent

    up[v][1] = up[ up[v][0] ][0] // ancestor (grandparent)
    up[v][2] = up[ up[v][1] ][1] // second ancestor
    up[v][3] = up[ up[v][2] ][2] // third ancestor

    In general.
    for j = 1 .. log - 1
        up[v][j] = up [ up [v][j-1] ] [j-1]

Time & Space -> O(N*log(N)) // depth of tree. (Difficult to code)

Boilercode

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {

    }

    int getKthAncestor(int node, int k) {

    }
};

 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
*/

// Bruteforce

class TreeAncestor
{
    unordered_map<int, int> mp;
public:
    // store values of all parents in the map
    TreeAncestor(int n, vector<int> &parent)
    {
        for (int i = 0; i < n; i++)
        {
            mp[i] = parent[i];
        }
    }

    int getKthAncestor(int node, int k)
    {
        int count = 0;
        // keep going up unless you reach kth acnestor or reach at highest point(root)
        while (mp[node] != -1)
        {
            node = mp[node];
            count++;
            if (count == k)
            {
                // answer found
                return node;
            }
        }
        return -1; // not found
    }
};

// TC -> O(Q * N) q = queries, n = nodes. SC -> O(N)
