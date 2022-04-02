// https://leetcode.com/problems/palindrome-linked-list/

// Check whether Linked List is a palindrome or not.
// [1->2->2-1] : true. [1-2] : false

/* ---Documentation---
    Main Idea -> Using the fast slow (floyd) analogy -> find the middle node [1->2->3->2->1] (3)
    Reverse all elements after the middle node. [1->2->3<-2<-1]
    Compare reverse data and head data. If they both are same ? Palindrome + (keep iterating to check elements) : Not Palindrome (break)
*/

class Solution
{
public:
    // Reverse
    // Node function reverse = to use it later
    Node *reverse(Node *head)
    {
        Node *current = head;
        Node *prevs = nullptr;
        Node *nxt = head;
        while (current != nullptr)
        {
            nxt = current->next;
            current->next = prevs;
            prevs = current;
            current = nxt;
        }
        return prevs;
    }

    bool isPalindrome(Node *head)
    {
        // Middle using Floyd Cycle Detection
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // return slow (Middle Node)

        // Main Program
        // Reverse elements from middle node. [1->2->3<-2<-1]
        Node *rev = reverse(slow);
        // Iterate until you reach NULL (Both rev and head)
        while (rev != nullptr && head != nullptr)
        {
            // rev value at any point = head value ? Palindrome : not Palindrome
            if (rev->val != head->val)
            {
                // not a palindrome
                return false;
            }
            // else it's true. Keep iterating to check for other elements.
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};