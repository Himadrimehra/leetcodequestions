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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp;
        if(head==0)
        {
            return NULL;
        }
        else {
            ListNode* temp = head;
        
        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                // Skip the duplicate node
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next; // Remove the duplicate node
                delete duplicate; // Properly delete the duplicate node
            } else {
                temp = temp->next; // Move to the next node if no duplicate
            }
        }
        
        return head;
    }
        }
};