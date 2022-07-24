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

int len(node *head)
{
    int l = 0;
    node *temp = head;

    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
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

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;

    while (pos--)
    {
        temp1 = temp1->next;
    }

    node *temp2 = head2;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int intersectionPoint(node *&head1, node *&head2)
{
    int l1 = len(head1);
    int l2 = len(head2);
    int diff;

    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {
        diff = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (diff)
    {
        ptr1 = ptr1->next;

        if (ptr1 == NULL)
        {
            return -1;
        }
        diff--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);

    insertAtTail(head2, 8);
    insertAtTail(head2, 7);

    intersect(head1, head2, 5);
    display(head1);
    display(head2);
    cout << intersectionPoint(head1, head2);
}