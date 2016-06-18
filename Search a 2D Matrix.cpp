class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        int begin = 0, end = row*col -1;
        while(begin <= end){

            mid = (begin + end)/2;
            if(target > matrix[mid/col][mid%col])
                begin = mid + 1;
            else if(target < matrix[mid/col][mid%col])
                end = mid - 1;
            else
                return true;
            
        }
        
        return false;
        
    }
    
};