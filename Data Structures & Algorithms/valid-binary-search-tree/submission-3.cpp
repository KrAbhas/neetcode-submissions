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

    int inf = 1e7;

    bool isValid(TreeNode* root, int lg, int rg) {
        if (!root) return true;
        if (root->val <= lg || root->val>=rg) return false;
        return isValid(root->left, lg, root->val) & isValid(root->right, root->val, rg);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, -inf, inf);
    }
};
