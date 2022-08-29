// LRU Cache: https://leetcode.com/problems/lru-cache/

class Node 
{
public:
    int key;
    int val;

    Node *next;
    Node *prev; 
    
    Node(int _key, int _val)
    {
        key = _key;
        val = _val; 
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public: 
    Node *head;
    Node *tail; 
    
    DoublyLinkedList()
    {
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    // To add node at head
    void addNode(Node *newNode)
    {
        Node *temp = head -> next; 
        newNode -> next = temp; 
        newNode -> prev = head; 
        head -> next = newNode;
        temp -> prev = newNode;
    }
    
    // To delete any node present anywhere in the doubly linked list
    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode -> prev; 
        Node *delNext = delNode -> next; 
        
        delPrev -> next = delNext; 
        delNext -> prev = delPrev; 
        
    }
};

class LRUCache 
{
public:
    
    int cap; 
    unordered_map<int, Node *> mp;
    DoublyLinkedList *dll;
    
    LRUCache(int capacity) 
    {
        cap = capacity; 
        dll = new DoublyLinkedList();
    }
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            Node *resNode = mp[key]; 
            int res = resNode -> val; 
            
            mp.erase(key); 
            dll -> deleteNode(resNode);
            dll -> addNode(resNode); 
            
            mp[key] = dll -> head -> next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key) != mp.end())
        {
            Node *exist = mp[key]; 
            
            mp.erase(key);
            dll -> deleteNode(exist); 
        }
        
        if(mp.size() == cap)
        {
            mp.erase(dll -> tail -> prev -> key); 
            dll -> deleteNode(dll -> tail -> prev);
        }

        
        dll -> addNode(new Node(key, value)); 
        mp[key] = dll -> head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */