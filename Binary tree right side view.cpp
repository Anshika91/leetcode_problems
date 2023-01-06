class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int level_size = q.size();
            int level_last;
            
            while(level_size--){
                TreeNode* cur = q.front(); q.pop();
                
                level_last = cur->val;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            ans.push_back(level_last);
        }
        
        return ans;
    }
};
