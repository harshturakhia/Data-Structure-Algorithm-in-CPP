#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int X)
    {
        data = X;
        next = NULL;
    }
};

struct node *buildList(int size)
{
    int val;
    cin >> val;

    node *head = new node(val);
    node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new node(val);
        tail = tail->next;
    }
    return head;
}

void printList(node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
private:
    node *reverse(node *head)
    {

        node *curr = head;
        node *prev = NULL;
        node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(struct node *&head, struct node *&tail, int val)
    {

        node *temp = new Node(val);
        // empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    struct node *add(struct node *first, struct node *second)
    {
        int carry = 0;

        node *ansHead = NULL;
        node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {

            int val1 = 0;
            if (first != NULL)
                val1 = first->data;

            int val2 = 0;
            if (second != NULL)
                val2 = second->data;

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            // create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }
        return ansHead;
    }

public:
    struct Node *addTwoLists(struct node *first, struct node *second)
    {
        // step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);

        // step2 - add 2 LL
        Node *ans = add(first, second);

        // step 3
        ans = reverse(ans);

        return ans;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;

        cin >> n;
        node *first = buildList(n);

        cin >> m;
        node *second = buildList(m);

        Solution ob;
        node *result = ob.addTwoLists(first, second);

        printList(result);
    }

    return 0;
}
