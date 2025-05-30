/*
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        Node *tail = head;

        // Find the last node
        while (tail->next) {
            tail = tail->next;
        }

        // Make the list circular
        tail->next = head;
        head->prev = tail;

        // Move head and tail by the given position
        for (int count = 1; count <= p; count++) {
            head = head->next;
            tail = tail->next;
        }

        // Break the circular connection
        tail->next = nullptr;
        head->prev = nullptr;

        return head;
    }
};