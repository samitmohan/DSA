#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

int maxProfit(vector<int> &prices)
{
    // two numbers (i and j)
    // i = buying day
    // j = selling day
    // Conditions = j > i (for profit)
    // max(prices[j] - prices[i]) = profit.
    // Find the maximum difference between two numbers in the given array.

    // BruteForce Approach O(N^2)
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        // selling day comes only after buying day. (can't sell before buying) j = i+1
        for (int j = i + 1; j < prices.size(); j++)
        {
            int profit = prices[j] - prices[i];
            if (profit > maxProfit)
            {
                // update
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

// O(N)

/* {7,1,5,3,6,4}

minprice = INT_MAX
maxprofit = 0

7. Min price = min(INT_MAX, 7) = 7.
   Max profit = max(0, 7-7) = 0.

1. Min price = min(7,1) = 1.
   Max profit = max(0, 0) = 0. (current - minPrice) [max(0,0) = 0]

5. Min price = min(1,5) = 1.
   Max profit = max(0, (5-1)) = 4.

3. Min price = min(1,3) = 1.
   Max profit = max(4, 2) = 4.

6. Min price = min(1,6) = 1.
   Max profit = max(4, (6-1)) = 5.

return maxProfit = 5. Answer

*/

void maxProfit_optimized(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = INT_MAX; // for now
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    cout << minPrice;
    cout << endl;
    cout << maxProfit;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prices = {10, 20, 30, 40, 50};
    maxProfit_optimized(prices);

    return 0;
}
