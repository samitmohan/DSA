#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/asteroid-collision/

int asteroidCollision(vector<int> &asteroids)
{
    // create a stack to store numbers
    stack<int> st;
    for (int x : asteroids)
    {
        // for every x, if x > 0, push to stack.
        if (x > 0)
        {
            st.push(x);
        }
        // else x < 0 (negative)
        // while stack is not empty + top element is positive + x (negative value) > top (pos element)
        else
        {
            while (st.size() != 0 && st.top() > 0 && abs(x) > st.top())
            {
                // the bigger negative value will destroy the positive value. Pop the positive value in the stack.
                st.pop();
            }
            // 3 cases, stack is empty, top < 0, abs(x) == top element
            if (st.size() == 0 || st.top() < 0)
            {
                // no number or only negative in the stack, if you counter another neg number (x in this case) push it to the stack.
                // Because negative doesn't affect negative.
                st.push(x);
            }
            // if abs(x) == top element (-8, 8) = it will destroy the asteroid. Pop.
            else if (abs(x) == st.top())
            {
                st.pop();
            }
        }
    }
    // remaining elements in the stack = answer, pop them and reverse for correct order.
    vector<int> ans;
    while (st.size() != 0)
    {
        // push in the ans vector until size == 0 (keep popping)
        ans.push_back(st.top());
        st.pop();
    }

    // answer = reverse of ans vector.
    reverse(ans.begin(), ans.end());

    // return ans;
    // printing
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> asteroids = {5, 10, -5};
    asteroidCollision(asteroids);

    return 0;
}
