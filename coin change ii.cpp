class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //amount's range: [0,5000]
        vector<int> dp(5001, 0);
        
        dp[0] = 1;
        
        for(int i = n-1; i >= 0; i--){
            for(int sum = coins[i]; sum <= amount; sum++){
                dp[sum] += dp[sum-coins[i]];
            }
        }
        
        return dp[amount];
    }
};
