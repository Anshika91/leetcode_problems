class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
    void dfs(TreeNode* root) {
        if(root == NULL) return ;
        dfs(root->left);
        result.push_back(root->val);
        dfs(root->right);
    }
};
