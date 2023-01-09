
class Codec {
public:
    template <typename Iter>
    std::string join(Iter begin, Iter end, std::string const& separator)
    {
        std::ostringstream result;
        result.precision(2); //for floating point
        if (begin != end)
            result << *begin++;
        while (begin != end)
            //std::fixed : for floating point
            result << std::fixed << separator << *begin++;
        return result.str();
    }
    
    std::vector<std::string> string_split(std::string str, std::string delimiter){
        size_t pos = 0;
        std::string token;
        std::vector<std::string> result;

        //Style 2, can deal with all tokens inside the while loop
        while(true){
            pos = str.find(delimiter);
            //works even if pos is string::npos
            token = str.substr(0, pos);
            result.push_back(token);
            if(pos == string::npos) break;
            //pos+1 equals to 0, so the line below can't handle this situation
            str.erase(0, pos+delimiter.length());
        }
        return result;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> tokens;
        
        TreeNode* cur;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            cur = q.front(); q.pop();
            
            if(cur != nullptr){
                tokens.push_back(to_string(cur->val));
                //we also visit children who are nullptr
                q.push(cur->left);
                q.push(cur->right);
            }else{
                tokens.push_back("null");
            }
        }
        
        return join(tokens.begin(), tokens.end(), ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = string_split(data, ",");
        int n = tokens.size();
        vector<TreeNode*> nodes(n);
        
        for(int i = 0; i < n; ++i){
            if(tokens[i] == "null"){
                nodes[i] = nullptr;
            }else{
                nodes[i] = new TreeNode(stoi(tokens[i]));
            }
        }
        
        //use bfs to reconstruct tree
        TreeNode* cur;
        int nodeCursor = 0;
        queue<TreeNode*> q;
        q.push(nodes[nodeCursor]);
        
        while(!q.empty()){
            int levelSize = q.size();
            
            //visit level by level
            while(levelSize-- > 0){
                cur = q.front(); q.pop();
                
                if(cur != nullptr){
                    cur->left = nodes[++nodeCursor];
                    cur->right = nodes[++nodeCursor];
                    
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        
        return nodes[0];
    }
};
