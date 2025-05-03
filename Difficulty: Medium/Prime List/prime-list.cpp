//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    Node *primeList(Node *head) {
        // Step 1: Sieve of Eratosthenes
        const int LIMIT = 10050;
        vector<bool> isPrime(LIMIT, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < LIMIT; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < LIMIT; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Step 2: Traverse and update the list
        Node* curr = head;
        while (curr != NULL) {
            int val = curr->val;
            if (isPrime[val]) {
                curr = curr->next;
                continue;
            }
            
            // Check both lower and higher to find nearest prime
            int low = val - 1;
            int high = val + 1;
            while (low >= 2 && !isPrime[low]) --low;
            while (high < LIMIT && !isPrime[high]) ++high;
            
            // Choose closer one, prefer smaller if equal
            if (low >= 2 && (val - low <= high - val)) {
                curr->val = low;
            } else {
                curr->val = high;
            }
            
            curr = curr->next;
        }
        return head;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends