class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //directed graph
        //find a node whose in-degree is N-1 and out-degree is 0
        
        vector<int> in(N), out(N);
        
        for(vector<int> edge : trust){
            //1-based -> 0-based
            int from = edge[0]-1, to = edge[1]-1;
            out[from]++;
            in[to]++;
        }
        
        for(int i = 0; i < N; i++){
            if(in[i] == N-1 && out[i] == 0){
                //0-based -> 1-based
                return i+1;
            }
        }
        
        return -1;
    }
};
