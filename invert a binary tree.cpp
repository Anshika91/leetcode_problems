class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* p = root;
        if(root == NULL) {
            return NULL;
        }
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return p;
    }
};
