#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int i = 2;
    int count = 0;
    while(i <= n)
    {
        // print all numbers from 2 to n
        cout << i << " ";
        // increment count by 1 
        count++;
        // logic to skip numbers, 2 = 2+(1*4) = 6 = 6+(2*4) = 14 ...
        i = i + count * 4;
    }
    return 0;
}
