class Solution {
public:
	bool row[9][9];
	bool col[9][9];
	bool blk[9][9];
    void solveSudoku(vector<vector<char>>& board) {
    	memset(row, false, sizeof(row));
    	memset(col, false, sizeof(col));
    	memset(blk, false, sizeof(blk));

    	for(int i = 0; i < 9; i++)
    		for (int j = 0; j < 9; j++)
    		{
    			if(board[i][j] != '.'){
    				int val = board[i][j] - '0';
    				row[i][val] = true;
    				col[j][val] = true;
    				int t = (i/3) * 3 + (j/3);
    				blk[t][val] = true;
    			}
    		} 

    	cout << findSolution(board) <<endl;

    	return;   
    }

    bool findSolution(vector<vector<char>> & board){
    	int r = -1;
    	int c = -1;
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j < 9; j++){
    			if(board[i][j] == '.'){
    				r = i;
    				c = j;
    				// cout << i << j<< endl;
    				break;
    			}
    		}
    		if(r != -1 && c != -1)
    			break;
    	}
    	if(r == -1 && c == -1){
    		return true;
    	}

    	int t = (r/3) * 3 + (c/3);

    	for(int val = 1; val <= 9; val++){
    		if(!row[r][val] && !col[c][val] && !blk[t][val]){
    			row[r][val] = true;
    			col[c][val] = true;
    			blk[t][val] = true;
    			board[r][c] = '0' + val;
    			if(findSolution(board));
    				return true;
    			board[r][c] = '.';
    			row[r][val] = false;
    			col[c][val] = false;
    			blk[t][val] = false;

     		}
    	}

    	return false;
    }
};