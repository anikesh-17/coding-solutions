/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    bool isBalanced(Node* root) {
        // code here
        return dfsHeight(root) != -1;
    }
    int dfsHeight(Node* root){
        if(root == NULL) return 0;
        int lh = dfsHeight(root->left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1) return -1;
        if(abs(rh-lh) > 1) return -1;
        return 1 + max(lh, rh);
    }
};