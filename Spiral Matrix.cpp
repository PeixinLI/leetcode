class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();

        int j = 0;
        while(j < m && j < n){
            cout << m <<" "<<n<<endl;
        	for(int i = j; i < n ; i++) 
        		res.push_back(matrix[j][i]);

        	for(int i = j+1; i < m; i++)
        		res.push_back(matrix[i][n-1]);
        	
        	if(n-1 > j && m-1 >j){
        	    for(int i = n-2; i >= j; i-- )
        	    	res.push_back(matrix[m-1][i]);

        	    for(int i = m-2; i > j; i--)
        	    	res.push_back(matrix[i][j]);
        	}
        	

        	m --;
        	n --;
        	j ++;
        }

        return res;
    }
};