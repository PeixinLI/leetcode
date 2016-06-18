class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n,0));
        if(obstacleGrid[0][0] == 0) path[0][0] = 1;
        for(int i = 1; i < m; i++)
            if(obstacleGrid[i][0] == 0 && path[i-1][0]) path[i][0] = 1;
        
        
        for(int j = 1; j < m ; j++)
            if(obstacleGrid[0][j] == 0 && path[0][j-1]) path[0][j] = 1;

        

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++ ){
                if(!obstacleGrid[i][j]){
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        
        
        return pos[m-1][n-1];
        
    }
};