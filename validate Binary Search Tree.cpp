class Solution {
public:
    bool isValidBST(TreeNode* root, int& minv, int& maxv) {
        if(!root) return true;
        if(!root->left && !root->right){
            minv = maxv = root->val;
            return true;
        }else if(root->left && root->right){
            int minl = INT_MAX, maxl = INT_MIN;
            //if subtree is invalid, return immediately!!
            if(!isValidBST(root->left, minl, maxl)) return false;
            if(maxl >= root->val) return false;
            
            int minr = INT_MAX, maxr = INT_MIN;
            if(!isValidBST(root->right, minr, maxr)) return false;
            if(minr <= root->val) return false;
            
            minv = minl;
            maxv = maxr;
            
            return true;
        }else if(!root->right){
            //left subtree is not empty
            int minl = INT_MAX, maxl = INT_MIN;
            if(!isValidBST(root->left, minl, maxl)) return false;
            if(maxl >= root->val) return false;
            maxv = root->val;
            minv = minl;
            return true;
        }else/* if(!root->left)*/{
            //right subtree is not empty
            int minr = INT_MAX, maxr = INT_MIN;
            if(!isValidBST(root->right, minr, maxr)) return false;
            if(minr <= root->val) return false;
            minv = root->val;
            maxv = maxr;
            return true;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        int rootmin = INT_MAX, rootmax = INT_MIN;
        return isValidBST(root, rootmin, rootmax);
    }
};
