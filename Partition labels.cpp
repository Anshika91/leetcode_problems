class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for (int i = 0; i < S.length(); ++i)
            last[S[i] - 'a'] = i;
        
        int j = 0, anchor = 0;
        vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            j = max(j, last[S[i] - 'a']); //push the boundary of this segment to the right
            if (i == j) { //if we are now at the supposed boundary of this segment, split here
                ans.push_back(i - anchor + 1);
                anchor = i + 1; //start from here next time
            }
        }
        return ans;
    }
};
