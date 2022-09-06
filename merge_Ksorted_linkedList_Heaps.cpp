class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                minHeap.push(arr[i]);
            }
        }

        Node<int> *head = NULL;
        Node<int> *tail = NULL;

        if (tail->next)
        {
            minHeap.push(tail->next);
        }

        while (minHeap.size() > 0)
        {
            Node<int> *temp = minHeap.top();
            minHeap.pop();

            if (head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};