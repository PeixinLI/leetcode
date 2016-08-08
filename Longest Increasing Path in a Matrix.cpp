class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	int row = matrix.size();
    	if(row == 0)
    		return 0;
    	int col = matrix[0].size();

    	vector<vector<int>> path(row, vector<int>(col, -1));

    	int maxlen = 0;
    	for(int i = 0; i < row; i++)
    		for(int j = 0; j < col; j++){
    			int val = dfs(path, matrix, i, j, row, col);
    			
    			maxlen = max(maxlen, val);
    		}

    	return maxlen;

    }

    int dfs(vector<vector<int>>& path, vector<vector<int>>& matrix, int i , int j, int row, int col){
    	
    	if(path[i][j] == -1){
    		path[i][j] = 1;
    		if(i > 0){
    			if(matrix[i][j] > matrix[i-1][j]){
    				path[i][j] = max(path[i][j], dfs(path, matrix, i-1, j, row, col) + 1);
    			} 
    		}
    		if(j > 0 ){
    			if(matrix[i][j] > matrix[i][j-1]){
    				path[i][j] = max(path[i][j], dfs(path, matrix, i, j-1, row, col) + 1);
    			} 
    		}
    		if(i < row - 1 ){
    			if(matrix[i][j] > matrix[i+1][j]){
    				path[i][j] = max(path[i][j], dfs(path, matrix, i+1, j, row, col) + 1);
    			} 
    		}
    		if(j < col -1){
    			if(matrix[i][j] > matrix[i][j+1]){
    				path[i][j] = max(path[i][j], dfs(path, matrix, i, j+1, row, col) + 1);
    			} 
    		}  		

    	}
    // 	cout << i <<" "<< j<<" "<<path[i][j]<<endl; 

    	return path[i][j];
    }
};