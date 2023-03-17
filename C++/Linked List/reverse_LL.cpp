// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

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
    Node *head, *tail;

    LinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addLast(int data)
    {
        Node *last = new Node(data);
        if (size == 0)
        {
            head = last;
            tail = last;
        }
        else
        {
            tail->next = last;
            tail = last;
        }
        size++;
    }

    // Reverse Elements
    int reverse()
    {
        Node *current = head;
        Node *previous = nullptr;
        Node *forward = head;

        while (current != nullptr)
        {
            // nxt pointer = saves the address of curr pointer
            forward = current->next;
            // curr pointer = links to prevs pointer (reverse)
            current->next = previous;
            // iterate forward.
            previous = current;
            current = forward;
        }
        // return previous
        head = previous;
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
    l1->display();
    cout << endl;

    // After Reversing
    l1->reverse();
    l1->display();

    return 0;
}