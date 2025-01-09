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
    ListNode* deleteMiddle(ListNode* head) {
       if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = nullptr;

        // Traverse to find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        // Delete the middle node
        temp->next = slow->next;
        delete (slow);

        return head;
    }
};