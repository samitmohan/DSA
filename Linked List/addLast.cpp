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
    Note (int value)
    {
        this->value = value;
        this->next = nullptr;
    }

}

class Node
{
public:
    // value and address of next
    int value;
    // type of address of next person? node. address of node? pointer node (will initially have null)
    Node *next;

    // Constructor.
    // value is different from the Node value, this value is basically the value we take from the user (from main function)
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

// Our own Linked List.

class LL
{
public:
    // head, tail, size of linkedlist. (initally)
    Node *head;
    Node *tail;
    int size = 0;

    // Constructor

    LL()
    {
        // we wont use (this keyword) here because there is no parameter in LL. (we are not taking anything from main function to pass in this)
        size = 0;
        // Address of Last = Tail
        // Address of First = Head
        head = nullptr;
        tail = nullptr;
    }

    // Add element to last of linked list.
    void addLast(int value)
    {
        // New node object of class Node is created (value = 10)
        // head and tail will be the same if only 1 node is there
        Node *node = new Node(value);
        // if head = null & tail = null;
        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            // till now, head = some address (1K), tail = 1K. (SAME)
            // One more node to be added (value = 20, nullptr)
            // now head = 1K, tail = 3K (new address after adding new node)
            tail->next = node;
            tail = node;
        }
        // increment size after addition of node
        size++;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL *l1 = new LL();
    l1->addLast(10);
    l1->addLast(20);
    l1->addLast(15);

    return 0;
}
