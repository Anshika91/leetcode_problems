class Solution {
public:
    void dfs(vector<vector<int>>& graph, int cur, vector<int>& path, vector<vector<int>>& paths){
        int n = graph.size();
        
        if(cur == n-1){
            paths.push_back(path);
        }else{
            for(int nei : graph[cur]){
                path.push_back(nei);
                dfs(graph, nei, path, paths);
                path.pop_back();
            }
        }
    };
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> paths;
        
        dfs(graph, 0, path, paths);
        
        return paths;
    }
};
