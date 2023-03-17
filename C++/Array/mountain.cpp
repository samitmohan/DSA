#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// 3 numbers are required to form mountain (5 10 8) -> Increasing and then decreasing.
// Input -> [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]  (Sample Output = 9)
// Visual
/*         5         3   4
          / \4       /\ /
       4 /   \3    2/  -2 
  6   3 /     \2  1/   
 /\  2 /       \  /
/  \  /         0
5  1
     <----------> Length = 9.
*/

int highest_mountain(vector<int> arr)
{
    int largest = 0;
    // last element and first element cant be peak so we iterate from 1 to 2nd last element
    for (int i = 1; i <= arr.size() - 2; i++)
    {
        // check if current number is peak or not
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            // peak found (do some work (find length of peak))
            int count = 1; // at peak
            int j = i;
            // count backwards (left -> how many elements are there)
            // if j = 0, seg fault
            while (j >= 1 and arr[j] > arr[j - 1])
            {
                j--;
                count++;
            }

            // count forwards (right -> how many elements are there)
            // if i = n-1, seg fault
            while ((i < arr.size() - 2) and arr[i] > arr[i + 1])
            {
                i++;
                count++;
            }
            largest = max(largest, count);
        }
    }
    return largest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highest_mountain(arr);

    return 0;
}
