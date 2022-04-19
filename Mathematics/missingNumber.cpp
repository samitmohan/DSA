#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;

int missingNumber(vector<int>& nums) 
{
    long long sum=0;
    int x = nums.size();
    for(int i=1;i<x;i++)
    {
        sum+=nums[i];
    }
    long long res = x*(x+1)/2-sum;
    return res;
} 

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> nums = {2,3,1,5};
    cout << missingNumber(nums);
    
    return 0;
}   
