class Solution {
public:
    
    int n = 0;
    Node *one, *zero;
    
    Node* dfs(vector<vector<int>>& a, int l, int x, int y) {
        if (l==1) {
            return a[x][y] ? one : zero;
        } else {
            int lt = l>>1;
            auto* now = new Node(true, false, dfs(a, lt, x, y), dfs(a, lt, x, y+lt), dfs(a, lt, x+lt, y), dfs(a, lt, x+lt, y+lt));
            if (now->topLeft==now->topRight && now->topLeft==now->bottomLeft && now->topLeft==now->bottomRight) 
                return now->topLeft;
            else 
                return now;
        }
    }
    
    Node* construct(vector<vector<int>>& a) {
        one = new Node(true, true, NULL, NULL, NULL, NULL);
        zero = new Node(false, true, NULL, NULL, NULL, NULL);
        n = a.size();
        return dfs(a, n, 0, 0);
    }
};
