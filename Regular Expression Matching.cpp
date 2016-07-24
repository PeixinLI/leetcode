class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> match(m+1, vector<bool>(n+1, false));

        // empty matches empty 
        match[0][0] = true;

        // if p is empty but s isn't empty then match[i][j] is false
        for(int i = 1; i <= m; i++)
            match[i][0] = false;

        // if s is empty but p isn't: x* matches empty
        for(int j = 2; j <= n; j++)
            match[0][j] = (p[j-1] == '*' && match[0][j-2]);

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*'){
                    // p[j-2] repeat 0 times or 
                    match[i][j] = match[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && match[i-1][j] ;
                }
                else{
                    match[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && match[i-1][j-1] ;
                }
            }
        }
        return match[m][n];
    }

};

// State Machine