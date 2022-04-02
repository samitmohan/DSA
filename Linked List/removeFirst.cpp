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

    void removeFirst()
    {
        if (size == 0)
        {
            cout << "Linked List is empty" << endl;
            // what if i want the value of the integer im removing.
            // i need the data of the person i'm removing.
            return;
        }
        if (size == 1)
        {
            // only one is there, no difference.
            size--;
            head = nullptr;
            tail = nullptr;
        }

        // More than one.
        size--;
        // [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
        // [HEAD] 20 (3k) -> 30 (NULL) [TAIl]

        // shift head to head.next
        head = head->next;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL *l2 = new LL();
    l2->removeFirst();
    return 0;
}
