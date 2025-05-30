/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/


class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (!head || !head->next) return head;  // Handle empty or single node

        DLLNode* current = head;
        DLLNode* temp = nullptr;

        // Swap next and prev for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;  // Move to the next node (was previous before swap)
        }

        // After loop, temp points to the new head's prev
        if (temp != nullptr)
            head = temp->prev;

        return head;
    }
};
