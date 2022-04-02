#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

// empty
// size
// front
// back
// push_back
// pop_front

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    cout << q1.size() << "\n";
    cout << q1.front() << "\n";
    cout << q1.back() << "\n";
    cout << q1.empty() << "\n";
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    cout << q1.empty() << "\n"; // now queue is empty (1)

    return 0;
}
