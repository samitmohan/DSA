#include <iostream>
#include <vector>
using namespace std;

// Kid with the greatest number of candles
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

int kidWithCandies(vector<int> &candies, int extraCandies)
{
    int max = INT_MIN; // current max is lowest as of now.
    // go through the list and check for the max number. O(N)
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] > max)
        {
            // update max.
            max = candies[i];
        }
    }

    // Result bool vector.
    vector<bool> res;
    for (int i = 0; i < candies.size(); i++) // O(N)
    {
        if (candies[i] + extraCandies >= max)
        {
            // answer found -> True
            res.push_back(true);
        }
        else
        {
            res.push_back(false);
        }
    }

    // for(auto x : res){
    //     cout << x << " ";
    // }
    return res;

    // Total complexity - O(N) + O(N) = O(N)
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> candies = {2, 3, 5, 1, 3};
    kidWithCandies(candies, 3);

    return 0;
}
