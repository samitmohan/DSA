#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Empty linked list case
        if (head == NULL)
        {
            return NULL;
        }

        // curr pointer points to head
        ListNode *curr = head;
        // traverse list while curr != NULL && curr.next != NULL
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                // duplicate found
                // if you also want to delete it (to save memory blah)
                // store curr->next->next somewhere
                // ListNode *next_next = curr->next->next;
                // delete curr.next
                // ListNode *to_delete = curr->next;
                /// delete(to_delete)
                // break link
                // curr->next = next_next;

                // break the link
                curr->next = curr->next->next;
            }

            else
            {
                // keep traversing
                curr = curr->next;
            }
        }
        // return head
        return head;
    }
};
