class NumMatrix {
public:
    vector<vector<int>> sums2d;
    
    NumMatrix(vector<vector<int>> &matrix) {
        int r = matrix.size();
        if(r == 0) return;
        int c = matrix[0].size();
        sums2d.resize(r + 1, vector<int>(c+1));
        for(int i = 0; i <= r; i++) sums2d[i][0] = 0;
        for(int j = 0; j <= c; j++) sums2d[0][j] = 0;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                sums2d[i][j] = sums2d[i-1][j] + sums2d[i][j-1] - sums2d[i-1][j-1] + matrix[i-1][j-1];
        
        return;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums2d[row2+1][col2+1]  - sums2d[row1][col2+1] - sums2d[row2+1][col1] +  sums2d[row1][col1 ];
        
    }
};



// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);