//Using DFS to find the island
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int num = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0 ; i < row; i++)
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                   // DFSgrid(grid, i, j);
                    num ++;
                }
            }
        return num;
    }
    
    void DFSgrid (vector<vector<int>>& grid, int i, int j){ // use * to represent that land ij is visited
        if(i < 0 || i > grid.size() || j < 0 || j > grid[0].size())
            return;
        
        grid[i][j] = '*';
        DFSgrid(grid, i+1, j);
        DFSgrid(grid, i, j+1);
        DFSgrid(grid, i-1, j);
        DFSgrid(grid, i, j-1);
        return;
    }
};