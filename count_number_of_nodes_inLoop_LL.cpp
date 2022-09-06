int countNodesinLoop(struct Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            int count = 1;
            slow = slow->next;
            // we have to increase slow because slow is already pointed fast
            while (slow != fast)
            {
                count++;
                slow = slow->next;
            }

            return count;
        }
    }
    return 0; // if we found NULL then no cycle is present
}