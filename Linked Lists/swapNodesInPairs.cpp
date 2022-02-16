// Swap nodes in pairs: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        ListNode *curr = head;

        tail -> next = head;

        while(curr && curr -> next)
        {
            ListNode *nextptr = curr -> next -> next;
            tail -> next = curr -> next;
            curr -> next -> next = curr;

            tail = curr;
            tail -> next = nextptr;
            curr = nextptr;
        }

        head = dummy -> next;
        delete dummy;
        return head;
    }
};

// Recursive solution
class Solution2
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode* temp;
        temp = head -> next;

        head -> next = swapPairs(head -> next -> next);

        temp -> next = head;

        return temp;
    }
};

