#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Question
// There is a long wire along a straight line which contains N bird nests at positions x1, x2 .. xN. There are B birds (B<=N) which become angry
// towards each other once put into a nest. To put birds from hurting each other you want to assign birds to nests such that min dist b/w 2 birds is max.

// helper function

bool canPlaceBirds(int B, int N, vector<int> &nests, int seperation)
{
    // seperation = min sep
    int birds = 1;
    int last_location = nests[0]; // last location is at 0th nest

    for (int i = 1; i <= N - 1; i++)
    {
        int current_location = nests[i];
        if (current_location - last_location >= seperation)
        {
            birds++;
            last_location = current_location;

            // number of birds that have placed = B which means we have found answer
            if (birds == B)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nests = {1, 2, 4, 8, 9};
    int B = 3;
    // Sort
    sort(nests.begin(), nests.end());
    int N = nests.size();

    // Binary Search
    int low = 0;
    int high = nests[N - 1] - nests[0]; // max distance
    int answer = -1;                    // no such config is possible as of now.

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // If it's feasible to place B number of birds in these nests as mid position

        bool canPlace = canPlaceBirds(B, N, nests, mid); // birds, nest, seperation
        if (canPlace == true)
        {
            answer = mid;  // potential answer
            low = mid + 1; // check for bigger number (maximise it)
        }
        else
        {
            high = mid - 1; // check for left side.
        }
    }

    cout << answer << endl;

    return 0;
}
