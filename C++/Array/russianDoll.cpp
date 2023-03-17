class Solution
{
public:
    int binSearch(vector<int> &vec, int maxVal, vector<vector<int>> &envelopes, int i)
    {
        int low = 0;
        int high = maxVal;

        int temp = maxVal;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (vec[mid] < envelopes[i][1])
                low = mid + 1;

            else
            {
                temp = mid;
                high = mid - 1;
            }
        }

        return temp;
    }

    // to sort in decreasing order
    static bool decSort(vector<int> &v1, vector<int> &v2)
    {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];

        return v1[0] < v2[0];
    }

    // answer
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int size = envelopes.size();

        if (size == 0)
        {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), decSort); // sort in decreasing order

        vector<int> vec(size, 0); // empty array filled w 0s
        int maxVal = 0;

        for (int i = 0; i < size; i++)
        {
            int pos = binSearch(vec, maxVal, envelopes, i);

            vec[pos] = envelopes[i][1];

            if (pos == maxVal)
                maxVal++; // number of russian dolls that can fit
        }
        return maxVal;
    }
};