#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
        head->prev = n;

    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;

    // cout << "NULL <- ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;

    head = head->next;
    head->prev = NULL;

    delete toDelete;
}

void deletion(node *&head, int pos)
{
    node *temp = head;
    int count = 1;

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

node *reverseDLL(node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *current = head;
    node *prev = NULL;
    node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;
        current->prev = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}

int main()
{
    node *head = NULL;

    insertAtHead(head, 20);
    insertAtHead(head, 10);

    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    display(head);

    deletion(head, 20);
    display(head);

    node *newhead = reverseDLL(head);
    display(newhead);
}