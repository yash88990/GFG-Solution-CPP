/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;                    // or some sentinel < 1 since node->data ≥ 1
        Node* cur = root;
        while (cur) {
            if (cur->data == k) {
                // perfect match is the best possible
                return k;
            }
            if (cur->data < k) {
                // cur->data is a candidate floor; record and try to find a larger one on the right
                ans = cur->data;
                cur = cur->right;
            } else {
                // cur->data > k: discard this node and everything in its right subtree
                cur = cur->left;
            }
        }
        return ans;
    }
};
