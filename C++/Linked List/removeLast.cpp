#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

class Node
{
public:
    int value;
    Node *next;

    // Constructor

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

// LinkedList

class LL
{
public:
    Node *head, *tail;
    int size = 0;

    // Constructor

    LL()
    {
        // initially
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void removeLast()
    {
        // if size 0, nothing removed.
        if (size == 0)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        if (size == 1)
        {
            // only 1 element present
            // decrement size if you're removing
            size--;
            head = nullptr;
            tail = nullptr;
            return;
        }
        // if more than 1 element in linked list. (first size--)
        /*
            [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
            Removing element? Make 3k = NULL, and shift TAIL to 20.
            Now address of 30 (last (3k) = removed) 
            New tail = Node having value 20.
        */
        size--;
        // use a dummy variable p
        Node *temp = head;
        // till it reaches 3k
        while (temp->next != tail)
        {
            // keep iterating
            temp = temp->next;
        }
        temp->next = nullptr;
        // tail still has address of removed element
        // shift tail to prevs element
        tail = temp;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL *l2 = new LL();
    l2->removeLast();
    return 0;
}
