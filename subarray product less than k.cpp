class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.size() <= 0 || k <= 0) return 0;
        int i=0,j=1, res = 0;
        // 先给product搞个默认值
        int product = nums[i];
        if (product < k) res=1;
        while (j < nums.size()) {
            product *= nums[j];
            if (product >= k) {
                // 这里为什么要用个while循环走你呢？因为这时候窗口左边可能已经是很小的数，比如1，1，2这种，product / 窗口左边 不见得会小于 k，所以需要一个while循环
                while (i<j && product >= k) {
                    product /= nums[i++];
                }    
            }
            res += j-i;
            res += nums[j] < k ? 1 : 0; // 这里主要判断当前数是不是小于k
            j++;
        }
        return res;
    }
};
