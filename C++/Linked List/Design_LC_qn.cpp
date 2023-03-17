// https://leetcode.com/problems/design-linked-list/ *Medium lowest acceptance rate question*
// Test cases are too strict, but this is a general idea of the code.

// Node Class = data, address of next (pointer)
class Node
{
public:
    int val;
    Node *next;

    // Constructor
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

// Linked List Class = head, tail, size

class MyLinkedList
{
public:
    int size = 0;
    Node *head, *tail;

    // Constructor
    MyLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        int count = 0;
        // dummy variable
        Node *current = head;
        // iterate through the list
        while (current != nullptr)
        {
            if (count == index)
            {
                // return value
                return current->val;
            }
            count++;
            // i++ or keep iterating
            current = current->next;
        }
        // if not found
        return -1;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val);
        if (size == 0)
        {
            // both will point to the same thing.
            head = node;
            tail = node;
        }
        else
        {
            // main logic
            // address of node = head & update new head = node
            node->next = head;
            head = node;
        }
        // increment size after addition of node
        size++;
    }

    void addAtTail(int val)
    {
        Node *node = new Node(val);
        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            // main logic
            // address of tail = nod & update new tail = node.
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        // special cases
        if (index < 0 || index > size)
        {
            cout << "Invalid arguemnt";
        }
        else if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else
        {
            Node *node = new Node(val);
            // go through list till you reach index - 1 posn. temp -> temp.next (temp address = index address now)
            Node *temp = head;
            for (int i = 0; i < (index - 1); i++)
            {
                temp = temp->next;
            }
            // main logic
            // new node address = temp address
            // temp address = node
            //     node
            //    /    \
            // temp --- temp->next
            node->next = temp->next;
            temp->next = node;
            size++;
        }
    }

    void removeAtHead()
    {
        if (size == 0)
        {
            cout << "Empty";
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
            // shift head to head.next (new head)
            head = head->next;
            size--;
        }
    }

    void removeAtTail()
    {
        if (size == 0)
        {
            cout << "Empty";
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
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            // when reached the last address = delete it (nullptr)
            temp->next = nullptr;
            // shift new tail
            tail = temp;
        }
    }

    void deleteAtIndex(int index)
    {
        // special cases
        if (index < 0 || index >= size)
        {
            cout << "Invalid arguement";
        }
        else if (index == 0)
        {
            removeAtHead();
        }
        else if (index == size - 1)
        {
            removeAtTail();
        }
        else
        {
            Node *temp = head;
            // iterate through the linked list, go to index - 1 position.
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            // directly link to next to next node (so next node(index node) gets unlinked/removed)
            temp->next = temp->next->next;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
