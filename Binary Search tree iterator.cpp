class BSTIterator {
public:
    vector<int> values;
    int pos;
    
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        values.push_back(node->val);
        inorder(node->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        pos = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return values[pos++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < values.size();
    }
};
