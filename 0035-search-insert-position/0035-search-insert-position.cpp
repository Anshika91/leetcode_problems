class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //find the first number larger than target
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= target) return i;
        }
        //if target is the largest
        return nums.size();
    }
};