class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector(n, 0));
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                // cout << i << ", " << j << endl;
                if(i == 0){
                    dp[i][j] = triangle[i][j];
                }else{
                    //when j == 0, dp[i-1][j-1] is out of range
                    //when j == i, dp[i-1][j] is out of range
                    dp[i][j] = min(j > 0 ? dp[i-1][j-1] : INT_MAX, 
                                   j < i ? dp[i-1][j] : INT_MAX) + 
                                triangle[i][j];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
