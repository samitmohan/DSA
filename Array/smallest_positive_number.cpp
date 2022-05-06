#include <bits/stdc++.h>
using namespace std;

// lab program (java)

int smallestPos(vector<int> &arr, int n) 
{
	int res = 1;
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] <= res) 
		{
			res += arr[i];
		}
	}
	return res;
}

int main() 
{
	vector<int> arr = {1, 3, 5, 7};
	cout << smallestPos(arr, arr.size()) << endl;
	return 0;
}
