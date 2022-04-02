#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

/*
Why do we use LL over arrays? Because LL are not contiguous. Better utlisation of memory takes place (insertion/deletion)
Complexity -> to search / find = O(N) (starts from first and iterates throughout)
              You can only access some element in a LL by following the links unlike in arrays where you can just do cout << arr[n] [No direct access]
           -> to insert / delete = O(N) constant time. (Better than arrays)


Each node stores a data and a pointer, pointing to the data of next node.
[Head] -> [10 | (100)] -> [20 | (104)] -> [30 | ()] [Tail]-> NULL
*/

class Node
{
public:
    // data and address of next of type Node
    int data;
    Node *next;

    // Constructor -> data is different from the Node data(int data), this data = the parameter we take from the user (main)
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked List.

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
        // Not using "this" as there is no parameter in LL constructor (Not taking anything from user in main function to pass)
        size = 0;
        // Address of Last = Tail (null initially)
        // Address of First = Head (null initially)
        head = nullptr;
        tail = nullptr;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // new linked list
    LL *l1 = new LL();

    return 0;
}