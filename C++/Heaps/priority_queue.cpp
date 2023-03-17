#include <bits/stdc++.h>
using namespace std;

void implementation()
{
    cout << "Using PQ" << endl;

    // max heap by default
    priority_queue<int> pq;
    pq.push(4);
    pq.push(6);
    pq.push(10);
    pq.push(1);

    cout << "Element at top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top : " << pq.top() << endl;
    cout << "Size : " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "PQ is empty" << endl;
    }
    else
    {
        cout << "PQ is not empty" << endl;
    }

    cout << "Minimum Heap" << endl;

    // for minimium heap.
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(6);
    minheap.push(10);
    minheap.push(1);
    cout << "Element at top : " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at top : " << minheap.top() << endl;
    cout << "Size : " << minheap.size() << endl;
    if (minheap.empty())
    {
        cout << "Min Heap is empty" << endl;
    }
    else
    {
        cout << "Min Heap is not empty" << endl;
    }
}

// Real world example

class student
{
public:
    string name;
    int roll;
    int marks;
    student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
    student()
    {
    }
};
class comparator
{
public:
    bool operator()(student &s1, student &s2)
    {
        return s1.marks < s2.marks;
    }
};

int main()
{

    priority_queue<student, vector<student>, comparator> pq3;
    pq3.push({"Ram", 30, 95});
    pq3.push({"Amit", 6, 85});
    pq3.push({"Shyam", 35, 92});
    pq3.push({"Vivek", 37, 86});
    while (pq3.size() != 0)
    {
        student rem = pq3.top();
        pq3.pop();
        cout << rem.name << " " << rem.marks << " " << rem.roll << "\n";
    }

    return 0;
}