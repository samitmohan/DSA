#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;

// 3
// c
// cb
// cba


// find lexigraphically(in dictionary) smallest

// output = cbacbc

// Direct sorting and adding wont work.


bool compare(string x, string y){
    return x + y < y + x;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string arr[] = {"a", "ab", "aba"};
    int n = 3;
    sort(arr, arr+n, compare);
    
    for(auto s : arr){
        cout << s;
    }

    return 0;
}