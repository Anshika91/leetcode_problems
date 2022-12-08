class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        if(root == NULL) {
            return v;
        }
        TreeNode *p = root;
        s.push(p);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.push_back(p->val);
            if(p->right != NULL) {
                s.push(p->right);
            }
            if(p->left != NULL) {
                s.push(p->left);
            }
        } 
        return v;
    }
};
