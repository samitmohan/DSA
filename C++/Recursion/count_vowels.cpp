// Proceed to build string recursively
// Insert next element in string only if it is greater than last element present and decrease n by 1
// if n == 0, base case hit return answer

class Solution 
{
public:
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

    void solve(int n, int last, int &count)
	{
		if (n == 0) 
		{
			count++;
			return;
		}

		for (int i = 0; i < 5; i++)
		{
			if (i >= last) 
			{
				solve(n - 1, i, count);
			}
		}
    }

	int countVowelStrings(int n) 
	{
		int count = 0;
		solve(n, 0, count);
		return count;
	}
};
