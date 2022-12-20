class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        dfs(result, nums, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int> nums, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
        } else {
            for(int i = start; i < nums.size(); i++) {
                if(i!=start and nums[i]==nums[start]) continue;
                swap(nums[i], nums[start]);
                dfs(result, nums, start+1);
            }
        }
    }
};
