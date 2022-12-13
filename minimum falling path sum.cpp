class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(N+2, vector<int>(N+2, INT_MAX));
        
        //dp: wrap A with a margin of width 1
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i+1][j+1] = A[i][j];
            }
        }
        
        //skip last row
        for(int row = N-1; row >= 1; row--){ //[0,N-2]+1
            for(int col = 1; col <= N; col++){ //[0,N-1]+1
                dp[row][col] += min({dp[row+1][col-1], dp[row+1][col], dp[row+1][col+1]});
            }
        }
        
        return *min_element(dp[1].begin(), dp[1].end());
    }
};
