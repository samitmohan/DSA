#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>

using namespace std;
typedef long long ll;

// STL -> Algorithms and Containers
// Algorithm -> Binary Search, Sort/Swap, Upper/Lower bound, Min/Max, Rotate/Reverse
// Containers -> Array, Vector, Deque, List, Stack, Queue, Priority Queue, Set, Map(unordered+ordered), Multiset, Pairs

// Containers

// Difference between push_back and emplace_back -> push_back makes a copy where as emplace_back passes the original value

// Vectors -> Dynamic Arrays

//  vector<int> v; // size can vary
//     int n; // number of elements you want (size)
//     cin >> n;
//     fr(0,n){ //
//     	int x; // elements intake.
//     	cin >> x;
//     	v.pb(x); // with push_back you can put elements in the list. (list+=[number])
//     }

int vec(vector<int> &A)
{

    // A.size() // size of vector
    // A.front(), A.back(), A.at(index) // to print first, last and index i element

    vector<int> v(5, 100); // {100, 100, 100, 100, 100}
    for (auto elem : v)
    {
        cout << elem << " ";
    }

    for (auto elem : A)
    {
        // printing a vector
        // cout << elem;
    }
    // Sorting
    sort(A.begin(), A.end()); // O(NlogN)
    // Printing the sorted vec
    for (auto elem : A)
    {
        cout << elem << " ";
    }

    cout << "\n";
    // 1,4,10,12,22
    // Binary Search O(logn)
    bool present = binary_search(A.begin(), A.end(), 4); // true(1)
    // present  = binary_search(A.begin(), A.end(), 2); // false(2)
    // cout << present << endl;

    // Finding the first occurrence of a number greater or equal to X or strictly greater than X
    // Lower bound and upper bound
    // removing last number -> v.pop_back();
    // Adding elements to vector -> push_back

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // 1,4,10,12,22,100,100,100,123

    // Lower bound and upper bounder -> Only when vector is sorted
    // Need to find an iterator which points to lower bound (first occurrence) of 100 (will be 5th index(the first 100)) >=
    // vector<int>::iterator = low--- instead of this we'll use auto it
    auto it = lower_bound(A.begin(), A.end(), 100);
    // Need to find an iterator which points to upper bound (first occurrence) of 100 (will be 123 [strictly greater than 100]) >
    auto it2 = upper_bound(A.begin(), A.end(), 100);

    cout << *it << " " << *it2 << " "
         << "\n";
    cout << it2 - it << endl; // 3 (gives the index after subtraction)

    // Erases the entire vector = {0,0,0,0}
    // A.clear();

    // Swapping
    vector<int> v1 = {10, 20};
    vector<int> v2 = {30, 40};
    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}

    // printing swap part
    for (auto elem : v1)
    {
        // cout << "V1 : " << elem << ", ";
    }
    cout << endl;
    for (auto elem : v2)
    {
        // cout << "V2 : " << elem << ", ";
    }

    // You can make vector of pairs also, vector<int,pair<int,int>> = {1,{1,2}};

    return 0;
}

// Unique Element Store -> Set
// Sets (We want some DS in which we can randomly insert elements and also perform queries without sorting it)
// Unordered Set -> not sorted, rest everything is the same.

// works on the concept of binary search trees.

int sets(set<int> &S)
{
    // Inserting any number in a set
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);
    // it will already be sorted (powerful than vector)
    // printing the set
    for (auto elem : S)
    {
        // -10,-1,1,2,10,12
        cout << elem << " ";
    }
    cout << "\n";
    // finding an element
    auto it = S.find(-1); // points to -1
    // if some element not present, return S.end() (null value)

    if (it == S.end())
    {
        // cout << "Not Present! \n";
    }
    else
    {
        // cout << "Present! \n";
        // cout << *it << endl;
    }
    S.erase(S.begin()); // deletes first element
    S.count(5);         // checks if 5 is present or not

    // Lower and Upper bounds in Sets (since its already sorted we dont need to do S.begin(), S.end())
    auto it2 = S.lower_bound(-1); // >=
    auto it3 = S.upper_bound(0);  // >
    // should print -1 (lower bound) and 1(upper bound strictly greater than 0)
    cout << *it2 << " " << *it3 << endl;

    // If upper bound not present
    auto it4 = S.upper_bound(100);
    cout << *it4 << " "; // prints 0 bcs not found -> it4 == S.end() not found

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    // This is the syntax
    auto it = S.lower_bound(2);

    auto it = S.upper_bound(3);

    return 0;
}

// Maps (Dictionaries) Key Value pair, one point only points to 1 thing.
// complexity -> O(logN), for unordered map -> O(1)

// Multimap -> everything same as map, only it can store multiple keys
// Unordered map -> same as unordered set

