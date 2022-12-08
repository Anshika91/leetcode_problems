class Solution {
public:
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        dfs(root->right);
        result.push_back(root->val);
    }
};
