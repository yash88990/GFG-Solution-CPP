//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
// Trie Node Definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
};

bool wordBreak(string &s, vector<string> &dictionary) {
    int n = s.size();
    
    // Build Trie from dictionary
    Trie trie;
    for (auto &word : dictionary) trie.insert(word);
    
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(0);  // Start BFS from index 0

    while (!q.empty()) {
        int start = q.front();
        q.pop();

        if (visited[start]) continue; // Avoid redundant processing
        visited[start] = true;

        TrieNode* node = trie.root;
        for (int end = start; end < n; end++) {
            char c = s[end];
            if (!node->children.count(c)) break;  // No match found

            node = node->children[c];

            if (node->isEnd) {  // Found a valid word
                if (end + 1 == n) return true;  // Reached end of string
                q.push(end + 1);
            }
        }
    }
    return false;
}



};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends