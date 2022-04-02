#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/palindrome-linked-list/

// Check whether Linked List is a palindrome or not.
// [1->2->2-1] : true. [1-2] : false

/* ---Documentation---
    Main Idea -> Using the fast slow (floyd) analogy -> find the middle node [1->2->3->2->1] (3)
    Reverse all elements after the middle node. [1->2->3<-2<-1]
    Compare Head and Tail node. If they both point to same = Palindrome.
*/

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
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Reverse

    Node *reverse(Node *head)
    {
        Node *current = head;
        Node *previous = nullptr;
        Node *forward = head;

        while (current != nullptr)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }

    // Palindrome
    bool isPalindrome()
    {
        // Middle (floyd)
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // head = slow // slow = middle node.
        Node *rev = reverse(slow);
        // till it reaches mid node (nullptr)
        while (rev != nullptr && head != nullptr)
        {
            // if data of both is same ? palindrome : not palindrome
            if (rev->data != head->data)
            {
                return false;
            }
            // else it's a palindrome, keep iterating and checking for other elements
            rev = rev->next;
            head = head->next;
        }
        return true;
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
    l1->addLast(2);
    l1->addLast(1);
    l1->display();
    cout << "\n";
    cout << l1->isPalindrome(); // 1

    return 0;
}
