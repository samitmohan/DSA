// https://leetcode.com/problems/k-closest-points-to-origin/
#include <bits/stdc++.h>
using namespace std;

/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]

Explanation : https://leetcode.com/problems/k-closest-points-to-origin/discuss/1647428/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-Friendly-with-detailed-explanations
*/

int kClosest(vector<vector<int>> &points, int k)
{
    // answer vector
    vector<vector<int>> result(k);
    // max heap
    priority_queue<vector<int>> maxHeap;
    // constructor of max heap
    for (auto &p : points)
    {
        int x = p[0], y = p[1]; // coorindates.
        // euclidean area calculate.
        maxHeap.push({x * x + y * y, x, y});
        // main logic
        if (maxHeap.size() > k)
        {
            // keep popping, in the end, the elements left in maxHeap = smallest elements (answer)
            maxHeap.pop();
        }
    }

    // printing
    for (int i = 0; i < k; i++)
    {
        vector<int> top = maxHeap.top(); // top = answer.
        maxHeap.pop();
        result[i] = {top[1], top[2]};
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    kClosest(points, 1); // -2, 2

    return 0;
}
