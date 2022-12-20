class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for(int i = n-1; i >= 0; --i){
            for(int j = i+1; j <= n; ++j){
                // cout << i << ", " << j << ", " << s.substr(i, j-i) << endl;
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(i, j-i)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};
