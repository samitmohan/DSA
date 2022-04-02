#include <iostream>
#include <vector>

#define ll long long
using namespace std;
// Find max contigious sub array sum

int maxSubArray(vector<int> &arr)
{
	int current_sum = 0, max_sum = INT_MIN; // for now its minimum
	for (int i = 0; i < arr.size(); i++)
	{
		// sum till this point = current sum till this point + this element
		current_sum = current_sum + arr[i];

		// if current max sum is greater than total sum, update it.
		max_sum = max(max_sum, current_sum);

		// if current sum = -ve, no point in carrying forward, make it 0.
		current_sum = max(0, current_sum);
	}
	return max_sum;
}

int main()
{
	vector<int> arr = {-2, 1, -3, 4};
	cout << maxSubArray(arr);
	return 0;
}
