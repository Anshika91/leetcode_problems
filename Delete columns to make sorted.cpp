class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int c = 0;
        bool ans = true;
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(strs[j][i] < strs[j-1][i])
                {
                    c++;
                    break;
                }
            }
            
        }
        return c;
    }
};
