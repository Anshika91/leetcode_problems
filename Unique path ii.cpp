class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long> > grids(m+1, vector<long>(n+1));
        //padding to the top and left
        for(int i = 0; i < m+1; i++){
            grids[i][0] = 0;
        }
        for(int j = 0; j < n+1; j++){
            grids[0][j] = 0;
        }
        
        for(int diag = 0; diag <= (m-1) + (n-1); diag++){
            for(int i = max(0, diag-(n-1)), j = diag - i; i <= m-1 && j >= 0; i++, j--){
                if(obstacleGrid[i][j] == 1){
                    grids[i+1][j+1] = 0;
                }else if(i == 0 && j == 0){
                    grids[i+1][j+1] = 1;
                }else{
                    grids[i+1][j+1] = grids[i-1+1][j+1] + grids[i+1][j-1+1];
                }
            }
        }
   
        return grids[m-1+1][n-1+1];
    }
};
