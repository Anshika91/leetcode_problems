class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        helper(root, m, res);
        return res;
    }
    string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) 
    {
        if (!node) return "#";
        string str = to_string(node->val) + "," + helper(node->left, m, res) + "," + helper(node->right, m, res);
        if (m[str] == 1) res.push_back(node);
        ++m[str];
        return str;
    }
};
