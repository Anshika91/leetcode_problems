class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int e1 : arr1){
            auto it = find_if(arr2.begin(), arr2.end(), 
                             [&e1, &d](int e2){
                                 return abs(e1 - e2) <= d;
                             });
            
            if(it == arr2.end()){
                ans++;
            }
        }
            
        return ans;
    }
};