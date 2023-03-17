// https://leetcode.com/problems/linked-list-cycle-ii/

// Hashing
/* ---Documentation---
    Using a hashmap (unordered_map) which keeps track of the node and the frequency.
    Using a dummy node, which keeps iterating till the end of the linked list, keep adding dummy to the map.
    if (map[dummy] > 1) = if frequency of any element > 1 (it is repeating = loop found.)
    return dummy (node)
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> map;
        // dummy node
        ListNode *temp = head;

        while (temp != nullptr)
        {
            // freq add
            map[temp]++;
            // if duplicate
            if (map[temp] > 1)
            {
                // loop found.
                break;
            }
            // iterate
            temp = temp->next;
        }
        return temp;
    }
};

// Floyd Cycle Detection.

/* ---Documentation---
    To detect if there is a loop in the linked list.
    [10] -> [20] -> [30] -> [10] (again) ? return true : return false

    Race. 2 Pointers. Fast and Slow.
    Speed of fast = 2x
    Speed of slow = x (normal pace)
    At some point in the race, fast pointer will surpass / meet slow pointer (if it does -> true, else -> false)
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 2 pointers
        ListNode *fast = head;
        ListNode *slow = head;
        // temp ptr for ans
        ListNode *temp = head;
        // iterating.
        while (fast != nullptr && fast->next != nullptr)
        {
            // one runs at 2x speed
            fast = fast->next->next;
            // other runs at normal speed
            slow = slow->next;
            // if any of them meet at any point of race -> cycle found.
            if (fast == slow)
            {
                // meeting point met.
                break;
            }

            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            // node where they are met (temp and slow)
            return temp;
        }
        // no cycle
        return nullptr;
    }
};
