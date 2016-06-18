class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row , col;
        row = matrix.size();
        if(row == 0) return 0;
        col = matrix[0].size();
        
        int Max_Squ[row][col];
        
        for(int i = 0; i < row; i++ )
            for(int j = 0; j < col; j++)
                Max_Squ[i][j] = 0;
        
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == '1') Max_Squ[i][0] = 1;
        
        for(int j = 0; j < col; j++)
            if(matrix[0][j] == '1') Max_Squ[0][j] = 1;
        

        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++){
                
                if(matrix[i][j] == '0'){
                    Max_Squ[i][j] = 0;
                    continue;
                }
                int temp = Max_Squ[i-1][j-1];
                if(Max_Squ[i-1][j] < temp) temp = Max_Squ[i-1][j];
                if(Max_Squ[i][j-1] < temp) temp = Max_Squ[i][j-1];
                Max_Squ[i][j] = temp + 1;
            }
        
        int max = 0;
        for(int i = 0; i < row; i++ )
            for(int j = 0; j < col; j++)
                if(Max_Squ[i][j] > max)
                    max = Max_Squ[i][j];
        
        return max*max;
         
    }
};