#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;

// we can also do stack<string> or stack<char> or stack<datatype>
// how to do this in our own customStack? Using a template
stack<int> s1;

// template can be of any name. template<typename x> (string or char or any data type)
template <typename k>

class customStack
{
public:
    int defaultSize = 10;
    // replace int with k everywhere you want a return type of k.
    k *arr;
    int peek;

    // Constructor
    customStack()
    {
        arr = new k[defaultSize];
        peek = -1;
    }

    k *resize()
    {
        k *newArray = new k[defaultSize * 2];
        defaultSize *= 2;
        for (int i = 0; i <= peek; i++)
        {
            newArray[i] = arr[i];
        }
        return newArray;
    }

    void push(k value)
    {
        if (peek + 1 == defaultSize)
        {
            arr = resize();
        }
        peek = peek + 1;
        arr[peek] = value;
    }

    k pop()
    {
        if (peek == -1)
        {
            cout << "Stack is empty"
                 << "\n";
            return EXIT_FAILURE;
        }
        k ans = arr[peek];
        peek = peek - 1;
        return ans;
    }

    int size()
    {
        return peek + 1;
    }

    k top()
    {
        if (peek == -1)
        {
            cout << "Stack is empty"
                 << "\n";
            return EXIT_FAILURE;
        }
        return arr[peek];
    }
};

int main()
{
    // now we can use customStack<string> or customStack<char>
    customStack<int> s1;

}
