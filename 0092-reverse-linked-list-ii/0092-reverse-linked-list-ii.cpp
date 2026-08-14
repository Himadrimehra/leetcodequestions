class Solution {
public:

    ListNode* getrightnode(ListNode* head, int right)
    {
        ListNode* temp = head;

        for(int i = 1; i < right && temp != NULL; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* getleftnode(ListNode* head, int left)
    {
        ListNode* temp = head;

        for(int i = 1; i < left - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* stop = tail->next;

        while(curr != stop)
        {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(head == NULL || left == right)
            return head;

        ListNode* rightnode = getrightnode(head, right);

        if(rightnode == NULL)
            return head;

        ListNode* next = rightnode->next;

        // left = 1
        if(left == 1)
        {
            ListNode* newhead = reverse(head, rightnode);

            head->next = next;

            return newhead;
        }

        // left > 1
        ListNode* prev = getleftnode(head, left);

        if(prev == NULL || prev->next == NULL)
            return head;

        ListNode* leftnode = prev->next;

        ListNode* newhead = reverse(leftnode, rightnode);

        prev->next = newhead;
        leftnode->next = next;

        return head;
    }
};