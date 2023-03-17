#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

// Same logic as NGE, just reverse stack_top and current_element comparision
// Find the smaller element and print, if no smaller element = -1

void next_Smaller_Element()
{
	vector<int> arr =  {4,3,2,1,7,6,9,100,6,15,19,8,18};
	stack<int> st;
	// loop through the array
	for (int i = 0; i < arr.size(); i++)
	{
		// push them to the stack IF stack is empty.
		if (st.size() == 0)
		{
			st.push(arr[i]);
			continue;
		}

        // while stack is not empty + top_element < current_element
		// next smaller found
		// print NSE of st.top() is arr[i] (current element)
		while (st.size() != 0 and st.top() > arr[i])
		{
			cout << "Next smaller element of " << st.top() << " is " << arr[i] << "\n";
			st.pop();
		}
		// finally all are removed and current element = 1 (smallest one)
        // now push current element (1) to the stack and repeat the process for the remaining numbers
		st.push(arr[i]);
		// continues again until all numbers have been travelled.
	}

	// for remaining elements (1 or smaller elements) answer = -1 (no next smaller element)

	while (st.size() != 0)
	{
		cout << "Next smaller element of " << st.top() << " is " << -1 << "\n";
		// keep removing them.
		st.pop();
	}

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    next_Smaller_Element();
    

    return 0;
}
