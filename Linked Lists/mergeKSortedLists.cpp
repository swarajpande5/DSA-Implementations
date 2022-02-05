// Merge k sorted lists: https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
// Priority queue approach: O(nlogn)
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return NULL;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];
            while(head != NULL)
            {
                pq.push(head -> val);
                head = head -> next;
            }
        }

        ListNode *start = NULL;
        ListNode *end = NULL;

        while(!pq.empty())
        {
            if(start == NULL)
            {
                start = new ListNode(pq.top());
                end = start; 
                pq.pop();
            }

            else 
            {
                end -> next = new ListNode(pq.top());
                pq.pop();
                end = end -> next;
            }
        }

        return start;
    }
};
*/

// Divide and Conquer: O(nlogk)
class Solution
{
public:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if(!a)
            return b;
        
        if(!b)
            return a;
        
        ListNode *ans = NULL;

        if(a -> val <= b -> val)
        {
            ans = a;
            ans -> next = merge(a -> next, b);
        }
        else 
        {
            ans = b;
            ans -> next = merge(a, b -> next);
        }

        return ans;
    }

    ListNode* mergeK(vector<ListNode*>& lists, int k)
    {
        while(k != 0)
        {
            int i = 0;
            int j = k;

            while(i < j)
            {
                lists[i] = merge(lists[i], lists[j]);
                i++;
                j--;

                if(i >= j)
                    k = j;
            }
        }

        return lists[0];
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return NULL;
        
        if(lists.size() == 1)
            return lists[0];
        
        ListNode* ans = mergeK(lists, lists.size() - 1);
        return ans;
    }
};