// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int listLength = 0;
        ListNode *temp = head;
        // from the start
        ListNode *start = head;
        while (temp != NULL)
        {
            // count++
            listLength++;
            // whenever you reach kth element from start
            if (listLength == k)
            {
                // store value of it
                start = temp;
            }
            // keep iterating
            temp = temp->next;
        }
        // from the end
        // another variable end
        ListNode *end = head;
        // till you reach kth element from end
        for (int i = 1; i <= listLength - k; i++)
        {
            // keep iterating
            end = end->next;
        }
        // once you reach, swap values
        swap(start->val, end->val);
        return head;
    }
};
