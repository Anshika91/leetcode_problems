class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<int> dp(n+1, 0);
        int dp_is1_js1;
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                int tmp = dp[j];
                if(i == 0 && j == 0){
                    dp[j] = 0;
                }else if(j == 0){
                    /*
                    word1: [0, i-1] //i 's upper limit is m
                    word2: ""
                    
                    this means we need to delete i char from word1
                    */
                    dp[j] = i;
                }else if(i == 0){
                    /*
                    word1: ""
                    word2: [0, j-1] //j 's upper limit is n
                    */
                    dp[j] = j;
                }else if(word1[i-1] == word2[j-1]){
                    //no op
                    dp[j] = dp_is1_js1;
                }else{
                    dp[j] = min({
                        //remove word1[i-1]
                        //dp[i-1][j]
                        dp[j],
                        //insert word2[j-1]
                        //dp[i][j-1]
                        dp[j-1],
                        //replace word1[i-1] to word2[j-1]
                        //dp[i-1][j-1]
                        dp_is1_js1
                        }) + 1;
                }
                dp_is1_js1 = tmp;
            }
        }
        
        return dp[n];
    }
};
