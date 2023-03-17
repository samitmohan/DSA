// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

/* ---Documentation---
    1) Find length of both nodes headA and headB
    2) Difference of both nodes (let's say 2) -> Determines how fast does the node has to go as compared to the other head (normal speed)
        Just like Floyd Cycle Detection, one will run faster x amount of times than the other so that overall they both run at same pace.
    3) When they're running at same pace, keep moving until they both meet at some point. That point = intersection point.
    4) return headA or headB (since both are intersection points)
    
    length() = finds the length of node
    sizeManage = manages size by taking 2 paramets (head, difference b/w headA and headB)
*/

class Solution
{
public:
    // Finding length of the two nodes (headA and headB)
    int length(ListNode *head)
    {
        int answer = 0;
        while (head != nullptr)
        {
            head = head->next;
            answer++;
        }
        return answer;
    }

    // Managing Size (Floyd Technique -> But by how much is one node faster than other?)
    // sizeManage(head, difference by which head should be incremented)
    ListNode *sizeManage(ListNode *head, int count)
    {
        while (count > 0)
        {
            head = head->next;
            count--;
        }
        return head;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Length of both headA and headB
        int lenA = length(headA);
        int lenB = length(headB);
        // two cases (lenA > lenB || lenB > lenA)
        if (lenA > lenB)
        {
            // headA += difference between lenA and lenB
            headA = sizemanage(headA, lenA - lenB);
        }
        else if (lenB > lenA)
        {
            headB = sizeManage(headB, lenB - lenA);
        }

        // When they are equal -> Move them both at same pace until they meet.
        // Point of intersection -> Answer
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        // At this point, headA = headB so it doesn't matter as both are pointing to intersection point.
        return headA;
    }
};
