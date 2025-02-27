//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    unordered_map<int, int> inorderMap;

    Node* solve(vector<int> &inorder, vector<int> &postorder, int &postorderindex, int left, int right) {
        if (left > right) return NULL;

        int rootvalue = postorder[postorderindex--];
        Node* root = new Node(rootvalue);
        int inorderindex = inorderMap[rootvalue];

        root->right = solve(inorder, postorder, postorderindex, inorderindex + 1, right);
        root->left = solve(inorder, postorder, postorderindex, left, inorderindex - 1);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }

        int postorderindex = n - 1; // Start from last element
        return solve(inorder, postorder, postorderindex, 0, n - 1);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends