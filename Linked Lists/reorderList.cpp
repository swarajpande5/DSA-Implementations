// Reorder list: https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) 
    {
        // Edge cases
        if(!head || !head->next || !head->next->next)
            return;
        
        stack<ListNode*> st;
        ListNode* curr = head;
        int size = 0;
        
        // Push all nodes to a stack
        while(curr != NULL)
        {
            st.push(curr);
            size++;
            curr = curr -> next;
        }
        
        ListNode *ptr = head;
        
        // Between every 2 nodes insert the one in the top of the stack
        for(int j = 0; j < size / 2; j++)
        {
            ListNode *e = st.top();
            st.pop();
            
            e -> next = ptr -> next;
            ptr -> next = e;
            ptr = ptr -> next -> next;
        }
        
        ptr -> next = NULL;
    }
};