class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        //padding ahead
        vector<int> count(amount+1, INT_MAX);
        
        //base case
        for(int coin : coins){
            //to ensure it won't exceed the array's size
            if(coin <= amount) count[coin] = 1;
        }
        
        // for(int i = 1; i <= amount; i++){
        //     cout << i << ", " << count[i] << " | ";
        // }
        // cout << endl;
        
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i < coin) continue;
                if(count[i-coin] == INT_MAX) continue;
                count[i] = min(count[i], count[i-coin]+1);
            }
            // cout << i << ", " << count[i] << endl;
        }
        // cout << "===========" << endl;
        
        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};
