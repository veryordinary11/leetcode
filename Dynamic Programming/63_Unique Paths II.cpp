class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int vol = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(vol));
        if(obstacleGrid[0][0] == 1) return 0;
        int flag1 = 0;
        int flag2 = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < vol; j++){
                if(((i == 0 && flag1 == 0) || (j == 0 && flag2 == 0)) && obstacleGrid[i][j] != 1 )    dp[i][j] = 1;
                else if((i == 0 || j == 0) && obstacleGrid[i][j] == 1){
                    if(i == 0){
                        flag1 == 1;
                        for(int k1 = j; k1 < vol; k1++)    dp[0][k1] = 0;
                    }
                    else{
                        flag2 == 1;
                        for(int k2 = i; k2 < row; k2++)     dp[k2][0] = 0;
                    }
                }
                else if(obstacleGrid[i][j] == 1)    dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][vol-1];
    }
};
