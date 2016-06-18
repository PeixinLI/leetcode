class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(row == 0) return false;
        int col = board[0].size();
        vector<vector<int>> used(row, vector<int>(col,0));
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(findword(board,used,word,i,j,0))
                    return true;
            }
        
        return false;
    }
    
    bool findword(vector<vector<char>>& board, vector<vector<int>>& used, string& word, int i, int j, int pos){
        if( i < 0 || j < 0 || i >= board.size()
           || j >= board[0].size() || word[pos] != board[i][j] || used[i][j])
            return false;
        if(pos == word.size() -1)
            return true;
        
        used[i][j] = 1;
        if(findword(board, used, word, i+1, j, pos+1) ||
           findword(board, used, word, i, j+1, pos+1) ||
           findword(board, used, word, i-1, j, pos+1) ||
           findword(board, used, word, i, j-1, pos+1)){
           // used[i][j] = 0; this line is necessary when we are not finding one solution
            return true;
        }
        used[i][j] = 0;
        
        return false;
    }
};