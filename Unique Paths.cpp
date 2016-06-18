class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pos(m*n);
        for(int i = 0; i < n ; i++)
            pos[i*m] = 1;
        for(int j = 0; j < m ; j++)
            pos[j] = 1;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++ )
                pos[i*m +j] = pos[(i-1)*m + j] + pos[i*m + j -1];
        
        return pos[m*n -1];
        
    }
    
};