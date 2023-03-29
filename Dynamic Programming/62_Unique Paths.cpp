class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(row == 0 || col == 0)    grid[row][col] = 1;
                else    grid[row][col] = grid[row-1][col] + grid[row][col-1];
            }
        }
        return grid[m-1][n-1];
    }
};
