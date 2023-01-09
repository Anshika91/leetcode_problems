class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pLevel = -1, qLevel = -1;
        
        queue<TreeNode*> bfsq;
        TreeNode* cur;
        int levelCount = 0;
        int level = 0;
        map<TreeNode*, TreeNode*> parents;
        
        bfsq.push(root);
        parents[root] = nullptr;
        levelCount++;
        
        while(!bfsq.empty()){
            // cout << level << " " << levelCount << endl;
            while(levelCount-- > 0){
                cur = bfsq.front(); bfsq.pop();
                if(cur == p){
                    pLevel = level;
                }
                if(cur == q){
                    qLevel = level;
                }
                if(cur->left){
                    bfsq.push(cur->left);
                    parents[cur->left] = cur;
                }
                if(cur->right){
                    bfsq.push(cur->right);
                    parents[cur->right] = cur;
                }
            }
            level++;
            levelCount = bfsq.size();
        }
        
        //lift the lower one to the same level
        while(qLevel > pLevel){
            qLevel--;
            q = parents[q];
        }
        
        while(pLevel > qLevel){
            pLevel--;
            p = parents[p];
        }
        
        //now p and q are at same level
        if(p == q) return p;
        
        while(p != q){
            p = parents[p];
            q = parents[q];
        }        
        return p;
    }
};
