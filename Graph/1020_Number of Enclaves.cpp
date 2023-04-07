class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && grid[i][j] == 1){
                    dfs(grid, i, j);
                }
            }
        }
        return accumulate(begin(grid), end(grid), 0, [](int sum, auto row) { return sum + accumulate(begin(row), end(row), 0); });
    }

    void dfs(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        vector<vector<int>> directions{{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto direction : directions){
            int r = x + direction[0];
            int c = y + direction[1];
            if(r >= 0 && r < grid.size() && c >=0 && c < grid[0].size() && grid[r][c] == 1){
                dfs(grid, r, c);
            }
        }
    }
};
