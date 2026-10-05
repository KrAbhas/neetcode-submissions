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
1. we keep the numbers separted by a delimeter '|' and for null we put n

approach: reading the values, leaving out delieters and considering nulls,
 we can easily construct the tree and how its usually done
*/

class Codec {
public:
    void serialize_dfs(TreeNode* root, stringstream &ss) {
        if (!root) {
            ss << "n|";
            return;
        }
        ss << to_string(root->val);
        ss << "|";
        serialize_dfs(root->left, ss);
        serialize_dfs(root->right, ss);
    }

    TreeNode* des_dfs(string data, int& ctr) {
        if (ctr >= data.length()) return nullptr;
        if (data[ctr] == 'n') {
            ctr += 2;
            return nullptr;
        }
        string ss;
        do {
            ss += data[ctr];
        } while(data[++ctr] != '|');
        ctr++;
        int num = stoi(ss);
        TreeNode* cur = new TreeNode(num);
        cur->left = des_dfs(data, ctr);
        cur->right = des_dfs(data, ctr);
        return cur;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize_dfs(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ctr = 0;
        TreeNode* root = des_dfs(data, ctr);
        return root;
    }
};
