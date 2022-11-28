class NumArray {
public:
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        int ans = 0;
        for(int pos = i; pos <= j; pos++){
            ans += nums[pos];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */