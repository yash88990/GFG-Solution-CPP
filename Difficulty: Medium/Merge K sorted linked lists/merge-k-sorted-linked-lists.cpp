//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
 
// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on data value
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Step 1: Push heads of all linked lists into the min-heap
    for (Node* list : arr) {
        if (list) minHeap.push(list);
    }

    Node* dummy = new Node(0); // Dummy node for result linked list
    Node* tail = dummy;

    // Step 2: Extract min and process
    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) {
            minHeap.push(smallest->next); // Push next node from the extracted list
        }
    }

    return dummy->next; // Head of the merged sorted linked list
}


};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends