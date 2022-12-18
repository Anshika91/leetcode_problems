class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        for(int i = 0; i < T.size(); i++){
            bool found = false;
            for(int j = i+1; j < T.size(); j++){
                if(T[j] > T[i]){
                    ans.push_back(j-i); 
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(0);
        }
        return ans;
    }
};
