// Merge nodes in between zeros:    https://leetcode.com/problems/merge-nodes-in-between-zeros/
//                                  https://leetcode.com/problems/merge-nodes-in-between-zeros/discuss/1785026/Recursive-vs-Iterative-without-Dummy-oror-O(1)-Space-%2B-Intuition

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
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *ans = new ListNode(-1);
        ListNode *anscurr = ans;

        ListNode *curr = head->next;
        int currsum = 0;

        while (curr)
        {
            if (curr->val == 0)
            {
                ListNode *node = new ListNode(currsum);
                anscurr->next = node;
                anscurr = anscurr->next;
                currsum = 0;
            }

            currsum += curr->val;
            curr = curr->next;
        }

        return ans->next;
    }
};

// Efficient O(1) Space complexity solution
class Solution2
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head -> next;
        ListNode* start = head;

        while(start)
        {
            ListNode *end = start;
            int sum = 0;

            while(end -> val != 0)
            {
                sum += end -> val;
                end = end -> next;
            }

            start -> val = sum;
            start -> next = end -> next;
            start = start -> next;
        }

        return head;
    }
};