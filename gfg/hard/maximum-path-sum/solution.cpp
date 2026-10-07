/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
public:

    int maxPathDown(Node* node, int &maxi) {
        if (node == NULL)
            return INT_MIN;

        // Leaf node
        if (node->left == NULL && node->right == NULL)
            return node->data;

        int left = maxPathDown(node->left, maxi);
        int right = maxPathDown(node->right, maxi);

        // If both children exist, we have a leaf-to-leaf path
        if (node->left != NULL && node->right != NULL) {
            maxi = max(maxi, left + node->data + right);

            return node->data + max(left, right);
        }

        // Only left child
        if (node->left != NULL)
            return node->data + left;

        // Only right child
        return node->data + right;
    }

    int maxPathSum(Node* root) {
        if (root == NULL)
            return -1;

        // Fewer than two leaves
        if (root->left == NULL && root->right == NULL)
            return -1;

        int maxi = INT_MIN;

        maxPathDown(root, maxi);

        // If no node had two children, there aren't two leaves
        if (maxi == INT_MIN)
            return -1;

        return maxi;
    }
};