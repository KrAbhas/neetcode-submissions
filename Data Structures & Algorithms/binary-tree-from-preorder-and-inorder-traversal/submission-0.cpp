class Solution {

private:

unordered_map<int,int> pos;

TreeNode* ans;

TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int l, int r, int &k) {

if (k >= preorder.size()) return nullptr;

if (l > r) return nullptr;

TreeNode* node = new TreeNode();

node->val = preorder[k++];

if (l >= r + 1)

return node;

node->left = construct(preorder, inorder, l, pos[node->val] - 1, k);

node->right = construct(preorder, inorder, pos[node->val] + 1, r, k);

return node;

}

public:

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

for (int i = 0; i < inorder.size(); i++) {

pos[inorder[i]] = i;

}

int k = 0;

return construct(preorder, inorder, 0, inorder.size() - 1, k);

}

};