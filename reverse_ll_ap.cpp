#include "bits/stdc++.h"
using namespace std;

class node
{

    public:
        node* next;
        int data;

    node(int val)
    {   
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)                 
    {
        head = n;
        return;
    }

    node* temp =head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// node* reverse(node* &head)
// {
//     node* prev = NULL;
//     node* curr = head;
//     node* next;


//     while(curr!=NULL)
//     {
//         next = curr->next;
        
//         curr->next = prev;

//         prev = curr;
//         curr = next;
        
//     }
//     return prev;
// }

// node* reverseRecursive(node* &head)
// {
//     if(head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     node* newhead = reverseRecursive(head->next);
    
//     head->next->next = head;
//     head->next = NULL;
//     return newhead;
// }

node* reverk(node* &head, int key)
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    int count=0;

    while(curr != NULL && count < key)
    {
        next = curr->next;
        curr->next=prev;

        prev = curr;
        curr=next;

        count++;
    }

    if(next != NULL)
    {
        head->next = reverk(next, key);
    }

    return prev;
}

void display(node* &head)              
{   
    node* temp = head;                  

    while(temp != NULL)                
    {
        cout<<temp->data;
        cout<< " -> ";
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
    insertAtTail(head,6);
    display(head);

    // node* newhead = reverse(head);
    // display(newhead);

    // node* newhead = reverseRecursive(head);
    // display(newhead);

    node* newhead = reverk(head,2);
    display(newhead);
}
