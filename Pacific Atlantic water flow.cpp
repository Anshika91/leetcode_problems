class Solution {
public:

    vector<vector<int>>result;
    int n;
    int m;
    
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int prev_val){
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<prev_val or ocean[i][j]){
            return;
        }
        ocean[i][j] = true;
        dfs(i-1,j,matrix,ocean,matrix[i][j]);
        dfs(i+1,j,matrix,ocean,matrix[i][j]);
        dfs(i,j-1,matrix,ocean,matrix[i][j]);
        dfs(i,j+1,matrix,ocean,matrix[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(not matrix.size() or not matrix[0].size()){
            return result;
        }
        n = matrix.size();
        m = matrix[0].size();
        
        vector<vector<bool>> pacific( n , vector<bool> (m, false));
        vector<vector<bool>> atlantic( n , vector<bool> (m, false));
        
        for(int i = 0; i < n;i++){
            dfs(i,0,matrix,pacific,INT_MIN);
            dfs(i,m-1,matrix,atlantic,INT_MIN);
        }
        
        for(int j = 0; j < m ; j++){
            dfs(0,j,matrix,pacific,INT_MIN);
            dfs(n-1,j,matrix,atlantic,INT_MIN);
        }
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back(vector<int>{i,j});
                }
            }
        }
        return result;
    }
};
