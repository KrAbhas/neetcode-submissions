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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* tempa = lowestCommonAncestor(root->left, p, q);
        TreeNode* tempb = lowestCommonAncestor(root->right, p, q);
        if (tempa != nullptr && tempb != nullptr) return root;
        if (tempa != nullptr) return tempa;
        if (tempb != nullptr) return tempb;
        return nullptr;
    }
};
