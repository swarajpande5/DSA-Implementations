// Reverse Nodes in k-Group : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Alter of above solution
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

// Recursive solution
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        
        ListNode *kSizeCheck = head;
        
        for(int i = 0; i < k; i++)
        {
            if(kSizeCheck == NULL)
                return head;
            
            kSizeCheck = kSizeCheck -> next;
        }
        
        int count = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(curr && count < k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next)
            head -> next = reverseKGroup(next, k);
        
        return prev;
    }
};

// Iterative Solution
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || k == 1) 
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;

        ListNode *curr, *nex, *pre;
        curr = nex = pre = dummy;

        int count = 0;
        while(curr -> next != NULL)
        {
            curr = curr -> next;
            count++;
        }

        while(count >= k)
        {
            curr = pre -> next;
            nex = curr -> next;

            for(int i = 1; i < k; i++)
            {
                curr -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = curr -> next;
            }

            pre = curr;
            count -= k;
        }
        return dummy -> next;
    }
};

// Alternative Iterative Solution
class SolutionAlter 
{
private:
    int getLengthOfList(ListNode *head)
    {
        ListNode *ptr = head;
        int count = 0;
        while(ptr)
        {
            count++;
            ptr = ptr -> next;
        }
        
        return count;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        
        int len = getLengthOfList(head);
        
        if(len < k)
            return head;
    
        int groups = len / k;
        
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode *start = dummy;
        ListNode *pre, *rem, *next;
        
        for(int i = 0; i < groups; i++)
        {
            pre = NULL;
            rem = head;
            for(int j = 0; j < k; j++)
            {
                next = head -> next;
                head -> next = pre;
                pre = head;
                head = next;
            }
            
            start -> next = pre;
            rem -> next = head;
            start = rem;
        }
        
        return dummy -> next;
    }
};