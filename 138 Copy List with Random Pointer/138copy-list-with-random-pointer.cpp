/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (original != NULL) {
            original->next = original->next->next;
            if (copy->next != NULL)
                copy->next = copy->next->next;
            else
                copy->next = NULL;
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};
