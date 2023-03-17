#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

int maxProfit(vector<int> &prices)
{
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < prices[i + 1])
        {
            max_profit += prices[i + 1] - prices[i];
        }
    }

    return max_profit;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}
