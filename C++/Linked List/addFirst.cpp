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

    void addFirst(int value)
    {
        Node *node = new Node(value);
        // head tail = null for now, 25 created.
        // if size = 0
        if (size == 0)
        {
            // doesn't matter if you enter from last or first
            addLast(value);
            return;
        }
        // if size != 0 (addFirst(30))
        // node consisting 30 created, address = null, shoule be behind 25 (node)
        // node ke next me head.
        node->next = head; // instead of null, it consists of address of head (25)
        // now head = node (new head = 30)
        head = node;
        size++;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL *l2 = new LL();
    l2->addFirst(25);
    l2->addFirst(30);
    l2->addFirst(17);

    return 0;
}
