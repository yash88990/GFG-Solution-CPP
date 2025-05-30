/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* newNode = new Node(data);
        Node* curr = head;
        
        for(int i = 0 ; i < pos ; i++){
            if(curr == NULL)return head;
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        if(curr->next != NULL){
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        return head;
    }
};