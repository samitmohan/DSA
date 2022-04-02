// https://leetcode.com/problems/middle-of-the-linked-list/

// Return mid of the node, incase 2 nodes -> return the second node.
// input [1->2->3->4->5]; output = [3->4->5]
// input [1->2->3->4->5-6]; output = [4->5-6] (2 mid notes (3,4) return 4)

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
    int size;
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

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Main Program -> runs on floyd cycle algorithm.
    void middle()
    {
        // special case, if empty
        if (head == nullptr)
        {
            // return head; (for leetcode)
            return;
        }
        // for middle pointer = we'll use floyd cycle detection algorithm
        // 2x and 1x speed
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // return slow
        // in leetcode, return slow works, here we have make slow = head, and then display to print the answer
        head = slow;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkedList *l1 = new LinkedList();
    l1->addLast(1);
    l1->addLast(2);
    l1->addLast(3);
    l1->addLast(4);
    l1->display();
    cout << "\n";
    l1->middle();
    l1->display();

    return 0;
}