int maps(map<int, int> &M)
{
    M[1] = 100;
    M[2] = -1;
    M[3] = 200;
    map<char, int> count;
    string x = "samit mohan";

    for (char c : x)
    {
        count[c]++;
    }
    cout << count['a'] << " " << endl;

    map<int, string> m;
    m[1] = "Samit"; // 1 = key, Samit = value
    m[2] = "Mohan";

    m[10] = "Sam";
    // anotehr way to insert

    m.insert({5, "Charlie"});
    // Will always print in a sorted way, if you need unsorted -> Use unordered_map
    for (auto i : m)
    {
        cout << i.first << endl;  // key print (1,2,10)
        cout << i.second << endl; // value print (Samit, Mohan, Sam)
    }

    // To find something

    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << endl;
    }

    // pairs inside a map
    map<pair<int, int>, int> mpp;

    mpp[{2, 3}] = 10; // {2,3} pair = key, value = 10
    {
        {1, 2} {2, 4} {
            3, 1
        }
    }

    for (auto elem : mpp)
    {
        cout << elem.first << " " << elem.second << endl;
    }
    cout << mpp[1]; // prints 2
    cout << mpp[5]; // prints 0, since it does not exists

    // Finding a value
    auto it = mpp.find(3); // points to the position where 3 is found
    cout << *(it).second;

    // lower_bound and upper_bound works exactly in the
    // same way as explained in the other video

    // This is the syntax
    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above

    return 0;
}

// Pairs
// why we use pairs : for relationship of two datatypes at the same time. Instead of changing them both individually, we can do it at once while using pairs

int pairs(pair<int, int> &P)
{
    // prints first and the second part (1,3)

    cout << P.first << " " << P.second << endl;

    // Pair inside Pair
    pair<int, pair<int, int>> p = {1, {3, 4}};
    // prints 1 4 3
    cout << p.first << " " << p.second.second << " " << p.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}}; // Can store array too
    // Prints 5
    cout << arr[1].second;

    return 0;
}

// Deques -> doubly ended queue (can insert/remove/push/pop from both ends)

int deques(deque<int> &dq)
{
    dq.push_back(1);   // {1};
    dq.push_front(5);  // {5,1}
    dq.pop_back();     // {5}
    dq.push_back(100); //{5,100}
    dq.pop_front();    // {100}
    for (auto elem : dq)
    {
        cout << elem << " ";
    }

    // rest functions same as vector
    // begin, end, rbegin, front, end, rend, clear, insert, size, swap, at(index)

    return 0;
}

// Stacks (last in first out)

int stacks(stack<int> &st)
{:208
    // pushing a value
    st.push(10); // {10}
    st.push(20); // {20,10} Kitaab ke upar ek aur kitaab.
    st.push(30); // {30,20,10}
    // st.top() -> gives the top element
    cout << st.top() << endl; // 30
    st.pop();                 // top element goes off, now -> {20,10}
    cout << st.top() << endl; // 20
    cout << st.size();        // 2 {20,10}

    // cout << st.empty(); // empties the stack

    // Swapping of stacks -> same as vectors
    stack<int> st1, st2;
    st1.swap(st2);

    return 0;
}

// Queue -> first in first out (ATM line)
int queues(queue<int> &q)
{
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.push(4); // {1,2,4}
    q.pop();   // {2,4} , 1 removed

    cout << q.front() << endl; // First element : 2
    cout << q.back() << endl;  // Last element : 4

    q.back() += 5; // adds 5 to the back element = 4+5
    cout << q.back();

    return 0;
}

// Priority Queue -> first element of the queue is the greatest of
// all elements in the queue and elements are in non increasing order

int PQ(priority_queue<int> &pq)
{
    pq.push(5);       // {5}
    pq.push(2);       // {5,2}
    pq.push(8);       // {8,5,2} -> largest number -> 8, so priority given
    cout << pq.top(); // 8
    cout << endl;
    // pq.top() will always get you the highest number in the Queue
    pq.pop(); // Now PQ -> {5,2}

    // printing stack/queue/pq

    int n = pq.size();
    for (int i = 0; i < n; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

//---------------------------------------------------------------------------

// STL Algorithms

// binary_search(vec.begin(), vec.end(), number);
// lower_bound(vec.begin(), vec.end(), number);
// upper_bound(vec.begin(), vec.end(), number);
// int a = 4;
// int b = 6;
// max(a,b) min(a,b) swap(a,b)
// string pal = "samit"
// reverse(pal.begin(), pal.end()); // timas
// sort -> intro sort -> quick, heap, insertion. sort(v.begin(), v.end());

rotate(vec.begin(), v.begin() + 1, vec.end()); // start, number of times you wanna rotate[mid], end

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> A = {10, 12, 1, 4, 22};
    // vec(A);

    set<int> S = {10, 12};
    // sets(S);

    map<int, int> M;
    maps(M);

    pair<int, int> P = {1, 3};
    // pairs(P);

    deque<int> dq = {};
    // deques(dq);

    stack<int> st;
    // stacks(st);

    queue<int> q;
    // queues(q);

    priority_queue<int> pq;
    //PQ(pq);
}
