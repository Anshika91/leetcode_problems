class Solution {
public:
    enum Index{
        GOOD, BAD, UNKNOWN
    };
    
    vector<Index> reach;
    vector<bool> visited;
    
    bool canReachRecursive(vector<int>& arr, int start) {
        //avoid fall into a loop in the graph
        if(visited[start]){
            reach[start] = Index::BAD;
            return reach[start];
        }
        visited[start] = true;
        
        if(reach[start] == Index::GOOD || reach[start] == Index::BAD){
            return reach[start];
        }
        
        //jump right
        if(start + arr[start] < arr.size()){
            if(canReachRecursive(arr, start + arr[start]) == Index::GOOD){
                reach[start] = Index::GOOD;
                return reach[start];
            }
        }
        
        //jump left
        if(start - arr[start] >= 0){    
            if(canReachRecursive(arr, start - arr[start]) == Index::GOOD){
                reach[start] = Index::GOOD;
                return reach[start];
            }
        }
        
        //cannot reach 0
        reach[start] = Index::BAD;
        // cout << endl;
        
        return reach[start];
    }
    
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        
        reach = vector<Index>(N, Index::UNKNOWN);
        visited = vector<bool>(N, false);
        
        for(int i = 0; i < N; i++){
            if(arr[i] == 0)
                reach[i] = Index::GOOD;
        }
        
        return canReachRecursive(arr, start) == Index::GOOD;
    }
};
