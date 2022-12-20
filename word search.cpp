class Solution {
private:
    int m, n;
    bool search_at(vector<vector<char>>& board, const string word, int char_idx, int x, int y){
        char curr = board[x][y];
        bool result = false;
        if (curr != word[char_idx]) return result;
        if (word.size() == char_idx+1) return true;
        
        board[x][y] = '-';
        if (x>0 && search_at(board, word, char_idx+1, x-1, y))  result = true;
        if (!result && y>0 && search_at(board, word, char_idx+1, x, y-1))  result = true;
        if (!result && y<n-1 && search_at(board, word, char_idx+1, x, y+1))  result = true;
        if (!result && x<m-1 && search_at(board, word, char_idx+1, x+1, y))  result = true;
        
        board[x][y] = curr;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        if (word.size() > m * n) return false;
        
        for (int idx1 = 0; idx1 < m; idx1++){
            for (int idx2 = 0; idx2 < n; idx2++){
                if (search_at(board, word, 0, idx1, idx2)) return true;
            }
        }
        return false;
    }
};
