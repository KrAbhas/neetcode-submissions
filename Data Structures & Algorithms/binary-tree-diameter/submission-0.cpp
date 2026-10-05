/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
 approach: 
 1. we need to compute left and right depth of the node
 2. we can add and get to know the distance
 3. it can be done by inorder or any traversal

 invariance: since diameter is left_depth + right_depth + 1, we can calculate the dpeths
 */

class Solution {
private:
    int maxm = 0;
    int preorder(TreeNode* root) {
        if (root == nullptr) return 0;
        int a, b;
        a = preorder(root->left);
        b = preorder(root->right);
        maxm = max(maxm, a + b);
        return max(a, b) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        preorder(root);
        return maxm;
    }
};
