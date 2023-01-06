class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int split = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        
        vector<int> linorder(inorder.begin(), inorder.begin()+split);
        vector<int> lpreorder(preorder.begin()+1, preorder.begin()+1+linorder.size());
        root->left = buildTree(lpreorder, linorder);
        
        vector<int> rpreorder(preorder.begin()+1+linorder.size(), preorder.end());
        vector<int> rinorder(inorder.begin()+split+1, inorder.end());
        root->right = buildTree(rpreorder, rinorder);
        
        return root;
    }
};
