class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
    	vector<vector<bool>> *row;
    	vector<vector<bool>> *col;
    	vector<vector<bool>> *subbox;
        row = new vector< vector<bool>>(9,vector<bool>(9,false));
        col = new vector< vector<bool>>(9,vector<bool>(9,false));
        subbox = new vector< vector<bool>>(9,vector<bool>(9,false));
    	for(int i = 0; i < 9; i ++) // row 
    		for(int j = 0; j < 9; j++){ // col

    			if(board[i][j] == '.') continue;
    			
    			int num = board[i][j] - '0';

    			int k = (j/3)*3 + i/3;

    			if( (*row)[i][num] || (*col)[j][num] || (*subbox)[k][num])
    				return false;

    			(*row)[i][num] = true;
    			(*col)[j][num] = true;
    			(*subbox)[k][num] = true;
    		}
        
        return true;
    }
};