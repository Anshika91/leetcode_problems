class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int start){
        ans.push_back(subset);
        for(int i = start; i < nums.size(); i++){
            subset.push_back(nums[i]);
            backtrack(ans, subset, nums, i+1);
            subset.pop_back();
        }
    };
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        backtrack(ans, subset, nums, 0);
        
        return ans;
    }
};
