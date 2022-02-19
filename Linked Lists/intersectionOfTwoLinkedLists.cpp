// Intersection of two linked lists:    https://leetcode.com/problems/intersection-of-two-linked-lists/
//                                      https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *currA = headA;
        ListNode *currB = headB;

        while (currA != currB)
        {
            if (currA)
                currA = currA->next;
            else
                currA = headB;

            if (currB)
                currB = currB->next;
            else
                currB = headA;
        }

        return currA;
    }
};