






Node* k_reverse(Node* head, int k)
{
    if(head== NULL)
    {
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int cnt = 0;

    while(curr != NULL && cnt != k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if(forward != NULL)
    {
    head->next = k_reverse(forward,k);
    }
    return prev;
}