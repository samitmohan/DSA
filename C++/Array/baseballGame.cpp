#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

*/

int callPoints(vector<string> &ops)
{
    vector<int> record; // answer
    for (string ch : ops)
    {
        if (ch == "C")
        {
            record.pop_back();
        }
        else if (ch == "D")
        {
            // vector.back() -> prevs element
            record.push_back(record.back() * 2);
        }
        else if (ch == "+")
        {
            // sum of prevs 2 scores
            record.push_back(record.back() + record[record.size() - 2]);
        }
        else
        {
            record.push_back(stoi(ch)); // else just insert element into the vector (after converting it to integer)
        }
    }
    // answer -> sum of vector
    return accumulate(record.begin(), record.end(), 0);
}

int main()
{
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << callPoints(ops) << endl; // 30

    return 0;
}

// Alt solution -> using stack

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> st;
        for (string s : ops)
        {
            // push string into stack and convert it to integer
            if (s != "C" && s != "D" && s != "+")
            {
                st.push(stoi(s));
            }
            // take 2 top elements and push it by adding up
            else if (s == "+")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1 + temp2);
            }
            else if (s == "D")
            {
                // push the top element by doubling it
                int temp = st.top();
                st.push(2 * temp);
            }
            else
            {
                // C occurs -> pop
                st.pop();
            }
        }

        // after all operations, pop all elements and sum up
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
