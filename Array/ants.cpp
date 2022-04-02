// Problem Link -> https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/* Ants are moving, they direction when they meet, find time when all ants fall off the plank.

--- Logic ---

When two ants meet they change direction, even if they don't change direction, it's the same thing (no one's naming the ants)
time it takes to fall off -> time it takes to cover maximum distance from that point to the plank
lets assume that ant left[i] and right[i] collide at any point x, so after collision they change their direction

after collision ant left[i] change its direction and start moving towards right from point x
after collision ant right[j] change its direction and start moving towards left from point x
replace left[i] and right[j] ant -> and there will be no effect of collision

After collision rather than changing their direction assume left[i] becomes right[j] and vice versa
*/

int getLastMoment(int n, vector<int> &left, vector<int> &right)
{
    // current ans = 0
    int ans = 0;

    // for left vector
    for (int i = 0; i < left.size(); i++)
    {
        ans = max(ans, left[i]);
    }

    // for right vector
    for (int i = 0; i < right.size(); i++)
    {
        ans = max(ans, n - right[i]);
    }

    // answer = maximum distance = time
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> left = {4, 3};
    vector<int> right = {0, 1};
    // n = number of ants
    cout << getLastMoment(4, left, right) << "\n";

    return 0;
}
