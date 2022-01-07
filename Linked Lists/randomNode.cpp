// Linked List Random Node: 

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
    // Vector to store all the linked list node's value
    vector<int> values;
    
    Solution(ListNode* head) 
    {
        while(head)
        {
            values.push_back(head -> val);
            head = head -> next;
        }
    }
    
    // BRUTE FORCE SOLUTION - USES O(N) SPACE COMPLEXITY
    int getRandom() 
    {
        // We first generate a random number using rand() between 0 and RAND_MAX
        // then we take its modulo with linked list size, so the range becomes 0 to n - 1
        // finally we return the value.
        
        return values[rand() % values.size()];
    }
};

class Solution2 
{
public:
    ListNode *head;
    
    Solution2(ListNode* head) 
    {
        this -> head = head;
    }
    
    // RESERVOIR SAMPLING - SPACE COMPLEXITY = O(1)
    int getRandom() 
    {
        int index = 1;
        int result = 0;
        ListNode *curr = head;
        
        while(curr)
        {
            if(rand() % index == 0)
                result = curr -> val;
        
            index++;
            curr = curr -> next;
        }
        
        return result;
    }
};