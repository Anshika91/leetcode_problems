class Solution {
public: 
    //initialize for leftmost leaf, 
    //we want the first node->val - last to be very large
    int last = INT_MIN/2;
    int ans = INT_MAX; //need to find min
    
    void inOrder(TreeNode* node){
        if(node->left) inOrder(node->left);
        ans = min(ans, node->val - last);
        last = node->val;
        if(node->right) inOrder(node->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        
        return ans;
    }
};
