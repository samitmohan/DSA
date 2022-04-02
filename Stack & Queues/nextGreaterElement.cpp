#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

// Next Greater Element

/*---Documentation----

4,3,2,1,7,8,9,100,6,15,19,8,18

print next greater element

4 -> 7
3 -> 7
2 -> 7
1 -> 7
7 -> 9
6 -> 8
9 -> 100
100 -> -1 (none)
6 -> 15
15 -> 19
19 -> -1 (none)
8 -> 18
18 -> -1

Bruteforce -> for (int i = 0; i < arr.size(); i++) { if i+1 > i { cout << i << " "}} 
Complexity = O(N^2) (n-1 comparisions for 1st, n-2 comparisions for second) 
Space = O(1)

void solve(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- " << next << endl;
    }
}

O(N) solution using stack. 
Complexity = O(N) (Both time and space)

---Logic---
Go through all the numbers.
if stack is empty
    add the current element to the stack (value)

// MAIN LOGIC
while (stack is not empty AND stack.top < current element)  
    1 < 7 ? YES, cout << next greater element of 1 (stack.top) is current element (7) and stack.pop
    (PS -> for next_Smaller_Element it should be stack.top > current element) [SIGN CHANGE]


once this gets completed, only number left = biggest number = 7
Check for 7.
st.push(current element)

Remaining elements = -1
while (stack is not empty)
    cout << next greater element of stack.top(100 or 19 or 18) is -1
    stack.pop

    

*/

void next_Greater_Element()
{
    vector<int> arr = {4,3,2,1,7,6,9,100,6,15,19,8,18};
    stack<int> st;
    // loop through the array
    for (int i = 0; i < arr.size(); i++)
    {
        // push curr element to stack IF stack is empty
        if (st.size() == 0)
        {
            st.push(arr[i]); 
            continue;
        }

        // Main logic 
        // while stack is not empty + top_element < current_element
        // next greater found!
        // print NGE of st.top() is arr[i] (current element)
        while (st.size() != 0 && st.top() < arr[i])
        {
            cout << "Next greater element of " << st.top() << " is " << arr[i] << "\n";
            // remove them and check for next
            st.pop();
        }
        // finally all are removed and current element = 7 (as of now biggest one) [FIRST ITERATION]
        // now push current element (7) to the stack and repeat the process for the remaining numbers
        st.push(arr[i]);
        // continues again until all numbers have been travelled.
    }

    // for remaining elements (100 or 19 or 18 that have no NGE) answer = -1 (no next greater element)
    while(st.size() != 0)
    {
        cout << "Next greater element of " << st.top() << " is " << -1 << "\n";
        // keep removing them.
        st.pop();

    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
    next_Greater_Element();


    return 0;
}
