/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
       if(!head || x <= 0){
           return head;
       }
       Node* curr = head;
       if(x == 1 ){
           Node* newHead = head->next;
           if(newHead){
               newHead->prev = NULL;
           }
           delete head;
           return newHead;
       }
       
       for(int i = 1 ; curr && i < x ; i++){
           curr = curr->next;
           
           
       }
       
       if(!curr)return head;
       
       if(curr->next){
           curr->next->prev = curr->prev;
       }
       if(curr->prev){
           curr->prev->next = curr->next;
       }
       delete curr;
       return head;
    }
};