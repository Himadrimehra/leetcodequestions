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
    bool isPalindrome(ListNode* head) {
        ListNode*currnode,*nextnode,*slow,*fast,*prev,*temp;
             slow=fast=head;
             while(fast!=0&&fast->next!=0)
             {
                fast=fast->next->next;
                slow=slow->next;
             }
             if(fast!=0)
             {
                slow=slow->next;
             }
            prev=0;
            while(slow!=0&&slow->next!=0)
            {
                temp=slow->next;
                slow->next=prev;
                prev=slow;
                slow=temp;
            }
            if(slow!=0){
                slow->next=prev;
            }
            fast=head;
            while(slow!=0&&fast!=0)
            {
                if(slow->val!=fast->val)
                {
                    return false;
                }
                slow=slow->next;
                 fast=fast->next;
            }
            return true;

    }
};