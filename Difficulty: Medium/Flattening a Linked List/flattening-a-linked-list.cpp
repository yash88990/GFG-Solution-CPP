/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/
class Solution {
public:
    // Merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        // Base cases
        if (!a) return b;
        if (!b) return a;

        // Pick the smaller node
        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // Remove 'next' links
        return result;
    }

    // Flatten the linked list
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;

        // Recursively flatten the next list
        root->next = flatten(root->next);

        // Merge current list with the flattened next list
        root = merge(root, root->next);

        return root;
    }
};
