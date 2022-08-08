// Subtraction in Linked List: https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1

/* Structure of linked list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

void swapPointers(Node** a, Node** b)
{
    Node *t = *a;
    *a = *b;
    *b = t;
}

int length(Node *head)
{
    int len = 0;
    Node *curr = head;
    while(curr)
    {
        len++;
        curr = curr -> next;
    }
    
    return len;
}

bool isl2Greater(Node *l1, Node *l2)
{
    int n = length(l1);
    int m = length(l2);
    
    if(n > m)
        return false;
    else if(m > n)
        return true; 
    
    while(l1 && l2 && l1 -> data == l2 -> data)
    {
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    
    if(!l1 && !l2)
        return false;
    
    if(l1 -> data > l2 -> data)
        return false;
        
    return true;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt;
    
    while(curr)
    {
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1 && l1 -> data == 0)
        l1 = l1 -> next;
    while(l2 && l2 -> data == 0)
        l2 = l2 -> next;
        
    // Considering l1 to be greater in value than l2 
    if(isl2Greater(l1, l2))
        swapPointers(&l1, &l2);
    
    // Now subtracting 
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    Node *curr1 = l1;
    Node *curr2 = l2;
    
    while(curr1 && curr2)
    {
        curr1 -> data -= curr2 -> data;
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    
    // Normalizing negative numbers
    curr1 = l1;
    int c = 0;
    while(curr1)
    {
        curr1 -> data += c;
        
        if(curr1 -> data < 0)
        {
            curr1 -> data += 10;
            c = -1;
        }
        else 
            c = 0;
            
        curr1 = curr1 -> next;
    }
    
    l1 = reverse(l1);
    
    // Remove leading zeroes
    while(l1 && l1 -> data == 0)
        l1 = l1 -> next;
    
    if(!l1)
        return new Node(0);
    
    return l1;
}