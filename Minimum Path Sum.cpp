class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0) return 0;
        vector<vector<int>> path(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++)
            path[i][0] = grid[i][0];
        
        for(int j = 0; j < col; j++)
            path[0][j] = gird[0][j];
        
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
        
        return path[row-1][col-1]
        
        
    }
};