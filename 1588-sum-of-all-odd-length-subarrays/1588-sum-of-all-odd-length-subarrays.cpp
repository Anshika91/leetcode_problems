class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        
        for(int len = 1; len <= n; len += 2){
            for(int start = 0; start+len-1 < n; ++start){
                ans += accumulate(arr.begin()+start, arr.begin()+start+len, 0);
            }
        }
        
        return ans;
    }
};
