#include"bits/stdc++.h"
using namespace std;

class node
{
    public:
    int data;
    node* prev;
    node* next;

    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{

    if(head == NULL)
    {
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp ->next = n;
    n->prev = temp;
}

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);

    n->next = n;
    if(head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void display(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data;
        cout<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);

    display(head);

    insertAtHead(head,0);
    display(head);

}