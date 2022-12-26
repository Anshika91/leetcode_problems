class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        
        int row = 0, col = n-1;
        while(col >= 0 && row < m){
            if(matrix[row][col] == target){
                return true;
            }else if(target < matrix[row][col]){
                //the current column's value are all larger than target
                col--;
            }else{
                //the current row's value are all smaller than target
                row++;
            }
        }
        
        return false;
    }
};
