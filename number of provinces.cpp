class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> visited;
        int ret = 0;
        for(int i = 0 ; i < isConnected.size(); ++i){
            if(visited.find(i) == visited.end()){
                dfs(isConnected, visited, i);
                ret++;
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& isConnected, set<int> &visited, int i) {
        if(visited.find(i) != visited.end()) {
            return;
        }
        visited.insert(i);
        for(int j = 0; j < isConnected[i].size(); ++j){
            if(isConnected[i][j] == 1) {
                dfs(isConnected, visited, j);
            }
        }
    }
};
