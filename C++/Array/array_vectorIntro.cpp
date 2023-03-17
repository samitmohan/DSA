// Arrays and Vectors
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int inpvalueFromUser()
{
    // size(n) = sizeof(arr)/sizeof(arr[0])
    int n = 6;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    { // or use the iterator method;
        cout << arr[i] << " ";
    }
    return 0;
}

int capacity()
{
    vector<int> arr;
    for (int i = 1; i < 20; i++)
    {
        arr.push_back(i);
        cout << arr.size() << " " << arr.capacity() << endl;
    }
    return 0;
}

int multipleVect()
{
    vector<int> vec2(10, 0); // all 0s
    // for(int i=0;i<vec2.size();i++){
    //     cout << vec2[i] << " ";
    // }
    for (auto x : vec2)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Vectors -> dynamic array
    vector<int> arr = {1, 2, 3, 4, 5};
    for (auto elem : arr)
    {
        // cout << elem << " ";
    }
    cout << endl;
    // push back -> pushing back a new element

    arr.push_back(100);
    arr.pop_back(); // remove
    // arr.size() => length
    for (auto elem : arr)
    {
        //cout << elem << " ";
    }

    // Vector capacity and size difference
    /*
       vec.pb(10) -> size = 1, capacity = 1
       vec.pb(20) -> size = 2, capacity = 2
       vec.pb(30) -> size = 3, capacity = 4
       vec.pb(40) -> size = 4, capacity = 4
       vec.pb(50) -> size = 5, capacity = 8

       Size => Numbers that are there in the vector
       Capacity -> Total numbers that vector can store .
     Whenever space is required, bytes are doubled. (for 1 -> 1, for 2 -> 2(double of 1), 3 -> 4(double of 4), 4-> 4, (now filled), 5->8)
    */

    // Insert function in vector to insert anywhere. vector.insert(vec.end()-1, 100); // second last
    // beginning se 3 bande ko chorhne ke baad insert karna hai
    // vec.insert(vec.begin()+3, 70) // 3 -> 3 bande chorhne ke baad insert karna hai, 70

    // Insert at last -> vec.push_back()

    // erase
    // erase 4th element (from beginning)
    // vec.erase(vec.begin()+3);

    // running code
    // inpvalueFromUser();
    // capacity();
    // multipleVect();

    return 0;
}
