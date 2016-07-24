class Solution {
public:
    int numDistinct(string s, string t) {
      int size1 = s.size();
      int size2 = t.size();

      if(size1 == 0 && size2 == 0)
      return 0;

      vector<vector<int>> M (size1+1, vector<int>(size2+1, 0));
      M[0][0] = 1;
      for(int i = 1; i <=size1 ; i++){
        M[i][0] = 1;  // if string t is an empty string then t is 1 subsequence of s
        for(int j = 1; j <=size2; j++){
          M[i][j] = M[i-1][j];
          if(s[i-1] == t[j-1])
            M[i][j] += M[i-1][j-1];
        }
      }

      return M[size1][size2];
    }
};
