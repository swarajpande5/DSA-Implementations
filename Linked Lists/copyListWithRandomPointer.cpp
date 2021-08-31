// Deep copy a linked list with next and random pointer : https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution 
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *iter = head;
        Node *front = head;

        // Making copy of each node and linking them side by side
        while(iter != NULL)
        {
            front = iter -> next;
            
            Node *copy = new Node(iter -> val);
            iter -> next = copy;
            copy -> next = front;

            iter = front;
        }

        // Assigning random pointers for the copy nodes
        iter = head;
        while(iter != NULL)
        {
            if(iter -> random != NULL)
                iter -> next -> random = iter -> random -> next;

            iter = iter -> next -> next;
        }

        // Finally restoring the original list, and extracting the copy list
        iter = head;
        Node *newHeadPtr = new Node(0);
        Node *copy = newHeadPtr;

        while(iter != NULL)
        {
            front = iter -> next -> next;

            // extract the copy
            copy -> next = iter -> next;

            // restore the original list 
            iter -> next = front;

            copy = copy -> next;
            iter = front;
        }

        return newHeadPtr -> next;
    }
}