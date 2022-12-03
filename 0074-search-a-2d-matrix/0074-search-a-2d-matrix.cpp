class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        
        int l = 0, r = m*n-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }else if(matrix[mid/n][mid%n] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        
        return false;
    }
};