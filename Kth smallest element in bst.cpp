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
class Solution {
public:
    int k;
    
    int inOrder(TreeNode* node){
        if(!node) return -1;
        int lval = inOrder(node->left);
        if(lval != -1) return lval;
        if(--k == 0){
            return node->val;
        }
        int rval = inOrder(node->right);
        if(rval != -1) return rval;
        return -1;
    };
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        return inOrder(root);
    }
};
