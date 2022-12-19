class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int allsum = accumulate(nums.begin(), nums.end(), 0);
        int cumsum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(cumsum*2 == (allsum-nums[i])){
                return i;
            }
            cumsum += nums[i];
        }
        
        return -1;
    }
};
