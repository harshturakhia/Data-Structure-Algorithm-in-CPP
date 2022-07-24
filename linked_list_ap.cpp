#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;  // adding value to first node
        next = NULL; // keeping null to first node address pointer
    }
};

void insertAtTail(node *&head, int val) // inserting at last of node
{
    node *n = new node(val); // Creating new node which we have to insert

    if (head == NULL) // If there are no node linked list
    {
        head = n;
        return;
    }

    node *temp = head; // Creating temporary node

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val) // inserting at first of node
{
    node *n = new node(val);

    n->next = head; // n is pointing towards the first node
    head = n;
}

void display(node *head) // displaying the node
{
    node *temp = head; // creating the temporary node and pointing the value head

    while (temp != NULL) // checking condition while
    {
        cout << temp->data;
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void count(node *&head) // Order is O(n)
{
    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << endl
         << "Count : " << count;
}

void add(node *&head) // Order is O(n)
{
    node *temp = head;
    int sum = 0;

    while (temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    cout << endl
         << "Sum : " << sum << endl;
}

void maximum(node *&head)
{
    node *temp = head;
    int ans = INT_MIN;

    while (temp != NULL)
    {
        if (temp->data > ans)
        {
            ans = temp->data;
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Max : " << ans << endl;
}

int deletetion(node *head, int key)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;

    while (temp->next->data != key)
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

/*
void checkSort(node* &head)
{
    node* temp = head;
    int val = INT_MIN;

    while(temp != NULL)
    {
        if(temp->data < val)
        {
            cout<<"Node is sorted!"<<endl;
            val = temp->data;
            temp = temp->next;
        }
        else
        {
            cout<<"Node is not sorted!"<<endl;
            temp = temp->next;
        }
    }
}
*/

bool search(node *head, int key) // searching for any kind of element in node
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
    return 0;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);
    cout << search(head, 30);

    count(head);
    add(head);
    maximum(head);
    deletetion(head, 4);
    cout << "After Deletion : " << endl;
    display(head);
    deleteAtHead(head);
    cout << "After Deletion at head : " << endl;
    display(head);

    //   checkSort(head);
}
