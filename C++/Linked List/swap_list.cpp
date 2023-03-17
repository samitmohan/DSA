// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k) 
    {
        // 2 pointer approach (both start at head)
        ListNode *left = head;
        ListNode *right = head;
        ListNode *curr = head;
        int counter = 1;
        while (curr != NULL)
        {
            if (counter < k)
            {
                // keep moving till you reach kth node from beginning
                left = left->next;
            }
            if (coutner > k)
            {
                // keep moving till you reach kth node from end
                right = right->next;
            }
            curr = curr->next;
            counter++;
        }
        // swap
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        return head;
    }
};