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
 ListNode*getkthnode( ListNode*temp,int k)
 {
    k--;
    while(temp!=NULL && k>0)
    {
        temp=temp->next;
        k--;
    }
    return temp;
 }
     ListNode* reverse( ListNode*head)
     {
         ListNode*prev=NULL;
          ListNode*curr=head;
          while(curr!=NULL)
          {
             ListNode*front=curr->next;
             curr->next=prev;
             prev=curr;
             curr=front;
          }
          return prev;
     }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
         ListNode*prevnode=NULL;
        while(temp!=NULL)
        {
             ListNode* kthnode=getkthnode(temp,k);
              if(kthnode==NULL)
              {
                if(prevnode!=NULL)
                prevnode->next=temp;
                break;
              }
               ListNode*nextnode=kthnode->next;
               kthnode->next=NULL;
               reverse(temp);
               if(temp==head)
               {
                head=kthnode;
               }
               else
               {
                prevnode->next=kthnode;
               }
               prevnode=temp;
               temp=nextnode;
        }
        return head;
    }
};