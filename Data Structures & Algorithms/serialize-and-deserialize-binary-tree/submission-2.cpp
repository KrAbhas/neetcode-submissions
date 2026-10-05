class Codec {
public:

    void serialize_dfs(TreeNode* root, string& s) {

        if (!root) {
            s += "n|";
            return;
        }

        s += to_string(root->val);
        s += "|";

        serialize_dfs(root->left, s);
        serialize_dfs(root->right, s);
    }

    TreeNode* des_dfs(string& data, int& ctr) {

        if (data[ctr] == 'n') {
            ctr += 2;
            return nullptr;
        }

        int sign = 1;

        if (data[ctr] == '-') {
            sign = -1;
            ctr++;
        }

        int num = 0;

        while (data[ctr] != '|') {
            num = num * 10 + (data[ctr] - '0');
            ctr++;
        }

        num *= sign;

        ctr++; // skip '|'

        TreeNode* node = new TreeNode(num);

        node->left = des_dfs(data, ctr);
        node->right = des_dfs(data, ctr);

        return node;
    }

    string serialize(TreeNode* root) {

        string s;
        s.reserve(100000);

        serialize_dfs(root, s);

        return s;
    }

    TreeNode* deserialize(string data) {

        int ctr = 0;

        return des_dfs(data, ctr);
    }
};