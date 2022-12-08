class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = -1, sum = 0, min_size = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_size = min(min_size, i - start);
                sum -= nums[++start];
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};
