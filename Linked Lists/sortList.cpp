// Sort list: https://leetcode.com/problems/sort-list/
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

// Merge sort technique T.C: O(nlogn) 
class Solution 
{
public:
    
    // Function to find middle node of linked list, using hare and tortoise problem
    void findmid(ListNode *curr, ListNode **first, ListNode **second)
    {
        ListNode *slow = curr;
        ListNode *fast = curr -> next;
        
        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        *first = curr;
        *second = slow -> next;
        slow -> next = NULL;
    }
    
    // Function used to merge first and second pointer
    ListNode *merge(ListNode *first, ListNode *second)
    {
        ListNode *ans = NULL;
        
        if(first == NULL)
            return second;
        
        if(second == NULL)
            return first;
        
        if(first -> val <= second -> val)
        {
            ans = first;
            ans -> next = merge(first -> next, second);
        }
        else
        {
            ans = second;
            ans -> next = merge(first, second -> next);
        }
        
        return ans;
    }
    
    // Function to divide the linked list into half parts, later merges them
    void mergesorting(ListNode **head)
    {
        ListNode *curr = *head;
        ListNode *first;
        ListNode *second;
        
        if(curr == NULL || curr -> next == NULL)
            return;
        
        findmid(curr, &first, &second);
        mergesorting(&first);
        mergesorting(&second);
        
        *head = merge(first, second);
    }
    
    
    ListNode* sortList(ListNode* head) 
    {
        mergesorting(&head);
        return head;
    }
};