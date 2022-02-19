#include "bits/stdc++.h"
using namespace std;

class node
{
    public:
        int data;
        node* next;

    node(int val)
    {
        data = val;     //adding value to first node
        next = NULL;    //keeping null to first node address pointer
    }

};

void insertAtTail(node* &head, int val)     //inserting at last of node
{   
    node* n = new node(val);        //Creating new node which we have to insert

    if(head==NULL)                  //If there are no node linked list
    {
        head = n;
        return;
    }

    node* temp = head;          //Creating temporary node

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = n;
}

void display(node* head)                //displaying the node
{   
    node* temp = head;                  //creating the temporary node and pointing the value head

    while(temp != NULL)                //checking condition while
    {
        cout<<temp->data;
        cout<< " -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void removeDuplicate(node* &head)
{
    node* first = head;
    node* trip = first->next;


    while(trip != NULL)
    {
        if(first->data != trip->data)
        {
            first = trip;
            trip = trip->next;
        } 
        else
        {
            first->next = trip->next;
            delete trip;
            trip = first->next;
        }
    }
}


int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,2);
    display(head);

    removeDuplicate(head);
    display(head);
}