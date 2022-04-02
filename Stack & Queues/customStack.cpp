#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

/*  
    Implementing Stack without using STL.
    Operations = Push, Pop, Peek (Display the top element)
    Follows LIFO
*/

class customStack
{
public:
    // size (by default let's say it's 10 (10 elements can be inserted in stack))
    int defaultSize = 10;
    // to store elements
    int *arr;
    // top element
    int peek;

    // Constructor
    customStack()
    {
        arr = new int[defaultSize];
        // peek/top element = -1 (index = top element)
        peek = -1;
        // question -> what is peek + 1 (out of bound (all elements in stack filled))
    }

    // what if we want to enter more than 10 elements?
    // Overflow? To avoid -> make a function resize which doubles to default size value once overloaded.
    int *resize()
    {
        int *new_arr = new int[defaultSize * 2];
        defaultSize = defaultSize * 2;
        // insert all elements of og arr into the new arr (of double the size)
        // iterate till it reaches the top element
        for (int i = 0; i <= peek; i++)
        {
            new_arr[i] = arr[i];
        }
        return new_arr;
    }

    // Push operation
    int push(int value)
    {
        // if top element = size (index full.)
        if (peek + 1 == defaultSize)
        {
            // stack overflow
            // double the size of stack
            arr = resize();
        }
        // increment peek
        peek++;
        // update new peek
        arr[peek] = value;

        return 0;
    }

    // Pop
    int pop()
    {
        // if full
        if (peek == -1)
        {
            cout << "Stack is empty"
                 << "\n";
            return EXIT_FAILURE;
        }
        // else, ans = pop = peek element
        int ans = arr[peek];
        // decrement size
        peek--;
        return ans;
    }

    // Size

    int size()
    {
        // size = peek+1 (index + 1)
        return peek + 1;
    }

    // Top / Peek element (Look at the top element)

    int top()
    {
        if (peek == -1)
        {
            cout << "Stack is empty"
                 << "\n";
            return EXIT_FAILURE;
        }
        // can also do int ans = arr[peek] and return ans;
        return arr[peek];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    customStack s1;
    s1.push(10);
    s1.push(20);
    cout << s1.size() << "\n";
    cout << s1.top() << "\n";
    s1.push(100);
    cout << s1.size() << "\n";
    cout << s1.top() << "\n";
    s1.pop();
    cout << s1.top() << "\n";

    for (int i = 1; i <= 15; i++)
    {
        s1.push(i);
    }
    cout << s1.size() << "\n";
    s1.pop();
    cout << s1.size() << "\n";

    return 0;
}
