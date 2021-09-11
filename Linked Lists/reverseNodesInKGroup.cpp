// Reverse Nodes in k-Group : https://leetcode.com/problems/reverse-nodes-in-k-group/
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