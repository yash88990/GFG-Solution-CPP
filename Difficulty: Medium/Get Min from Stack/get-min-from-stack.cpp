//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    stack<int>s , minstack;
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        s.push(x);
        if(minstack.empty() || x <= minstack.top()){
            minstack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!s.empty()){
            if(s.top() == minstack.top()) minstack.pop();
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return s.empty() ? -1 : s.top();
        
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return minstack.empty() ? -1 : minstack.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends