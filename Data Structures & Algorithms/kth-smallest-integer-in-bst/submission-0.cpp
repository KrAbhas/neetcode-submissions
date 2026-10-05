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

class Solution {
public:
    int p;
    TreeNode* kth(TreeNode* root) {
        if (!root) return root;
        TreeNode *a, *b;
        a = kth(root->left);
        p--;
        if (p == 0)
            return root;
        b = kth(root->right);
        return a? a: b;
    }
    int kthSmallest(TreeNode* root, int k) {
        p = k;
        return kth(root)->val;
    }
};
