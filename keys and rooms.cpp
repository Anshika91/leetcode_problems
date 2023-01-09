class Solution {
public:
    
    void openRooms(vector<vector<int>>& rooms, int i, vector<bool>& opened) {
        if (opened[i]) return;
        opened[i] = true;
        for (int& n : rooms[i]) {
            openRooms(rooms, n, opened);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> opened(n, false);
        openRooms(rooms, 0, opened);
        for (bool val : opened) {
            if (!val) return false;
        }
        return true;
    }
};
