#include <iostream>
using namespace std;

// diameter -> longest path between 2 nodes.
// path does not need to path via root.

// binary tree -> children sum property.

/*

    1
   / \
  2   3
 / \
4   5

4 -> 2 -> 1 -> 3 = length = 3
*/

// naive approach -> traverse entire tree, longest path = lh + rh
// for the above diagram its 2(lh) + 1(rh) = 3

int diameter(node)
{
    if (root == nullptr)
        return;
    int maxi = 0;
    lh = find_left_half(node->left);   // get left half
    rh = find_right_half(node->right); // get right half
    maxi = max(maxi, lh + rh);
    diameter(node->left);
    diameter(node->right);
}

// O(N) + figuring out left height/right height -> O(N) = O(N^2) shit solution.

// Optimise to O(N)
// Height of tree -> max(lh + rh) + 1

// Maximum is 0 initially (maxi = 0)
// 1) Go to left until null reached, when null reached, return 0.
// 2) Go to right until null, return 0.
// 3) max(maxi, lh + rh)
// 4) return 1 + max(lh, rh);
