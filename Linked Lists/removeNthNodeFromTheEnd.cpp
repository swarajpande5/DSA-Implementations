// Remove Nth Node from the end of the list: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

/*
    We give a headstart to our fast pointer by n, and then 
    start slow and fast. By doing this, slow pointer will reach at
    the nth node from end, while fast reaches the end.
*/

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *fast = head, *slow = head;

        // Giving fast a headstart
        for(int i = 0; i < n; i++)
            fast = fast -> next;
        
        // If fast is already null, then node pointed by head is obviously the nth node from end
        // We simply return the next node to head, eliminating head.
        if(!fast)
            return head -> next;
        
        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow-> next;
        }

        // We eliminate the node pointed by slow
        slow -> next = slow -> next -> next;

        return head;
    }
};