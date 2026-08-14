/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* getthenode(int length, ListNode* head)
{
    ListNode* temp = head;
      length--;
    while(length > 0 && temp != NULL)
    {
        temp = temp->next;
        length--;
    }

    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* tail=head;
        int length=1;
        while(tail->next!=NULL)
        {
            tail=tail->next;
            length++;
        }
        ListNode* temp=head;
          k=k%length;
        if(k==0)
        {
            return head;
        }
        tail->next=head;
        ListNode* newtail=getthenode(length-k,head);
        head=newtail->next;
         newtail->next=NULL;
         return head;
    }
};