#include <iostream>
#include <vector>
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

// 1st approach = reversing the LL
bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(node *head)
{
    node *temp = head;

    vector<int> arr;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}

// 2nd approach = reversing only after middle of LL

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

node *middleOfLinkedList(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(node *head)
{
    if (head->next == NULL)
        return true;

    // step 1 = fint middle
    node *middle = middleOfLinkedList(head);

    // step 2 = reverse LL after middle
    node *temp = middle->next;
    middle->next = reverse(temp);

    // step 3 = compare both half
    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    // step 4 = repeat step 2
    node *temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 0);

    display(head);

    cout << isPalindrome(head) << endl;
}
