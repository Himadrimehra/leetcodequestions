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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* temp=head;
        int count=0;
        while(count!=k)
        {
            count++;
            if(temp==NULL)
            {
                return head;
            }
            temp=temp->next;
        }
        ListNode* prevnode=reverseKGroup(temp,k);
         temp=head;
          count=0;
          while(count!=k)
          {
             ListNode*nextt=temp->next;
            temp->next=prevnode;
            prevnode=temp;
             temp=nextt;
             count++;
          }
          return prevnode;
    }
};