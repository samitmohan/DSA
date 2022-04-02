#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

void previous_Smaller_Element()
{
	vector<int> arr =  {4,3,2,1,7,6,9,100,6,15,19,8,18};
	stack<int> st;
	// THE ONLY DIFFERENCE, start from the end and keep decrementing until you reach 0.
	// REST ALL LOGIC IS SAME FOR FINDING GREATER/SMALLER ELEMENT
	for (int i = arr.size(); i >= 0; i--)
	{
		if (st.size() == 0)
		{
			st.push(arr[i]);
			continue;
		}
		while (st.size() != 0 and st.top() > arr[i])
		{
			cout << "Previous smaller element of " << st.top() << " is " << arr[i] << "\n";
			st.pop();
		}
		st.push(arr[i]);
	}

	while (st.size() != 0)
	{
		cout << "Previous smaller element of " << st.top() << " is " << -1 << "\n";
		st.pop();
	}

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    previous_smaller_Element();
    

    return 0;
}
