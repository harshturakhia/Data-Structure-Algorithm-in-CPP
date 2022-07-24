#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;

    head = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *&head, int key)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

void deletion(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next != NULL)
    {
        deleteAtHead(head);
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

node *recursiveReverse(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = recursiveReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reversekNodes(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;

        count++;
    }

    if (nextptr != NULL)
        head->next = reversekNodes(nextptr, k);

    return prevptr;
}

bool detectCycle(node *&head)
{

    node *slowptr = head;
    node *fastptr = head;

    while (fastptr != NULL && fastptr->next != NULL)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;

        if (fastptr == slowptr)
        {
            return true;
        }
    }
    return false;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

/*
void removeLoop(node* &head)
{
    node* temp = head
    while(temp < temp->next)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
*/
void removeCycle(node *&head)
{
    node *slowptr = head;
    node *fastptr = head;

    do
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    } while (slowptr != fastptr);

    fastptr = head;

    while (slowptr->next != fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    slowptr->next = NULL;
}

int lengths(node *head)
{
    int len = 0;
    node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node *kAppend(node *&head, int k)
{

    node *newHead;
    node *newTail;
    node *tail = head;

    int length = lengths(head);
    int count = 0;
    k = k % length;

    while (tail->next != NULL)
    {
        if (count == length - k)
        {
            newTail = tail;
        }

        if (count == length - k + 1)
        {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);

    display(head);

    // Reverse in iterative way
    //  node* newhead = reverse(head);
    //  display(newhead);

    // Reverse in recursive way
    // node* newhead = recursiveReverse(head);
    // display(newhead);

    // Reverse k nodes
    // int k = 2;
    // node* newhead = reversekNodes(head, k);
    // display(newhead);

    // cout << detectCycle(head) << endl;
    // makeCycle(head, 3);
    // cout << detectCycle(head) << endl;
    // removeCycle(head);
    // cout << detectCycle(head) << endl;

    // node *newhead = kAppend(head, 3);
    // display(head);

    evenAfterOdd(head);
    display(head);
    return 0;
}
