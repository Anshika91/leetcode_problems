
class Solution {
public:
    int DIR[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 ||i ==n-1 || j==m-1){
                    dfs(grid,i,j);
                }
            }
        }
            int ans=0;
             for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                    dfs(grid,i,j);
                   ans++;
               }
            }
        }
            return ans;
    }
    
    void dfs(vector<vector<int>>& grid,int r,int c){
        
         if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==1)return ;
        grid[r][c]=1;
        for(auto & d:DIR){
            int nr= r+d[0];
            int nc=c+d[1];
            dfs(grid,nr,nc);
        }
    }
};
