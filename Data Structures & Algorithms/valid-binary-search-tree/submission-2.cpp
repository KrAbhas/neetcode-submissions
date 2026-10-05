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
private:
    bool status;
    pair<int,int> check(TreeNode* root) {
        if (!root) return {-INT_MAX, INT_MAX};
        pair<int,int> leftstate = check(root->left);
        pair<int,int> rightstate = check(root->right);
        if (leftstate.first >= root->val || rightstate.second <= root->val) 
            status = false;
        leftstate.first = max(leftstate.first, root->val);
        leftstate.second = min(leftstate.second, root->val);
        return {
            max(leftstate.first, rightstate.first),
            min(leftstate.second, rightstate.second)
        };
    }
public:
    bool isValidBST(TreeNode* root) {
        status = true;
        check(root);
        return status;
    }
};
