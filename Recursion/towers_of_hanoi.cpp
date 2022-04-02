#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// Tower of Hanoi (Recursion)

/*
Procedure Hanoi(number_of_plates, source, destination, helper)

   IF plates == 1, THEN
      move plate from source to destination
   ELSE
      Hanoi(n - 1, source to helper via destination)     // Step 1
      print -> move plates from source to destination    // Step 2
      Hanoi(n - 1, helper to destination via source)     // Step 3

END Procedure
*/

void solve(char source, char destination, char helper, int n)
{
    // if single plate -> source to destination directly
    // Base Case
    if (n == 1)
    {
        cout << "Moving plate 1 from " << source << " to " << destination << "\n";
        return;
    }
    // n-1 from source to helper (source to b) (source to helper using destination (works as helper) for n-1 plates)
    solve(source, helper, destination, n - 1);
    // only 1 plate left, place in destination. (biggest plate)
    cout << "Moving plate " << n << " from " << source << " to " << destination << "\n";
    // From helper to destination (put all plates on top of the biggest plate) (n-1 discs)
    solve(helper, destination, source, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    // source = a
    // helper = b
    // destination = c
    solve('A', 'C', 'B', n);
    return 0;
}
/*
---------Time Complexity---------
Let the time required for n disks is T(n) .
There are 2 recursive call for n-1 disks and one constant time operation to move a disk from ‘from’ plate to ‘to’ plate . Let it be k1.

T(n) = 2 T(n-1) + k1
T(0) = k2 , a constant.
T(1) = 2 k2 + k1
T(2) = 4 k2 + 2k1 + k1
T(2) = 8 k2 + 4k1 + 2k1 + k1

Coefficient of k1 = 2n
Coefficient of k2 = 2n

Time complexity is O(2^n) or O(a^n) where a is a constant greater than 1.
So it has exponential time complexity.

-------Space Complexity----------
Space for parameter for each call is independent of n i.e., constant. Let it be k .
When we do the 2nd recursive call 1st recursive call is over. So, we can reuse the space of 1st call for 2nd call.

T(n) = T(n-1) + k
T(0) = k
T(1) = 2k
T(2) = 3k
T(3) = 4k

So the space complexity is O(n).
*/
