// Split linked list in parts: https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        vector<ListNode *> ans;

        if (len <= k)
        {
            for (int i = 0; i < k; i++)
            {
                if (head)
                {
                    ans.push_back(head);
                    temp = head;
                    head = head->next;
                    temp->next = NULL;
                }
                else
                    ans.push_back(head);
            }
        }
        else
        {
            int c = len / k;
            int rem = len % k;
            temp = head;
            while (temp)
            {
                ans.push_back(temp);
                int i = 0;
                while (i < c - 1)
                {
                    temp = temp->next;
                    i++;
                }
                if (rem)
                {
                    temp = temp->next;
                    rem--;
                }
                head = temp->next;
                temp->next = NULL;
                temp = head;
            }
        }

        return ans;
    }
};