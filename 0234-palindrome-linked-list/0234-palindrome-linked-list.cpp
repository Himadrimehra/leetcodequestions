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
 ListNode*reverse(ListNode*head)
 {
    ListNode* prev=NULL;
    ListNode* curr= head;
    while(curr!=NULL)
    {
        ListNode* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
 }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newhead=reverse(slow->next);
        ListNode*t1=head;
        ListNode*t2=newhead;
        while(t2!=NULL)
        {
            if(t1->val!=t2->val)
            {
                reverse(newhead);
                return false;
            }
            t1=t1->next;
            t2=t2->next;
        }
         reverse(newhead);
        return true;
    }
};