class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	int m = board.size();
    	if(m == 0)
    		return;

    	int n = board[0].size();
    	vector<pair<int, int>> v;
    	vector<vector<bool>> visit(m+2, vector<bool>(n+2, false));

    	for(int i = 1; i <= m; i++){
    		if(board[i-1][0] == 'O'){
    			v.push_back(pair<int,int>(i, 1));
    			visit[i][1] = true;
    		}
    		
    		if(board[i-1][n-1] == 'O'){
    			v.push_back(pair<int,int>(i, n));
    			visit[i][n] = true;
    		}
    		
    	}
    	for(int j = 2; j <= n-1; j++){
    		if(board[0][j-1] == 'O'){
    			v.push_back(pair<int,int>(1, j));
    			visit[1][j] = true;
    		}
    		
    		if(board[m-1][j-1] == 'O'){
    			v.push_back(pair<int,int>(m, j)); 
    			visit[m][j] = true;  		
    		}
    	}

    	for(int i = 0; i < v.size(); i++){ 
    		pair<int,int> temp = v[i];
    		int k = temp.first;
    		int j = temp.second;

    		if(visit[k-1][j] == false && k > 1 && board[k-2][j-1] == 'O'){
    			visit[k-1][j] == true;
    			v.push_back(pair<int, int>(k-1, j));
    		}

    		if(visit[k+1][j] == false && k < m && board[k][j-1] == 'O'){
    			visit[k+1][j] = true;
    			v.push_back(pair<int, int>(k+1, j));
    		}

    		if(visit[k][j-1] == false && j > 1 && board[k-1][j-2] == 'O'){
    			visit[k][j-1] = true;
    			v.push_back(pair<int, int>(k, j-1));
    		}

    		if(visit[k][j+1] == false && j < n && board[k-1][j] == 'O'){
    			visit[k][j+1] = true;
    			v.push_back(pair<int, int>(k, j+1));
    		}
    	}

    	for(int i = 0; i < m; i++)
    		for(int j = 0; j < n; j++){
    			board[i][j] = 'X'; 
    		}

    	for(int i = 0; i < v.size(); i++){
    		pair<int, int> temp = v[i];
    		int j = temp.first;
    		int k = temp.second;

    		board[j-1][k-1] ='O';
    	}

    	return;
        
    }
};