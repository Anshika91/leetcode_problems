class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int start){
        ans.push_back(subset);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            backtrack(ans, subset, nums, i+1);
            subset.pop_back();
        }
    };
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        //sorting here is important!
        sort(nums.begin(), nums.end());
        backtrack(ans, cur, nums, 0);
        
        return ans;
    }
};
