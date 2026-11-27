/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void recurssion(Node *root, int level, vector<int> &res) {
      if (root == nullptr) return;
      if (res.size() == level) res.push_back(root->data);
      recurssion(root->right, level + 1, res);
      recurssion(root->left, level + 1, res);
    }
    vector<int> rightView(Node *root) {
      //  code here
      vector<int> res;
      recurssion(root, 0, res);
      return res;
    }
};