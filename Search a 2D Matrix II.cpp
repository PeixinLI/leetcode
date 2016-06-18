/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    }
    bool divide_search(vector<vector<int>>& matrix, int target, int row1, int col1, int row2, int col2){
        if(row2 < row1 || col2 < col1) return false;
        if(row2 == row1 && col2 == col1)
            return (matrix[row1][col1] == target);
        int row = (row1 + row2)/2;
        int col = (col1 + col2)/2;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target){
            if(divide_search(matrix, target, row+1, col+1, row2, col2)) return true;
            else if(divide_search(matrix, target, row1, col1))
        }
    
    }
    
            
};*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while(i >= 0 && i < m && j >= 0 && j < n){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) i --;
            else j++;

        }
        return false;
    }
};

// start from the lower left corner( or upper right corner) if target is larger than the cur_num then go left else go upper