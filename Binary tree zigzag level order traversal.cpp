class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        stack<TreeNode*> stk, stk_next;
        TreeNode* cur;
        bool pos = true;
        
        stk.push(root);
        while(!stk.empty()){
            int levelSize = stk.size();
            vector<int> level(levelSize);
            bool next_pos = !pos;
            
            for(int i = 0; i < levelSize; ++i){
                cur = stk.top(); stk.pop();
                level[i] = cur->val;
                
                TreeNode* child1 = cur->left;
                TreeNode* child2 = cur->right;
                
                if(next_pos){
                    swap(child1, child2);
                }
                
                if(child1) stk_next.push(child1);
                if(child2) stk_next.push(child2);
                
            }
            
            swap(stk, stk_next);
            pos = next_pos;
            ans.push_back(level);
        }
        
        return ans;
    }
};
