// Cycle detection: https://leetcode.com/problems/linked-list-cycle-ii/

/*
Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, then return null.
*/

/**
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 */

// Floyd's cycle detection algorithm

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Edge cases
        if(!head || !head -> next || !head -> next -> next)
            return NULL;
        
        ListNode *slow, *fast;
        slow = fast = head;

        while(fast -> next && fast -> next -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                break;
        }

        // If they are not on the same node
        if(fast != slow)
            return NULL;
        
        // Otherwise, we find the start of the loop
        slow = head;
        while(slow != fast)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }
};