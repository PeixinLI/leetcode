class Solution {
public:
	vector<vector<string>> res;
	vector<string> oneres;
    vector<vector<string>> solveNQueens(int n) {
    	vector<bool> col(n, false);
    	vector<bool> sum(2*n-1, false);
    	vector<bool> dif(2*n-1, false);
        findSolution(0, n, col, sum, dif);
        return res;
    }

    void findSolution(int i, int n, vector<bool>& col, vector<bool>& sum, vector<bool>& dif){
    	if(i == n){
    		res.push_back(oneres);
    		return;
    	}
    	for(int j = 0; j < n; j++){
    		if(col[j] == false && sum[i+j] == false && dif[i-j+n-1] == false){
    			col[j] = true;
    			sum[i+j] = true;
    			dif[i-j+n-1] = true;
    			string s = "";
    			for(int k = 0; k < n; k++){
    				if(k == j)
    					s += "Q";
    				else
    					s += ".";
    			}
    			oneres.push_back(s);
    			findSolution(i+1, n, col, sum, dif);
    			oneres.pop_back();
    			col[j] = false;
    			sum[i+j] = false;
    			dif[i-j+n-1] = false;
    		}

    	}
    	return;
    }
};