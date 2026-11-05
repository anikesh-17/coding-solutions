/* Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int maxLevel(Node *root) {
        // code here
        if(root == NULL) return 0;
        int lh = maxLevel(root->left);
        int rh = maxLevel(root->right);
        return 1 + max(lh,rh);
    }
};
