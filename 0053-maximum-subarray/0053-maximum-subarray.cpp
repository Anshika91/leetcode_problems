class Solution {
public:
    int maxNegative(vector<int>& nums) {
        int maxNegative = nums[0];
        for(int e : nums){
            //if there are non-negative numbers in nums,
            // return 0
            if(e >= 0) return 0;
            maxNegative = max(maxNegative, e);
        }
        return maxNegative;
    }
    
    int maxSubArray(vector<int>& nums) {
        int mn = maxNegative(nums);
        if(mn < 0) return mn;
        
        int sum = 0, largest = nums[0];
        for(int e : nums){
            sum += e;
            //restart(zero the sum) if it's negative
            sum = max(sum, 0);
            largest = max(largest, sum);
        }
        
        return largest;
    }
};