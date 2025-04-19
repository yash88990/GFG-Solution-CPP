//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    struct TrieNode {
        TrieNode* children[2] = {nullptr, nullptr};
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int maxXorWithTrie(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->children[opposite]) {
                maxXor |= (1 << i);
                node = node->children[opposite];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

public:
    int maxXor(vector<int>& arr) {
        int result = 0;
        insert(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            result = max(result, maxXorWithTrie(arr[i]));
            insert(arr[i]);
        }

        return result;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends