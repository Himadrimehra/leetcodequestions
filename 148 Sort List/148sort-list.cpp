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
     ListNode*mergetwolinkedlist(ListNode*l1,ListNode*l2)
     {
        ListNode*dummynode=new ListNode(-1);
        ListNode*temp=dummynode;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                temp->next=l1;
                l1=l1->next;
            }
            else 
            {
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
       if(l1!=NULL)
       {
        temp->next=l1;
       }
       else 
       {
        temp->next=l2;
       }
       return dummynode->next;
     }
     ListNode*findmiddle(ListNode*head)
     {
        ListNode*slow=head;
        ListNode*fast=head->next;
      while(fast != nullptr && fast->next != nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
     }
    ListNode* sortList(ListNode* head) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }    
     ListNode* middle =findmiddle(head);
      ListNode*right=middle->next;
       middle->next=nullptr;
        ListNode*left=head;
        left=sortList(left);
        right=sortList(right);
        return mergetwolinkedlist(left,right);
    }
};