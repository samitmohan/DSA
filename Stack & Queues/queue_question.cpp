#include <iostream>
#include <queue>
using namespace std;
void binaryRepresentation(int num)
{
    if (num == 0)
    {
        cout << "0"
             << " ";
        return;
    }
    queue<string> que;
    que.push("1");
    int cnt = 1;
    while (cnt <= num)
    {
        string rem = que.front();
        que.pop();
        cout << rem << "\n";
        if (cnt + 1 <= num)
        {
            que.push(rem + "0");
            cnt++;
        }
        if (cnt + 1 <= num)
        {
            que.push(rem + "1");
            cnt++;
        }
    }
    while (que.size() != 0)
    {
        cout << que.front() << " ";
        que.pop();
    }
}
int main()
{
    binaryRepresentation(10);
    return 0;
}