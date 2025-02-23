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
    ListNode* removeElements(ListNode* head, int val) {
         ListNode* dummy = new ListNode(0); // Create a dummy node
        dummy->next = head; // Point dummy to head
        
        ListNode* temp = head;
        ListNode* prev = dummy; // Start from dummy node

        while (temp != nullptr) {
            if (temp->val == val) {
                prev->next = temp->next; // Skip the node
                delete temp; // Free memory
                temp = prev->next; // Move temp forward
            } else {
                prev = temp; // Move prev forward
                temp = temp->next; // Move temp forward
            }
        }

        head = dummy->next; // Update head to the real list
        delete dummy; // Free dummy node
        return head;
    }
};
    