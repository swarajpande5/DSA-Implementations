// Reverse linked list 2: https://leetcode.com/problems/reverse-linked-list-ii/
// https://leetcode.com/problems/reverse-linked-list-ii/discuss/2311084/JavaC%2B%2B-Tried-to-Explain-every-step

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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *dummy = new ListNode(0); 
        dummy -> next = head; 
        
        // Initializing prev pointer on dummy node
        ListNode *prev = dummy; 
        
        // Adjusting the prev pointer on it's actual index
        for(int i = 0; i < left - 1; i++)
            prev = prev -> next; 
        
        ListNode *curr = prev -> next; 
        
        for(int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr -> next; 
            curr -> next = forw -> next; 
            forw -> next = prev -> next; 
            prev -> next = forw;
        }
        
        return dummy -> next;
    }
};