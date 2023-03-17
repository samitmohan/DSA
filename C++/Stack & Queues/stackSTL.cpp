#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // we can also do stack<string> or stack<char>
    stack<int> s1;
    s1.push(10);
    s1.push(20101010);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.pop();
    cout << s1.top();

    return 0;
}
