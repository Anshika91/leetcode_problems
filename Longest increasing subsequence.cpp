class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int prev = -1, int cur = 0) {
        /*
        nums[cur] is the element we consider to append,
        it cannot be out of the range of nums
        */
        if(cur == nums.size()) return 0;
        int taken = 0;
        //we may append current element into sequence, take
        /*
        initial state: prev is -1, and cur = 0,
        that means we are considering the 0th element,
        and the 0th element is always ok to be appended to the empty sequence
        */
        if(prev < 0 || nums[cur] > nums[prev]){
            taken = 1 + lengthOfLIS(nums, cur, cur+1);
        }
        //skip current element, not take
        int nottaken = lengthOfLIS(nums, prev, cur+1);
        // cout << prev << ", " << cur << " : " << taken << ", " << nottaken << endl;
        return max(taken, nottaken);
    }
};
