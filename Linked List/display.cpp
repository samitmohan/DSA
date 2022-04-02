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

    // Display Elements
    void display()
    {
        // iterate from head to tail and print (using a dummy variable)
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "\n";
            temp = temp->next;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL *l2 = new LL();
    l2->display();
    return 0;
}
