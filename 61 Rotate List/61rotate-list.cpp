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
  int findLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;

        int len = findLength(head);
        k = k % len;  
        if (k == 0) return head;

       
        ListNode* tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = head;

       
        int steps = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

       
        ListNode* newHead = newTail->next;
        newTail->next = NULL;  

        return newHead;
    }
};