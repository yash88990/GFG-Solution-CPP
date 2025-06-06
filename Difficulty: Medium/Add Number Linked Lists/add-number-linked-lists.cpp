//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;
        }
        return prev;
        
    }
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        //reverse the linnked list
        num1 = reverse(num1);
        num2 = reverse(num2);
        int carry = 0 ;
        Node* curr = NULL;
        while(num1 != NULL || num2 != NULL || carry != 0){
            int val1 =(num1 != NULL) ? num1->data : 0;
            int val2 = (num2 != NULL )? num2->data : 0;
            int sum  = val1 + val2 + carry;
            carry = sum/10;
            
            Node* temp = new Node(sum % 10);
            temp->next = curr;
            curr = temp;
            if(num1 != NULL) num1= num1->next;
            if(num2 != NULL) num2 = num2->next;
        }
        while(curr != NULL && curr->data == 0 ) {
            curr = curr->next;
        }
        return curr;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends