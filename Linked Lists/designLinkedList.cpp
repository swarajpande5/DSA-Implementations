// Design linked list: https://leetcode.com/problems/design-linked-list/

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList
{

    int size = 0;
    Node *head = new Node(0);

public:
    MyLinkedList()
    {
    }

    int get(int index)
    {

        if (index >= size)
            return -1;
        Node *temp = head->next;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val)
    {

        Node *temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }

    void addAtTail(int val)
    {

        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val)
    {

        if (index > size)
            return;

        Node *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        Node *temp = curr->next;
        curr->next = new Node(val);
        curr->next->next = temp;
        size++;
    }

    void deleteAtIndex(int index)
    {

        if (index >= size)
            return;

        Node *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        Node *temp = curr->next;
        curr->next = temp->next;

        temp->next = NULL;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */