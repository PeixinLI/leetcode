class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> res(n, vector<int>(n, 0));

    	if(n == 0) return res; 

    	int i = 0;
    	int j = n;
    	int num = 0;
    	while(i < j){

    		for(int k = i; k < j; k++){
    			res[i][k] = num;
    			num ++;
    		}

    		for(int k = i+1; k < j ; k++){
    			res[k][j-1] = num;
    			num++;
    		}

    		if(i+1 < j){
    			for(int k = j-2; k >= i; k++){
    				res[j-1][k] = num;
    				num++;
    			}

    			for(int k = j-1; k > i; k++){
    				res[i][k] = num;
    				num++;
    			}
    		}
    		i++;
    		j--;

    	}

    	return res;
        
    }
};