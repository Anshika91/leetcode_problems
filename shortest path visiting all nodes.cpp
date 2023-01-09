
struct State{
    int cur;
    int visit;
    int step;
    
    State(int cur,int visit,int step):cur(cur),visit(visit),step(step){}
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        int ans = 0;
        queue<State> q;
        vector<vector<bool>> visited(1<<N,vector<bool>(N,false)); //visit下，停在某个节点的情况是否被计算过
        for(int i=0;i<N;i++){
            q.push(State(i,1<<i,0));  //用0-1 bit表示是否访问过
            visited[1<<i][i] = true;
        }
        
        while(!q.empty()){
            State tmp = q.front();
            q.pop();
            
            if(tmp.visit == (1<<N)-1){ //说明所有节点已经全部访问过
                ans = tmp.step;  //可以直接返回，因为这是bfs，确保了当前是最短的路径
                break;
            }
            
            for(int node : graph[tmp.cur]){
                int tmp_state = tmp.visit|(1<<node); //加上对应node的状态
                if(!visited[tmp_state][node]){
                    q.push(State(node,tmp_state,tmp.step+1));
                    visited[tmp_state][node] = true;
                }
            }
            
        }
        
        return ans;
    }
};
