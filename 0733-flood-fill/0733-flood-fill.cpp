class Solution {
public:
    void dfs(vector<vector<int>>& image, int initial, int i, int j, int color){
        int n= image.size(); int m= image[0].size();
        if (i<0 || j<0 || i>=n || j>=m)return;
        if (image[i][j]!=initial || image[i][j]==color)return;
        image[i][j]= color;
        dfs(image,initial,i-1,j,color);
        dfs(image,initial,i+1,j,color);
        dfs(image,initial,i,j-1,color);
        dfs(image,initial,i,j+1,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,image[sr][sc],sr,sc,color);
        return image;
    }
};