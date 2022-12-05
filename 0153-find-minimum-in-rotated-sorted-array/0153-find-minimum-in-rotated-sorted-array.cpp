class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int mid;
        /*
        choose nums[0] as pivot, 
        so we don't need to put nums[0] in the search range
        */
        int ans = nums[0];
        int l = 1, r = n-1;
        
        while(l <= r){
            mid = (l+r) >> 1;
            // cout << mid << endl;
            
            if(nums[mid] < nums[0]){
                ans = min(ans, nums[mid]);
                r = mid-1;
            }else{
                //nums[mid] > nums[0]
                l = mid+1;
            }
        }
        
        return ans;
    }
};