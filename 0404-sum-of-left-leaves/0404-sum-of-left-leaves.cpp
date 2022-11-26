class Solution {
public:
    int ans;
    
    void rSumOfLeftLeaves(TreeNode* node, bool isLeft){
        // cout << node->val << " " << isLeft << endl;
        if(node->left == NULL && node->right == NULL && isLeft){
            ans += node->val;
        }
        if(node->left){
            rSumOfLeftLeaves(node->left, true);
        }
        if(node->right){
            rSumOfLeftLeaves(node->right, false);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        
        ans = 0;
        rSumOfLeftLeaves(root, false);
        
        return ans;
    }
};