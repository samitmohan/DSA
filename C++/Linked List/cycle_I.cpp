#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/linked-list-cycle/

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    int size = 0;
    Node *head;
    Node *tail;

    LinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addLast(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Main Program
    /* ---Documentation----
        To detect if there is a loop in the linked list. 
        [10] -> [20] -> [30] -> [10] (again) ? return true : return false

        Race. 2 Pointers. Fast and Slow. 
        Speed of fast = 2x
        Speed of slow = x (normal pace)
        At some point in the race, fast pointer will surpass / meet slow pointer (if it does -> true, else -> false)

    */
    bool hasCycle()
    {
        Node *fast = head;
        Node *slow = head;
        // while fast does not complete the race, keep iterating.
        while (fast != nullptr)
        {
            // 2x speed
            fast = fast->next->next;
            // normal speed
            slow = slow->next;
            // if they ever meet.
            if (fast == slow)
            {
                // loop found
                return true;
            }
        }
        // no loop
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkedList *l1 = new LinkedList();

    l1->addLast(10);
    l1->addLast(20);
    l1->addLast(30);
    l1->addLast(40);
    l1->addLast(50);
    l1->addLast(60);
    l1->addLast(70);
    l1->addLast(80);
    l1->addLast(90);
    l1->addLast(100);

    l1->display();
    cout << endl;

    // Loop.
    l1->head->next->next->next->next->next->next->next->next->next->next = l1->head->next->next->next;
    // Check.
    cout << l1->hasCycle(); // should print true (1)

    return 0;
}
