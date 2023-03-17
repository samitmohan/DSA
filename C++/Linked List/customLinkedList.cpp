#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/design-linked-list/ *Medium lowest acceptance rate question*
// Personal Linked List (addFirst, addLast, removeFirst, removeLast, display)

// Node Class = data, address of next (pointer)
class Node
{
public:
    int data;
    Node *next;

    // Constructor

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked List Class = head, tail, size

class LL
{
public:
    int size = 0;
    Node *head;
    Node *tail;

    // Constructor
    LL()
    {
        // Initially
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    // Add First

    void addFirst(int data)
    {
        // new "first" object of class Node is created.
        Node *first = new Node(data);
        if (size == 0)
        {
            // both will point to the same thing.
            head = first;
            tail = first;
        }
        else
        {
            // main logic
            // address of first = head & update new head = first
            first->next = head;
            head = first;
        }
        // increment size after addition of node
        size++;
    }

    void addLast(int data)
    {
        Node *last = new Node(data);
        if (size == 0)
        {
            // addFirst(data);
            // OR
            head = last;
            tail = last;
        }
        else
        {
            // main logic
            // address of tail = last & update new tail = last.
            tail->next = last;
            tail = last;
        }
        size++;
    }
    // Remove First

    void removeFirst()
    {
        if (size == 0)
        {
            cout << "Linked List is empty";
            return;
        }
        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        else
        {
            // shift head to head.next (new head)
            head = head->next;
            size--;
            // [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
            // [HEAD] 20 (3k) -> 30 (NULL) [TAIl]
        }
    }

    // Remove Last

    void removeLast()
    {
        if (size == 0)
        {
            cout << "Linked List is empty";
            return;
        }
        if (size == 1)
        {
            size--;
            head = nullptr;
            tail = nullptr;
            return;
        }
        else
        {
            size--;
            // dummy variable (starting from head)
            Node *temp = head;
            while (temp->next != tail)
            {
                // keep iterating
                temp = temp->next;
            }
            // when reached the last address = delete it (nullptr)
            temp->next = nullptr;
            // shift the new tail.
            tail = temp;
            // [HEAD] 10 (2k) -> 20 (3k) -> 30 (NULL) [TAIL]
            // Removing element? Make 3k = NULL, and shift TAIL to 20.
        }
    }

    // Get ith node.

    int get_ith(int index)
    {
        int count = 0;
        // dummy variable
        Node *current = head;
        // iterate through the list
        while (current != nullptr)
        {
            if (count == index)
            {
                // return data
                return current->data;
            }
            count++;
            // keep iterating
            current = current->next;
        }
        return -1;
    }

    // Deleting ith node

    void deleteAtindex(int index)
    {
        // special cases.
        if (index < 0 || index > size)
        {
            cout << "Invalid arguement";
        }
        else if (index == 0)
        {
            removeFirst();
        }
        else if (index == size - 1)
        {
            removeLast();
        }
        else
        {
            Node *temp = head;
            // iterate through the linked list, go to index - 1 position.
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            // directly link to the next to next node. (so next node(ith node) gets unlinked/removed)
            temp->next = temp->next->next;
            size--;
        }
    }

    // Adding ith node.

    void addAtIndex(int data, int index)
    {
        // special cases.
        if (index < 0 || index > size)
        {
            cout << "Invalid argument";
        }
        else if (index == 0)
        {
            addFirst(data);
        }
        else if (index == size)
        {
            addLast(data);
        }
        else
        {
            Node *add = new Node(data);
            // go through list till you reach index - 1 posn. temp -> temp.next (temp address = ith index address now)
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            // main logic
            // new node address = temp address
            // temp address = node
            //     node(add)
            //    /        \
            // temp ---- temp->next

            // add.address = temp.address | temp.address = add.
            add->next = temp->next;
            temp->next = add;
            size++;
        }
    }

    // Display

    void display()
    {
        // iterate from head to tail and print (using temp/dummy variable (i))
        Node *i = head;
        while (i != nullptr)
        {
            int c = 0;
            cout << i->data << " ";
            // i++;
            i = i->next;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL *l1 = new LL();
    l1->addFirst(40);
    l1->addFirst(30);
    l1->addFirst(20);
    l1->addFirst(10);
    l1->addLast(35);
    l1->display();
    cout << "\n";
    l1->removeFirst();
    l1->display(); // 20 30 40 35
    cout << "\n";
    l1->removeLast();
    l1->display(); // 20 30 40
    cout << "\n";
    cout << "Size : " << l1->size << endl;
    cout << l1->get_ith(1); // 30
    cout << "\n";
    l1->display();        // 20 30 40
    l1->deleteAtindex(1); // removes 30
    cout << "\n";
    l1->display(); // 20 40
    l1->addAtIndex(55, 2);
    cout << "\n";
    l1->display(); // 20 40 55k
    l1->addAtIndex(100, 2);
    cout << "\n";
    l1->display(); // 20 40 100 55

    return 0;
}
