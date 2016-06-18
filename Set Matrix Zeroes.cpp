
//space O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size()
        vector<int> row_zero(row, 1);
        vector<int> col_zero(col, 1);
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == 0){
                    row_zero[i] = 0;
                    col_zero[j] = 0;
                }
        for(int i = 0; i < row; i++){
            if(row_zero [i] == 0)
                for(int j = 0; j < col; j++)
                    matrix[i][j] = 0;
        }
        for(int j = 0; j < col; j++){
            if(col_zero [j] == 0)
                for(int i = 0; i < row; i++)
                    matrix[i][j] = 0;
        }
        
        return ;
    }
};

//also can do in O(n) very simple;
