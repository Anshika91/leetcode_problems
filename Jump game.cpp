class Solution {
public:
    bool canJump(vector<int>& nums) {
        map<int, vector<int>> graph;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            // for(int j = max(0, i-nums[i]); j <= min(n-1, i+nums[i]); j++){
            for(int j = i; j <= min(n-1, i+nums[i]); j++){
                graph[i].push_back(j);
            }
        }
        
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            
            for(int next : graph[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        
        return visited[n-1];
    }
};
