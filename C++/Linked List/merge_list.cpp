// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {
        // 2 linked lists with heads.
        // 1-> 5-> 7-> 10
        // 2-> 3-> 6
        // base cases
        if (head1 == nullptr)
        {
            return head2;
        }
        if (head2 == nullptr)
        {
            return head1;
        }

        // recursive case
        ListNode *temp;

        // check length
        // head1 is smaller
        if (head1->val < head2->val)
        {
            temp = head1;
            temp->next = mergeTwoLists(head1->next, head2);
        }
        else
        {
            // head2 is smaller
            temp = head2;
            temp->next = mergeTwoLists(head1, head2->next);
        }
        return temp;
    }
};
