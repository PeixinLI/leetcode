class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	if(n == 0 || n == 1)
    		return ;

    	for(int i = 0; i < n; i ++){
    		for(int j = i; j < n-i-1; j++){
    			int temp = matrix[i][j];
    			matrix[i][j] = matrix[n-j-1][i];
    			matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
    			matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
    			matrix[j][n-i-1] = temp; 
    		}
    	}
        
    }
};