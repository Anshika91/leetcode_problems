class Solution {
public:
    vector<int> money;
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        
        int N = nums.size();
        money = nums;
        //so that we can access money[N]
        money.push_back(0);
        for(int i = N-3; i >= 0; i--){
            money[i] += max(money[i+2], money[i+3]);
        }
        return max(money[0], money[1]);
    }
};
