class Solution {
public:
   int orangesRotting(vector<vector<int>> &grid) {
      int minutes = 0;
      int rowMax = grid.size();
      int colMax = grid[0].size();
      bool freshLeft = false;
      auto newGrid = grid;
      while (true) {
         newGrid = grid;
         bool flag = false;
         freshLeft = false;
         for (int i = 0; i < rowMax; i++) {
            for (int j = 0; j < colMax; j++) {
               if (newGrid[i][j] == 1) {
                  if ((i - 1 >= 0 && newGrid[i - 1][j] == 2) or (i + 1 < rowMax && newGrid[i + 1][j] == 2) or (j - 1 >= 0 && newGrid[i][j - 1] == 2) or (j + 1 < colMax && newGrid[i][j + 1] == 2)) {
                     grid[i][j] = 2;
                     flag = true;
                  }
                  freshLeft = true;
               }
            }
         }
         if (flag)
            minutes++;
         else
            break;
      }
      return (freshLeft != true) ? minutes : -1;
   }
};